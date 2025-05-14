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

// get/set RB4 aliases
#define IO_RB4_TRIS                 TRISBbits.TRISB4
#define IO_RB4_LAT                  LATBbits.LATB4
#define IO_RB4_PORT                 PORTBbits.RB4
#define IO_RB4_WPU                  WPUBbits.WPUB4
#define IO_RB4_OD                   ODCONBbits.ODCB4
#define IO_RB4_ANS                  ANSELBbits.ANSELB4
#define IO_RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define IO_RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define IO_RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define IO_RB4_GetValue()           PORTBbits.RB4
#define IO_RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define IO_RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define IO_RB4_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define IO_RB4_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define IO_RB4_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define IO_RB4_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define IO_RB4_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define IO_RB4_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RB5 aliases
#define IO_RB5_TRIS                 TRISBbits.TRISB5
#define IO_RB5_LAT                  LATBbits.LATB5
#define IO_RB5_PORT                 PORTBbits.RB5
#define IO_RB5_WPU                  WPUBbits.WPUB5
#define IO_RB5_OD                   ODCONBbits.ODCB5
#define IO_RB5_ANS                  ANSELBbits.ANSELB5
#define IO_RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define IO_RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define IO_RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define IO_RB5_GetValue()           PORTBbits.RB5
#define IO_RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define IO_RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define IO_RB5_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define IO_RB5_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define IO_RB5_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define IO_RB5_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define IO_RB5_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define IO_RB5_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set RC0 aliases
#define IO_RC0_TRIS                 TRISCbits.TRISC0
#define IO_RC0_LAT                  LATCbits.LATC0
#define IO_RC0_PORT                 PORTCbits.RC0
#define IO_RC0_WPU                  WPUCbits.WPUC0
#define IO_RC0_OD                   ODCONCbits.ODCC0
#define IO_RC0_ANS                  ANSELCbits.ANSELC0
#define IO_RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define IO_RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define IO_RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define IO_RC0_GetValue()           PORTCbits.RC0
#define IO_RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define IO_RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define IO_RC0_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define IO_RC0_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define IO_RC0_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define IO_RC0_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define IO_RC0_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define IO_RC0_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set RC1 aliases
#define IO_RC1_TRIS                 TRISCbits.TRISC1
#define IO_RC1_LAT                  LATCbits.LATC1
#define IO_RC1_PORT                 PORTCbits.RC1
#define IO_RC1_WPU                  WPUCbits.WPUC1
#define IO_RC1_OD                   ODCONCbits.ODCC1
#define IO_RC1_ANS                  ANSELCbits.ANSELC1
#define IO_RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define IO_RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define IO_RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define IO_RC1_GetValue()           PORTCbits.RC1
#define IO_RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define IO_RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define IO_RC1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define IO_RC1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define IO_RC1_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define IO_RC1_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define IO_RC1_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define IO_RC1_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

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