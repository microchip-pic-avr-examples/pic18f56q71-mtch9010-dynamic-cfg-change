 /*
 * MTCH9010 File
 * 
 * @file mtch9010.c
 * 
 * @defgroup mtch9010
 *
 * @brief This file contains the functions used to configure MTCH9010 in Enhanced Configuration Mode.
*/

/*
© [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/


#include "mtch9010.h"
#include "mcc_generated_files/system/system.h"

void MTCH9010_Init_Pins(void)
{
    RESET_SetHigh(); // RESET: OFF
    CFG_EN_SetHigh(); // CFG Mode: OFF
    SYS_LK_SetLow(); // SYS Lock: ON
}

void MTCH9010_Receive_Firmare_Version(char *firmwareVersion)
{
    uint8_t receivedData;
    uint8_t indexData = 0;
    
    do
    {
        while(!UART1_IsRxReady());
        receivedData = UART1_Read();
        if(receivedData != ENTER_KEY)
        {
            firmwareVersion[indexData++] = receivedData;
        }  
    } while(receivedData != ENTER_KEY);
}

uint8_t MTCH9010_Receive_ACK_NAK(void)
{
    uint8_t command = 0;
    uint8_t receivedData;
    
    do
    {
        while(!UART1_IsRxReady());
        receivedData = UART1_Read();
        if(receivedData != ENTER_KEY && (receivedData == ACK || receivedData == NAK))
        {
            command = receivedData;
        }  
    } while(receivedData != ENTER_KEY);
        
    return command;
}

uint16_t MTCH9010_Receive_Data(void)
{
    uint16_t command = 0;
    uint8_t receivedData;
    
    do
    {
        while(!UART1_IsRxReady());
        receivedData = UART1_Read();
        if(receivedData != ENTER_KEY && receivedData >= '0' && receivedData <= '9')
        {
            command = command * 10 + (receivedData - '0');
        }  
    } while(receivedData != ENTER_KEY);
        
    return command; 
}

void MTCH9010_Send_Command(uint16_t command)
{
    uint16_t p = 1;
    uint16_t tempCommand = command;
    
    while(tempCommand > 9)
    {
        p *= 10;
        tempCommand /= 10;
    }
    
    while(p > 0)
    {
        uint8_t c = (uint8_t)(command / p) + '0';
        UART1_Write(c);
        command = command % p;
        p /= 10;
        while(!UART1_IsTxDone());  
    }
    
    UART1_Write(ENTER_KEY);
    while(!UART1_IsTxDone());
}

mtch9010_config_status_t MTCH9010_Config(mtch9010_config_t configData)
{
    char firmwareVersion[20];
    uint8_t repeatCommand;
    uint16_t receivedData;
            
    // Configure CFG_EN pin to enter Enhanged Configuration Mode after reset
    CFG_EN_SetLow(); // CFG Mode: ON
    SYS_LK_SetHigh(); // SYS LOCK: OFF
    UART_EN_SetLow(); // Enable UART
                    
    // Reset MTCH9010
    RESET_SetLow();
    __delay_ms(10);
    RESET_SetHigh();
            
    // Read firmware version
    MTCH9010_Receive_Firmare_Version(firmwareVersion);
    
    // Send Operation mode
    repeatCommand = 0;
    do
    {
        if(++repeatCommand == (MAX_COMMAND_REPEAT + 1)) {
            return OP_MODE_ERROR;
        }
        
        MTCH9010_Send_Command(configData.op_mode);
    } while(MTCH9010_Receive_ACK_NAK() != ACK);
       
    // Send Sleep time
    repeatCommand = 0;
    do
    {
        if(++repeatCommand == (MAX_COMMAND_REPEAT + 1)) {
            return SLEEP_TIME_ERROR;
        }
        
        MTCH9010_Send_Command(configData.sleep_time);
    } while(MTCH9010_Receive_ACK_NAK() != ACK);
    
    // Send Extended Output Mode
    repeatCommand = 0;
    do
    {
        if(++repeatCommand == (MAX_COMMAND_REPEAT + 1)) {
            return EXTENDED_OUTPUT_MODE_ERROR;
        }
        
        MTCH9010_Send_Command(configData.extended_output_mode);
    } while(MTCH9010_Receive_ACK_NAK() != ACK);
    
    // Check if the Extended Output Mode is enabled and send the chosen format if needed
    if(configData.extended_output_mode == MTCH9010_EXTENDED_OUTPUT_ENABLE)
    {
        repeatCommand = 0;
        do
        {
            if(++repeatCommand == (MAX_COMMAND_REPEAT + 1)) {
                return EXTENDED_OUTPUT_FORMAT_ERROR;
            }
            
            MTCH9010_Send_Command(configData.extended_output_format);
        } while(MTCH9010_Receive_ACK_NAK() != ACK);
    }
    
    // Wait for Reference value measurement
    receivedData = MTCH9010_Receive_Data(); 
    
    // Send the option for Reference value
    repeatCommand = 0;
    do
    {
        if(++repeatCommand == (MAX_COMMAND_REPEAT + 1)) {
            return REFERENCE_VALUE_ERROR;
        }
        
        MTCH9010_Send_Command(configData.reference_value);
    } while(MTCH9010_Receive_ACK_NAK() != ACK);
    
    // Verify if another commands should be transmitted based on the Reference value option
    if(configData.reference_value == MTCH9010_REF_VALUE_STANDARD)
    {
        // The current capacitive/conductive measurement was validated as Reference Value by the last command
        ;
    }
    else if(configData.reference_value == MTCH9010_REF_VALUE_REPEAT)
    {
        // Wait for the new capacitive/conductive measurement
        receivedData = MTCH9010_Receive_Data();
    
        // Confirm the new capacitive/conductive measurement as Reference Value
        // For this simple implementation the measurement is repeat once and then the value is validated
        // MTCH9010 also offers the possibility to repeat the measurement several times before it is validated
        repeatCommand = 0;
        do
        {
            if(++repeatCommand == (MAX_COMMAND_REPEAT + 1)) {
                return REFERENCE_VALUE_ERROR;
            }
            
            MTCH9010_Send_Command(MTCH9010_REF_VALUE_STANDARD);
        } while(MTCH9010_Receive_ACK_NAK() != ACK);
    }
    else if(configData.reference_value == MTCH9010_REF_VALUE_CUSTOM)
    {
        // Send a custom Reference value
        repeatCommand = 0;
        do
        {
            if(++repeatCommand == (MAX_COMMAND_REPEAT + 1)) {
                return REFERENCE_CUSTOM_ERROR;
            }
            
            MTCH9010_Send_Command(configData.reference_custom);
        } while(MTCH9010_Receive_ACK_NAK() != ACK);
    }
    
    // Send the Threshold value
    repeatCommand = 0;
    do
    {
        if(++repeatCommand == (MAX_COMMAND_REPEAT + 1)) {
            return THRESHOLD_ERROR;
        }
        
        MTCH9010_Send_Command(configData.threshold);
    } while(MTCH9010_Receive_ACK_NAK() != ACK);
    
    // Configure CFG_EN pin to exit Enhanged Configuration Mode after reset
    CFG_EN_SetHigh(); // CFG Mode: OFF
    SYS_LK_SetLow(); // SYS Lock: ON
    
    // Verify if the UART should be disabled
    if(configData.extended_output_mode == MTCH9010_EXTENDED_OUTPUT_DISABLE)
    {
        UART_EN_SetHigh();
    }
    
    return CONFIG_DONE; 
}
