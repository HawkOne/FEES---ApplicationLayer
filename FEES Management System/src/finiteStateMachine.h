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
 * File:FiniteStateMachine.h
 *
 *  Created on: 10 apr 2019
 *      Author: Stefano
 */

#ifndef STATE_H
#define STATE_H

#define TRUE true
#define FALSE false



#include <iostream>
#include <cstdint>
#include "GpiosAndFunctions.h"

using namespace std;



enum state_t {
	RECOVER_PREV_STATE = 0, 	// First State after BOOT.
    IN_VECTOR, 					// FEES inside the vector, both Switches still connected
    WAIT_FIRST_TIMER, 			// FEES out of the launcher - First Timer on, 30'
    DETUMBLE_SECOND_TIMER, 		// FEES Detumbling , Second Timer on, Angular speed limit to be decided.
    NOMINAL, 					// FEES NOMINAL STATE - Everything Good.
    TRANSMISSION, 				// FEES Transmission State, Everything else is off.
    RADEX_MODE, 				// FEES RADEX MODE - Programmed Experiment.
};





class finiteStateMachine {

public:
	state_t get();
	void set(state_t a);
	void print_State();
	void print_Menu();
	void print_StateList();
	void print_Variables();
	void event_Handler();
	void human_event_Handler(int a);

	bool switch_vector;
	bool beacon_received;
	bool radex_scheduled;
	bool radex_finished;
	bool transmission_finished;


	float first_timer;
	float second_timer;
	float timer_for_radex;
	float trx_timer;
	float radex_timer;

	state_t previous_state;


	// Constructor - Destructor
	finiteStateMachine();
	virtual ~finiteStateMachine();

private:
	state_t state;
};


void Update_Pin_Mask(state_t NewState);

#endif 	/* STATE_H */

