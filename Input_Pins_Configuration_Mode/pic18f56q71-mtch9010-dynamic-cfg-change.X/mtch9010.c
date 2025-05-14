 /*
 * MTCH9010 File
 * 
 * @file mtch9010.c
 * 
 * @defgroup mtch9010
 *
 * @brief This file contains the functions used to configure MTCH9010 in GPIO Configuration Mode.
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

void MTCH9010_Config(mtch9010_config_t configData)
{
    // SYS LOCK: OFF
    SYS_LK_SetHigh();
    
    // CFG Mode: OFF
    CFG_EN_SetHigh();
    
    // Set Operation mode
    if(configData.op_mode == MTCH9010_OP_MODE_CONDUCTIVE)
    {
        OP_MODE_SetLow();
    }
    else if(configData.op_mode == MTCH9010_OP_MODE_CAPACITIVE)
    {
        OP_MODE_SetHigh();
    }
    
    // Set Sleep time
    DAC2_SetOutput(configData.sleep_time);
    
    // Set Extended output mode
    if(configData.extended_output_mode == MTCH9010_EXTENDED_OUTPUT_ENABLE)
    {
        UART_EN_SetLow();
    }
    else if(configData.extended_output_mode == MTCH9010_EXTENDED_OUTPUT_DISABLE)
    {
        UART_EN_SetHigh();
    }
    
    // Set Threshold value
    DAC1_SetOutput(configData.threshold);
    
    // Reset MTCH9010
    RESET_SetLow();
    __delay_ms(10);
    RESET_SetHigh();
}
