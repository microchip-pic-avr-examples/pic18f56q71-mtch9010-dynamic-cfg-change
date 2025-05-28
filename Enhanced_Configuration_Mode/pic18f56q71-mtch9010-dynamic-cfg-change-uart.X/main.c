 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.2
 *
 * @version Package Version: 3.1.2
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
#include "mcc_generated_files/system/system.h"
#include "mtch9010.h"

/*
* MTCH9010 with PIC18F56Q71 - Pins usage for Enhanced Configuration
* RA0 - CNANO button - switch between configuration scenarios
* RC0 - MTCH9010 Rx
* RC1 - MTCH9010 Tx
* RD1 - MTCH9010 RESET
* RD2 - MTCH9010 CFG_EN
* RD3 - MTCH9010 SYS_LK
* RD4 - MTCH9010 UART_EN
*/

/*
    Main application
*/

#define CONFIGURATIONS_NO               2

volatile bool buttonPressed = false;

void Button_Handler(void)
{
    buttonPressed = true;
}

void Print_Config_Status(mtch9010_config_status_t status)
{
    switch(status)
    {
        case CONFIG_DONE:
            printf("Configuration done\n\r");
            break;
        case OP_MODE_ERROR:
            printf("Operation Mode error\n\r");
            break;
        case SLEEP_PERIOD_ERROR:
            printf("Sleep Period error\n\r");
            break;   
        case EXTENDED_OUTPUT_MODE_ERROR:
            printf("Extended Output Mode error\n\r");
            break;
        case EXTENDED_OUTPUT_FORMAT_ERROR:
            printf("Extended Output Format error\n\r");
            break;
        case REFERENCE_VALUE_ERROR:
            printf("Reference Value error\n\r");
            break;
        case REFERENCE_CUSTOM_ERROR:
            printf("Reference Custom Value error\n\r");
            break;
        case THRESHOLD_ERROR:
            printf("Threshold error\n\r");
            break;
        default:
            break;   
    }
}

int main(void)
{
    bool cfgMode = true;
    uint8_t cfgNo = 0;
    
    mtch9010_config_status_t configStatus;
    mtch9010_config_t mtch9010_configArray[CONFIGURATIONS_NO];
    
    mtch9010_configArray[0].op_mode = MTCH9010_OP_MODE_CAPACITIVE;
    mtch9010_configArray[0].sleep_period = MTCH9010_SLEEP_PERIOD_2S;
    mtch9010_configArray[0].extended_output_mode = MTCH9010_EXTENDED_OUTPUT_ENABLE;
    mtch9010_configArray[0].extended_output_format = MTCH9010_EXTENDED_OUTPUT_STANDARD;
    mtch9010_configArray[0].reference_value = MTCH9010_REF_VALUE_STANDARD;
    mtch9010_configArray[0].threshold = 300;
    
    mtch9010_configArray[1].op_mode = MTCH9010_OP_MODE_CAPACITIVE;
    mtch9010_configArray[1].sleep_period = MTCH9010_SLEEP_PERIOD_4S;
    mtch9010_configArray[1].extended_output_mode = MTCH9010_EXTENDED_OUTPUT_DISABLE;
    mtch9010_configArray[1].reference_value = MTCH9010_REF_VALUE_STANDARD;
    mtch9010_configArray[1].threshold = 2000;
    
    SYSTEM_Initialize();
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts 
    // Use the following macros to: 

    // Enable the Global Interrupts 
    INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 

    USER_BUTTON_SetInterruptHandler(Button_Handler);
    
    MTCH9010_Init_Pins();
    
    while(1)
    {
        if(buttonPressed == true)
        {
            __delay_ms(10); // Delay for debouncing
            if(~USER_BUTTON_GetValue() & 0x01) // Verify if the button is still pressed
            {
                cfgMode = true;
            }
            
            INTERRUPT_GlobalInterruptDisable(); 
            buttonPressed = false;
            INTERRUPT_GlobalInterruptEnable(); 
        }
        
        if(cfgMode == true)
        {
            configStatus = MTCH9010_Config(mtch9010_configArray[cfgNo]);
            Print_Config_Status(configStatus);
            if(configStatus != CONFIG_DONE)
            { 
                while(1);
            }
            
            cfgMode = false;
            cfgNo++;
            cfgNo &= (CONFIGURATIONS_NO - 1);
        }
    }    
}