/***************************************************************************************************
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *												   												   *
 *      FFFFFFFFFFFFFFFFFFFFFFEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE   SSSSSSSSSSSSSSS       *
 *      F::::::::::::::::::::FE::::::::::::::::::::EE::::::::::::::::::::E SS:::::::::::::::S      *
 *      F::::::::::::::::::::FE::::::::::::::::::::EE::::::::::::::::::::ES:::::SSSSSS::::::S      *
 *      FF::::::FFFFFFFFF::::FEE::::::EEEEEEEEE::::EEE::::::EEEEEEEEE::::ES:::::S     SSSSSSS      *
 *        F:::::F       FFFFFF  E:::::E       EEEEEE  E:::::E       EEEEEES:::::S                  *
 *        F:::::F               E:::::E               E:::::E             S:::::S                  *
 *        F::::::FFFFFFFFFF     E::::::EEEEEEEEEE     E::::::EEEEEEEEEE    S::::SSSS               *
 * ----   F:::::::::::::::F     E:::::::::::::::E     E:::::::::::::::E     SS::::::SSSSS     ---- *
 * -::-   F:::::::::::::::F     E:::::::::::::::E     E:::::::::::::::E       SSS::::::::SS   -::- *
 * ----   F::::::FFFFFFFFFF     E::::::EEEEEEEEEE     E::::::EEEEEEEEEE          SSSSSS::::S  ---- *
 *        F:::::F               E:::::E               E:::::E                         S:::::S      *
 *        F:::::F               E:::::E       EEEEEE  E:::::E       EEEEEE            S:::::S      *
 *      FF:::::::FF           EE::::::EEEEEEEE:::::EEE::::::EEEEEEEE:::::ESSSSSSS     S:::::S      *
 *      F::::::::FF           E::::::::::::::::::::EE::::::::::::::::::::ES::::::SSSSSS:::::S      *
 *      F::::::::FF           E::::::::::::::::::::EE::::::::::::::::::::ES:::::::::::::::SS       *
 *      FFFFFFFFFFF           EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE SSSSSSSSSSSSSSS         *
 *												   												   *
 *               ____    ___     __      ___    ___    __  ___ __       ___   ___        	   	   *
 *               |__ |   |__ \_/||__)|   |__    |__ \_/|__)|__ |__)||\/||__ |\ || /\ |    	       *
 *               |   |___|___/ \||__)|___|___   |___/ \|   |___|  \||  ||___| \||/~~\|___ 	       *
 *                         ___     __  ___ __  __  ___ __     __     ________         		       *
 *                        |__ |\/||__)|__ |  \|  \|__ |  \   /__`\ //__`||__ |\/|     		       *
 *                        |___|  ||__)|___|__/|__/|___|__/   .__/ | .__/||___|  |     		       *
 *                                                                                       	       *
 *												    											   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *												   												   *
 *												   												   *
 *											FEES Project			 					           *
 *		    			URL: https://github.com/ferrandi/DEIB-DAER-project		                   *
 *				 					Politecnico di Milano - DEIB                                   *
 *			    						   Stefano Ampolo	    			                       *
 *		 			  ***********************************************************                  *
 *        		 	   		Copyright (c) 2018-2019 Politecnico di Milano				   		   *
 *                                                                                                 *
 *   This file is part of the FEES framework.                                                      *
 *                                                                                                 *
 *   The FEES framework is free software; you can redistribute it and/or modify                    *
 *   it under the terms of the GNU General Public License as published by                          *
 *   the Free Software Foundation; either version 3 of the License, or                             *
 *   (at your option) any later version.                                                           *
 *                                                                                                 *
 *   This program is distributed in the hope that it will be useful,                           	   *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of                                *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                                 *
 *   GNU General Public License for more details.                                                  *
 *                                                                                                 *
 *   You should have received a copy of the GNU General Public License                             *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.                         *
 *                                                                                                 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * FILE:Pinmask.h
 *
 *  Created on: 14 mar 2019
 *      Author: Stefano
 */

#ifndef PINMASK_H
#define PINMASK_H

#include <iostream>
#include <cstdint>
#include "finiteStateMachine.h"
#include "GpioMapper.h"
#include "finiteStateMachine.h"

using namespace std;

/*

bool GPIO[34];

bool Flag_TELECOM_Active=0;
bool Flag_Analog_Active=0;
bool Flag_GPS_Active=0;
bool Flag_Iridium_Active=0;
bool Flag_Radex_Active=0;
bool Flag_RaspberryPi_WD_Active=0;
bool Flag_ADCS_Active=0;
bool Flag_BatteryManagement_Active=0;
bool Flag_Hardware_Watchdog_Active=0;
bool Flag_Transmission_Watchdog_Active=0;

 */



void Update_Pin_Mask(int NewState);

void Pin_Mask_All_OFF();
void Pin_Mask_InVector();
void Pin_Mask_Wait();
void Pin_Mask_Detumble();
void Pin_Mask_Nominal();
void Pin_Mask_Transmission();
void Pin_Mask_RADEX();

// There is an important difference Between Lowercase and UPPERCASE
// RESET is the action of turning off - waiting and on again a device
// Reset instead is for setting to 0 the GPIO pin.
void GpioSet(int pin);
void GpioReset(int pin);
// The 2 Funcions Above are used to Set==PUT TO 1 and Reset=PUT TO 0 the GPIO pins ATOMICALLY

// User-friendly -STUB Functions
void print_PinMask();
void print_ThreadsAndManagers();

void print_ADCS_State();
void print_BatteryManagement_State();

// // // POWER MANAGEMENT Functions
void System_Reboot();  // Salva i dati critici nella memoria e resetta il sistema.

/**********| TELECOM DEVICE-PAYLOAD       (PC13)*(GPIO 0 )   ******/
void TELECOM_PowerON();
void TELECOM_PowerOFF();
void TELECOM_PowerRESET();

/**********| Analog_DEVICES-PAYLOAD       (PE0)*(GPIO 2 )    ******/
void Analog_PowerON();
void Analog_PowerOFF();
void Analog_PowerRESET();

/**********| GPS DEVICE-PAYLOAD           (PE2)*( GPIO 1 )   ******/
void GPS_PowerON();
void GPS_PowerOFF();
void GPS_PowerRESET();

/**********| Iridium Trasmitter PAYLOAD   (PE3)*(GPIO 29)    ******/
void Iridium_PowerON();
void Iridium_PowerOFF();
void Iridium_PowerRESET();

/**********| RAD-Experiment PAYLOAD    (PE1)*( GPIO 5 )      ******/
void Radex_PowerON();
void Radex_PowerOFF();
void Radex_PowerRESET();
void Radex_SignalRESET();   // Signal GPIO 6 - This RESETS THE 32BitAdc

// RADEX SIGNAL
void RADEX();

/**********| RASPBERRY-Pi CONTROL - (GPIO 3 - 4)  ******     ******/
void RaspberryPi_PowerON();			// GPIO 3
void RaspberryPi_PowerOFF();
void RaspberryPi_PowerRESET();
//GpioReset(RASPY_ON);
//RASPY_KEEP-on thread); 	//KeepON(AliveSignal)  - GPIO 4
void RaspberryPi_Watchdog(); // Questa funzione fa partire il Thread tiene acceso il RaspberryPi

/**********| MagnetoTorquerControl - ADCS SYSTEM  ***** 	******/
void ADCS_ON();
void ADCS_OFF();

/**********| BATTERY THERMAL Control SYSTEM  (PWM 4)(GPIO 14)*/
// BATTERY HEATER PWM - GPIO 14
void BatteryThermal_Management_ON();
void BatteryThermal_Management_OFF();

/**********| WatchDog  Control 	**********************		******/
void Hardware_Watchdog(); // Questa funzione fa partire il Thread che gestisce il Watchdog Hardware

/**********| LED - TELECOM WATCHDOG  Control  (GPIO 19) *** ******/
void Transmission_Watchdog(); // Questa funzione fa partire il Thread che gestisce Led-Watchdog


#endif // PINMASK_H
