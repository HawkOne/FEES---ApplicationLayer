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
 * File:Threads.cpp
 *
 *  Created on: 1 mag 2019
 *      Author: Stefano
 */

#include <stdlib.h>
#include <cstdlib>
#include <sys/types.h>
#include <time.h>
#include <chrono>
#include <iostream>
#include <thread>
#include <ctime>

#include "finiteStateMachine.h"
#include "Pinmask.h"


/*


// Complex Systems - Thread Functions
void thread_ADCS(){
	if(Flag_ADCS_Active == 1){
		// ADCS Algorithm Zone

	}

}
void thread_BatteryPID(){
	if(Flag_BatteryManagement_Active==1){
		// PID Function Zone

	}

}

// Watchdog Thread Functions
void thread_HardwareWD(){ 		// GPIO 20
	// ACTUAL CHIBIOS FUNCTION
	while(1){
		if(Flag_Hardware_Watchdog_Active==1){
			//hal.gpio->write( 20 , 1 );
			//std::this_thread::sleep_for(std::chrono::milliseconds(50));
			//hal.gpio->write( 20, 0 );
			//std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}}
}
void thread_TransmissionWD(){ 	// GPIO 19
	// ACTUAL CHIBIOS FUNCTION
		while(1){
			if(Flag_Transmission_Watchdog_Active==1){
				//hal.gpio->write( 19 , 1 );
				//std::this_thread::sleep_for(std::chrono::milliseconds(50));
				//hal.gpio->write( 19, 0 );
				//std::this_thread::sleep_for(std::chrono::milliseconds(50));

				// Inserire la funzione
				// Trasmetti BEACON
				// Cerca GroundStationBeacon --> fsm.beacon_received=TRUE; //se trovata

			}
		}
}

*/












