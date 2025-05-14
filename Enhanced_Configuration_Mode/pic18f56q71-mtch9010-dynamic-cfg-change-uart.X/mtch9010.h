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

#define ENTER_KEY                           0x0D
#define ACK                                 0x06
#define NAK                                 0x15

#define MAX_COMMAND_REPEAT                  5

#define MTCH9010_OP_MODE_CAPACITIVE         0
#define MTCH9010_OP_MODE_CONDUCTIVE         1

#define MTCH9010_SLEEP_TIME_WU              0
#define MTCH9010_SLEEP_TIME_1S              1
#define MTCH9010_SLEEP_TIME_2S              2
#define MTCH9010_SLEEP_TIME_4S              3
#define MTCH9010_SLEEP_TIME_8S              4
#define MTCH9010_SLEEP_TIME_16S             5
#define MTCH9010_SLEEP_TIME_32S             6
#define MTCH9010_SLEEP_TIME_64S             7
#define MTCH9010_SLEEP_TIME_128S            8
#define MTCH9010_SLEEP_TIME_256S            9

#define MTCH9010_EXTENDED_OUTPUT_DISABLE    0
#define MTCH9010_EXTENDED_OUTPUT_ENABLE     1

#define MTCH9010_EXTENDED_OUTPUT_DELTA      0
#define MTCH9010_EXTENDED_OUTPUT_STANDARD   1
#define MTCH9010_EXTENDED_OUTPUT_BOTH       2
#define MTCH9010_EXTENDED_OUTPUT_DV         3

#define MTCH9010_REF_VALUE_STANDARD         0
#define MTCH9010_REF_VALUE_REPEAT           1
#define MTCH9010_REF_VALUE_CUSTOM           2

typedef struct
{
    uint8_t op_mode;
    uint8_t sleep_time;
    uint8_t extended_output_mode;
    uint8_t extended_output_format;
    uint8_t reference_value;
    uint16_t reference_custom;
    uint16_t threshold;        
} mtch9010_config_t;

typedef enum
{
    CONFIG_DONE = 0,
    OP_MODE_ERROR,
    SLEEP_TIME_ERROR,
    EXTENDED_OUTPUT_MODE_ERROR,
    EXTENDED_OUTPUT_FORMAT_ERROR,
    REFERENCE_VALUE_ERROR,
    REFERENCE_CUSTOM_ERROR,
    THRESHOLD_ERROR
}mtch9010_config_status_t;

void MTCH9010_Init_Pins(void);

void MTCH9010_Receive_Firmare_Version(char *firmwareVersion);

uint8_t MTCH9010_Receive_ACK_NAK(void);

uint16_t MTCH9010_Receive_Data(void);

void MTCH9010_Send_Command(uint16_t command);

mtch9010_config_status_t MTCH9010_Config(mtch9010_config_t configData);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* MTCH9010_H */

