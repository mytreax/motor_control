/*******************************************************************************
  System Definitions

  File Name:
    userparams.h

  Summary:
    Header file which defines Motor Specific and Board Specific constants 

  Description:
    This file contains the motor and board specific constants. It also defines
 * switches which allows algorithm to be run in debug modes like Open Loop Mode,
 * Torque mode, etc. 

 *******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *******************************************************************************/
//DOM-IGNORE-END

#ifndef USERPARAMS_H 
#define USERPARAMS_H

/*Define the Motor Type*/
#define AC_IM_1    

/* Defining RAM_EXECUTE executes key motor control functions from RAM and thereby allowing faster execution at the expense of data memory
  Undefining RAM_EXECUTE executes key motor control functions from Flash and thereby reducing data memory consumption at the expense of time */
#define RAM_EXECUTE

/*******************************************************************************
Macro definitions
*******************************************************************************/
#define MC_FREQ_HZ      ( 48000000.0f ) /* PWM peripheral frequency */

#define PWM_FREQUENCY 20       /* in kHz   */

#define PWM_HPER_TICKS  ( 1200U )  /* 4000 ticks, total period 8000 ticks @48MHz -> 167us */
/* 1200 ticks , total period 2400 ticks -> 50 micro seconds */

/* motor and application related parameters */
/* Note: only one motor has to be selected! */

#ifdef  AC_IM_1                     /* ACIM Example motor */
#define MOTOR_VOLTAGE   (230)			/* Motor Voltage [Volts] */
#define MAX_MOTOR_SPEED (1800)			/* maximum motor speed [RPM] */
#define VF_CONSTANT     (300)			/* Voltage/Frequency ratio * 2^12 */
#define VF_OFFSET       (104)			/* Voltage offset at starting zero freq */
#define START_SPEED_DEFAULT    (200U)   /* Default startup speed */
#define POLE_PAIRS		(2)             /* number of pole pairs  */
#define ACC_RAMP        (1)             /* acceleration ramp count in internal unit */
#define DEC_RAMP        (1)             /* deceleration ramp count in internal unit */

#endif  /* ifdef AC_IM_1 */

#ifdef  SMALL_HURST                     /* DMB0224C10002 motor */
#define MOTOR_VOLTAGE   (24)			/* Motor Voltage [Volts] */
#define MAX_MOTOR_SPEED (2400)			/* maximum motor speed [RPM] */
#define VF_CONSTANT     (300)			/* Voltage/Frequency ratio * 2^12 */
#define VF_OFFSET       (100)		    /* Voltage offset at starting zero freq */
#define START_SPEED_DEFAULT    (800U)   /* Default startup speed */
#define POLE_PAIRS		(4)             /* number of pole pairs */
#define ACC_RAMP        (1)             /* acceleration ramp count in internal unit */
#define DEC_RAMP        (1)             /* deceleration ramp count in internal unit */

#endif  /* ifdef SMALL_HURST */


#endif // USERPARAMS_H

