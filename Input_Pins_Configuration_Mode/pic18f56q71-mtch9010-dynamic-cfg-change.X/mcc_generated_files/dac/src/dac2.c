/**
 * DAC2 Generated Driver File
 * 
 * @file dac2.c
 * 
 * @ingroup dac2
 * 
 * @brief This is the generated driver implementation file for the DAC2 driver using PIC10/12/16/18 MCUs
 *
 * @version DAC2 Driver Version 2.1.2
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
#include "../dac2.h"

/**
  Section: DAC2 APIs
*/

void DAC2_Initialize(void) 
{ 
    //DACPSS VDD; DACNSS VSS; DACOE DACOUT1 and DACOUT2 are Disabled; DACEN enabled; 
    DAC2CON =  0x80;

    //DACR 0; 
    DAC2DATL =  0x0;     
}

void DAC2_SetOutput(uint8_t inputData) 
{
    DAC2DATL =  inputData;
}
uint8_t DAC2_GetOutput(void) 
{
    return DAC2DATL;
}

/**
 End of File
*/
