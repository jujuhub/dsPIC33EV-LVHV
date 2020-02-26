/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.155.0-a
        Device            :  dsPIC33EV256GM102
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.40
        MPLAB 	          :  MPLAB X v5.25
*/

/*
    (c) 2019 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
  *** NOTE: MUST INCLUDE "mcc.h" !! It contains the other .h files. ***
*/
#include <stdio.h>
#include <time.h>

#include "mcc_generated_files/system.h"
#include "mcc_generated_files/mcc.h"
#include "hih6030-021/hih6030.h"

// need to check return values in HIH6030.c
#define RHT_OK 0
#define RHT_NOTOK 1

/*
                         Main application
 */
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    int rht_status = RHT_OK;
    uint16_t pin26 = 0;

    while (1)
    {
        // Add your application code

        // Photodiode
        // read pin 3 (RA1)
//        PhotoDiode_GetValue(); // returns uint16_t but pin 3 set to analog I

        // LTC 2631 : DAC INTERFACE W/ HV_CTRL
        // read pins 14 (RB5), 15 (RB6)


        // HIH6030-021-001 : RELATIVE HUMIDITY AND TEMPERATURE 
        rht_status = HIH6030_GetRHTStatus();
//        rht_status = RHT_NOTOK; // for debugging
        if (rht_status == RHT_NOTOK)
        {
          // turn LV OFF; pin 26 (RB15)
//          printf("Turning off LV.. \n");
          LV_ON_OFF_SetLow();
          pin26 = LV_ON_OFF_GetValue(); // not sure if this is valid since output
          if (pin26 == 0)
          {
//            printf("LV successfully turned OFF ! \n");
          }
//          else
//          {
//            delay(3000);
//          }
//
//          // turn HV OFF; pin 12 (RA4)
//          printf("Turning off HV.. \n");
//          HV_ON_OFF_SetLow();
        }
        else
        {
          printf("Relative humidity and temperature OK ! \n");
        }
    }

    return 1; 
}

/**
 End of File
*/

