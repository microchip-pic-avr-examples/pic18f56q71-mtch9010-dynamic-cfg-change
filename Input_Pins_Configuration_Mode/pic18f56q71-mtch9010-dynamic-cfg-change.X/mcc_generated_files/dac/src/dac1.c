/**
 * DAC1 Generated Driver File
 * 
 * @file dac1.c
 * 
 * @ingroup dac1
 * 
 * @brief This is the generated driver implementation file for the DAC1 driver using PIC10/12/16/18 MCUs
 *
 * @version DAC1 Driver Version 2.1.2
*/
/*
� [2025] Microchip Technology Inc. and its subsidiaries.

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

/**
  Section: Included Files
*/

#include <xc.h>
#include "../dac1.h"

/**
  Section: DAC1 APIs
*/

void DAC1_Initialize(void) 
{ 
    //DACPSS VDD; DACNSS VSS; DACOE DACOUT1 Enabled and DACOUT2 Disabled; DACEN enabled; 
    DAC1CON =  0x90;

    //DACR 0; 
    DAC1DATH =  0x0;

    //DACR 0; 
    DAC1DATL =  0x0;     
}

void DAC1_SetOutput(uint16_t inputData) 
{    
    DAC1DATH = (uint8_t)((inputData >> 8) & 0x00FFU);
    DAC1DATL = (uint8_t)(inputData & 0x00FFU);
}

uint16_t DAC1_GetOutput(void)
{ 
    return (uint16_t)(((uint16_t)DAC1DATH << 8) | DAC1DATL);
}

/**
 End of File
*/
