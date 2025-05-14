/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.1.1
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

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 aliases
#define USER_BUTTON_TRIS                 TRISAbits.TRISA0
#define USER_BUTTON_LAT                  LATAbits.LATA0
#define USER_BUTTON_PORT                 PORTAbits.RA0
#define USER_BUTTON_WPU                  WPUAbits.WPUA0
#define USER_BUTTON_OD                   ODCONAbits.ODCA0
#define USER_BUTTON_ANS                  ANSELAbits.ANSELA0
#define USER_BUTTON_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define USER_BUTTON_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define USER_BUTTON_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define USER_BUTTON_GetValue()           PORTAbits.RA0
#define USER_BUTTON_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define USER_BUTTON_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define USER_BUTTON_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define USER_BUTTON_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define USER_BUTTON_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define USER_BUTTON_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define USER_BUTTON_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define USER_BUTTON_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)
#define RA0_SetInterruptHandler  USER_BUTTON_SetInterruptHandler

// get/set RA2 aliases
#define THR_TRIS                 TRISAbits.TRISA2
#define THR_LAT                  LATAbits.LATA2
#define THR_PORT                 PORTAbits.RA2
#define THR_WPU                  WPUAbits.WPUA2
#define THR_OD                   ODCONAbits.ODCA2
#define THR_ANS                  ANSELAbits.ANSELA2
#define THR_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define THR_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define THR_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define THR_GetValue()           PORTAbits.RA2
#define THR_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define THR_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define THR_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define THR_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define THR_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define THR_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define THR_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define THR_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set RB1 aliases
#define SLP_PER_TRIS                 TRISBbits.TRISB1
#define SLP_PER_LAT                  LATBbits.LATB1
#define SLP_PER_PORT                 PORTBbits.RB1
#define SLP_PER_WPU                  WPUBbits.WPUB1
#define SLP_PER_OD                   ODCONBbits.ODCB1
#define SLP_PER_ANS                  ANSELBbits.ANSELB1
#define SLP_PER_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define SLP_PER_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define SLP_PER_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define SLP_PER_GetValue()           PORTBbits.RB1
#define SLP_PER_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define SLP_PER_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define SLP_PER_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define SLP_PER_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define SLP_PER_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define SLP_PER_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define SLP_PER_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define SLP_PER_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set RD0 aliases
#define OP_MODE_TRIS                 TRISDbits.TRISD0
#define OP_MODE_LAT                  LATDbits.LATD0
#define OP_MODE_PORT                 PORTDbits.RD0
#define OP_MODE_WPU                  WPUDbits.WPUD0
#define OP_MODE_OD                   ODCONDbits.ODCD0
#define OP_MODE_ANS                  ANSELDbits.ANSELD0
#define OP_MODE_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define OP_MODE_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define OP_MODE_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define OP_MODE_GetValue()           PORTDbits.RD0
#define OP_MODE_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define OP_MODE_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define OP_MODE_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define OP_MODE_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define OP_MODE_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define OP_MODE_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define OP_MODE_SetAnalogMode()      do { ANSELDbits.ANSELD0 = 1; } while(0)
#define OP_MODE_SetDigitalMode()     do { ANSELDbits.ANSELD0 = 0; } while(0)

// get/set RD1 aliases
#define RESET_TRIS                 TRISDbits.TRISD1
#define RESET_LAT                  LATDbits.LATD1
#define RESET_PORT                 PORTDbits.RD1
#define RESET_WPU                  WPUDbits.WPUD1
#define RESET_OD                   ODCONDbits.ODCD1
#define RESET_ANS                  ANSELDbits.ANSELD1
#define RESET_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define RESET_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define RESET_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define RESET_GetValue()           PORTDbits.RD1
#define RESET_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define RESET_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define RESET_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define RESET_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define RESET_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define RESET_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define RESET_SetAnalogMode()      do { ANSELDbits.ANSELD1 = 1; } while(0)
#define RESET_SetDigitalMode()     do { ANSELDbits.ANSELD1 = 0; } while(0)

// get/set RD2 aliases
#define CFG_EN_TRIS                 TRISDbits.TRISD2
#define CFG_EN_LAT                  LATDbits.LATD2
#define CFG_EN_PORT                 PORTDbits.RD2
#define CFG_EN_WPU                  WPUDbits.WPUD2
#define CFG_EN_OD                   ODCONDbits.ODCD2
#define CFG_EN_ANS                  ANSELDbits.ANSELD2
#define CFG_EN_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define CFG_EN_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define CFG_EN_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define CFG_EN_GetValue()           PORTDbits.RD2
#define CFG_EN_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define CFG_EN_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define CFG_EN_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define CFG_EN_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define CFG_EN_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define CFG_EN_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define CFG_EN_SetAnalogMode()      do { ANSELDbits.ANSELD2 = 1; } while(0)
#define CFG_EN_SetDigitalMode()     do { ANSELDbits.ANSELD2 = 0; } while(0)

// get/set RD3 aliases
#define SYS_LK_TRIS                 TRISDbits.TRISD3
#define SYS_LK_LAT                  LATDbits.LATD3
#define SYS_LK_PORT                 PORTDbits.RD3
#define SYS_LK_WPU                  WPUDbits.WPUD3
#define SYS_LK_OD                   ODCONDbits.ODCD3
#define SYS_LK_ANS                  ANSELDbits.ANSELD3
#define SYS_LK_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define SYS_LK_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define SYS_LK_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define SYS_LK_GetValue()           PORTDbits.RD3
#define SYS_LK_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define SYS_LK_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define SYS_LK_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define SYS_LK_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define SYS_LK_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define SYS_LK_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define SYS_LK_SetAnalogMode()      do { ANSELDbits.ANSELD3 = 1; } while(0)
#define SYS_LK_SetDigitalMode()     do { ANSELDbits.ANSELD3 = 0; } while(0)

// get/set RD4 aliases
#define UART_EN_TRIS                 TRISDbits.TRISD4
#define UART_EN_LAT                  LATDbits.LATD4
#define UART_EN_PORT                 PORTDbits.RD4
#define UART_EN_WPU                  WPUDbits.WPUD4
#define UART_EN_OD                   ODCONDbits.ODCD4
#define UART_EN_ANS                  ANSELDbits.ANSELD4
#define UART_EN_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define UART_EN_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define UART_EN_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define UART_EN_GetValue()           PORTDbits.RD4
#define UART_EN_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define UART_EN_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define UART_EN_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define UART_EN_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define UART_EN_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define UART_EN_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define UART_EN_SetAnalogMode()      do { ANSELDbits.ANSELD4 = 1; } while(0)
#define UART_EN_SetDigitalMode()     do { ANSELDbits.ANSELD4 = 0; } while(0)

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handler for the USER_BUTTON pin functionality
 * @param none
 * @return none
 */
void USER_BUTTON_ISR(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for USER_BUTTON pin interrupt-on-change functionality.
 *        Allows selecting an interrupt handler for USER_BUTTON at application runtime
 * @pre Pins intializer called
 * @param InterruptHandler function pointer.
 * @return none
 */
void USER_BUTTON_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup  pinsdriver
 * @brief Dynamic Interrupt Handler for USER_BUTTON pin.
 *        This is a dynamic interrupt handler to be used together with the USER_BUTTON_SetInterruptHandler() method.
 *        This handler is called every time the USER_BUTTON ISR is executed and allows any function to be registered at runtime.
 * @pre Pins intializer called
 * @param none
 * @return none
 */
extern void (*USER_BUTTON_InterruptHandler)(void);

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for USER_BUTTON pin. 
 *        This is a predefined interrupt handler to be used together with the USER_BUTTON_SetInterruptHandler() method.
 *        This handler is called every time the USER_BUTTON ISR is executed. 
 * @pre Pins intializer called
 * @param none
 * @return none
 */
void USER_BUTTON_DefaultInterruptHandler(void);


#endif // PINS_H
/**
 End of File
*/