
//============================================================================
// Name        : GpioMapper.h
// Author      : Stefano Ampolo
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : this file is needed to link The Schematics to the GPIO system
//
// DA MODIFICARE IL FILE HWDEFINITION di ARDUPILOT.
//============================================================================



#ifndef MAPPER_H
#define MAPPER_H

// GPIO PIN NUMBER
// - POWER "CONTROLS" - RESET ATTIVI BASSI

#define		UHF_RESET		0
#define		GPS_PWR_ON		1
#define		ANALOG_PWR_ON	2
#define		RASPY_ON		3
#define		RASPY_KEEP		4
#define		RAD_PWR_ON		5
#define		RAD_RESET		6

#define		PSD_0	7
#define		PSD_1	8
#define		PSD_2	9
#define		PSD_3	10


// PWM CONTROLS  - PWMX,Y,Z
//  PWMBATT/PWM4/54

#define		PWM_X			PWM(1)
#define		PWM_X_GPIO		11

#define		PWM_Y			PWM(2)
#define		PWM_Y_GPIO		12

#define		PWM_Z			PWM(3)
#define		PWM_Z_GPIO		13

#define	BATTERY_HEATER_PWM		PWM(4)
#define	BATTERY_HEATER_GPIO 	14

#define		DIR_X		15
#define		DIR_Y		16
#define		DIR_Z		17


#define		RADFET_OWB		18

#define		LED		19


#define WATCHDOG	20


// IRIDIUM - SDB (GPIO 60-68)

#define		SDB_0	21		// DCD
#define		SDB_1	22		// DSR
#define		SDB_2	23		// DTR
#define		SDB_3	24		// CTS
#define		SDB_4	25		// RTS
#define		SDB_5	26	// on-off?
#define		SDB_6	27		// RI
#define		SDB_7	28		// NET
#define		SDB_PWR_ON	29  // Iridium Pwr On


#define EX_GPIO_1	30
#define	EX_GPIO_2	31
#define	EX_GPIO_3	32
#define	EX_GPIO_4	33



// POWER "INPUTS"
//	PGOOD -
// 	VUSB  - ADC INTERNO + Termocoppia

//ADC ESTERNO
// I_ X,Y,Z COIL
// BATT_TEMP
// I_CELL_ +X,+Y,+Z,-X
// V_CELL_ +X,+Y+Z,-X
// V_CELL_ +Y_1



#endif // MAPPER_H
