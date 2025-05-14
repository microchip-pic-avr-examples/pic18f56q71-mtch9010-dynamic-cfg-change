/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef MTCH9010_H
#define	MTCH9010_H

#include <stdint.h>

#define DAC1_MAX_VALUE                          (1023UL)
#define DAC2_MAX_VALUE                          (255UL)
#define DAC_REFERENCE_VOLTAGE_V                 (3.3)

#define MTCH9010_OP_MODE_CONDUCTIVE             0
#define MTCH9010_OP_MODE_CAPACITIVE             1

#define MTCH9010_SLEEP_TIME_WU                  0
#define MTCH9010_SLEEP_TIME_1S                  (1UL * DAC2_MAX_VALUE / 9UL)
#define MTCH9010_SLEEP_TIME_2S                  (2UL * DAC2_MAX_VALUE / 9UL)
#define MTCH9010_SLEEP_TIME_4S                  (3UL * DAC2_MAX_VALUE / 9UL)
#define MTCH9010_SLEEP_TIME_8S                  (4UL * DAC2_MAX_VALUE / 9UL)
#define MTCH9010_SLEEP_TIME_16S                 (5UL * DAC2_MAX_VALUE / 9UL)
#define MTCH9010_SLEEP_TIME_32S                 (6UL * DAC2_MAX_VALUE / 9UL)
#define MTCH9010_SLEEP_TIME_64S                 (7UL * DAC2_MAX_VALUE / 9UL)
#define MTCH9010_SLEEP_TIME_128S                (8UL * DAC2_MAX_VALUE / 9UL)
#define MTCH9010_SLEEP_TIME_256S                (9UL * DAC2_MAX_VALUE / 9UL)

#define MTCH9010_EXTENDED_OUTPUT_ENABLE         0
#define MTCH9010_EXTENDED_OUTPUT_DISABLE        1

#define MTCH9010_THRESHOLD_VOLTAGE_V(voltage)   (uint16_t)((voltage / DAC_REFERENCE_VOLTAGE_V) * DAC1_MAX_VALUE)

typedef struct
{
    uint8_t op_mode;
    uint8_t sleep_time;
    uint8_t extended_output_mode;
    uint16_t threshold;        
} mtch9010_config_t;

void MTCH9010_Config(mtch9010_config_t configData);


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* MTCH9010_H */

