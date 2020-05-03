/*
 * CatchTest.cpp
 *
 *  Created on: 18 apr 2020
 *      Author: Stefano
 */


#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"

#include <stdlib.h>
#include <cstdlib>
#include <sys/types.h>
#include <time.h>
#include <chrono>
#include <iostream>
#include <thread>
#include <ctime>
#include <limits.h>

#include "../src/finiteStateMachine.h"
#include "../src/GpioMapper.h"
#include "../src/GpiosAndFunctions.h"


using namespace std;



// Creazione dell'Oggetto da testare
finiteStateMachine TEST_FSM;

//Testing Delle funzioni FSM.cpp

//TEST_CASE( "TEST Update_Pin_Mask (a) " ) {
//	Update_Pin_Mask(a);
//	REQUIRE( ... );
//}


TEST_CASE( "TEST finiteStateMachine::set(state_t a) " ) {
	TEST_FSM.set(IN_VECTOR);
		REQUIRE( TEST_FSM.get() == IN_VECTOR );
	TEST_FSM.set(WAIT_FIRST_TIMER);
		REQUIRE( TEST_FSM.get() == WAIT_FIRST_TIMER );
}


TEST_CASE( "TEST finiteStateMachine::get()" ) {
	TEST_FSM.set(IN_VECTOR);
		REQUIRE( TEST_FSM.get() == IN_VECTOR );
	TEST_FSM.set(WAIT_FIRST_TIMER);
		REQUIRE( TEST_FSM.get() == WAIT_FIRST_TIMER );
}


TEST_CASE( "TEST finiteStateMachine::setPrev()" ) {
	TEST_FSM.set(IN_VECTOR);
		REQUIRE( TEST_FSM.get() == IN_VECTOR );
	TEST_FSM.setPrev(WAIT_FIRST_TIMER);
		REQUIRE( TEST_FSM.get() == IN_VECTOR );
		REQUIRE( TEST_FSM.getPrev() == WAIT_FIRST_TIMER );
}




TEST_CASE( "TEST finiteStateMachine::event_Handler()" ) {

	//Unknown Phase

	TEST_FSM.set(RECOVER_PREV_STATE);
	TEST_FSM.setPrev(TRANSMISSION);

	REQUIRE( TEST_FSM.get() == RECOVER_PREV_STATE );
	REQUIRE( TEST_FSM.getPrev() == TRANSMISSION );


	TEST_FSM.event_Handler(); // TEST FUNCTION
	
	REQUIRE( TEST_FSM.get() == TRANSMISSION );
	REQUIRE( TEST_FSM.getPrev() == TRANSMISSION );




	//Launch Phase Test
	TEST_FSM.set(IN_VECTOR);
	TEST_FSM.setPrev(IN_VECTOR);

	TEST_FSM.switch_vector= 1;
	TEST_FSM.event_Handler(); // TEST FUNCTION


	REQUIRE( TEST_FSM.get() == WAIT_FIRST_TIMER );
	REQUIRE( TEST_FSM.getPrev() == WAIT_FIRST_TIMER );



	TEST_FSM.set(WAIT_FIRST_TIMER);
	TEST_FSM.setPrev(WAIT_FIRST_TIMER);

	TEST_FSM.first_timer = 0;
	TEST_FSM.event_Handler(); // TEST FUNCTION


	REQUIRE( TEST_FSM.get() == DETUMBLE_SECOND_TIMER );
	REQUIRE( TEST_FSM.getPrev() == DETUMBLE_SECOND_TIMER );



	TEST_FSM.set(DETUMBLE_SECOND_TIMER);
	TEST_FSM.setPrev(DETUMBLE_SECOND_TIMER);

	TEST_FSM.second_timer = 0;
	TEST_FSM.event_Handler(); // TEST FUNCTION


	REQUIRE( TEST_FSM.get() == NOMINAL );
	REQUIRE( TEST_FSM.getPrev() == NOMINAL );


	//w>wLim
	TEST_FSM.set(DETUMBLE_SECOND_TIMER);
	TEST_FSM.setPrev(DETUMBLE_SECOND_TIMER);

	TEST_FSM.angular_velocity= 3500;
	TEST_FSM.event_Handler(); // TEST FUNCTION

	REQUIRE( TEST_FSM.get() == NOMINAL );
	REQUIRE( TEST_FSM.getPrev() == NOMINAL );

	//w<wLim
	TEST_FSM.set(DETUMBLE_SECOND_TIMER);
	TEST_FSM.setPrev(DETUMBLE_SECOND_TIMER);

	TEST_FSM.angular_velocity= 49;
	TEST_FSM.event_Handler(); // TEST FUNCTION

	REQUIRE( TEST_FSM.get() == NOMINAL );
	REQUIRE( TEST_FSM.getPrev() == NOMINAL );



	// ORBIT PHASE

	// From Nominal to Transmission
	TEST_FSM.set(NOMINAL);
	TEST_FSM.setPrev(NOMINAL);


	TEST_FSM.beacon_received=true;
	TEST_FSM.transmission_finished=false;
	TEST_FSM.trx_timer = CONST_TRX_TIMER;

	TEST_FSM.event_Handler();  // TEST FUNCTION

	REQUIRE( TEST_FSM.get() == TRANSMISSION );
	REQUIRE( TEST_FSM.getPrev() == TRANSMISSION );

	// From Nominal to Transmission
	TEST_FSM.set(NOMINAL);
	TEST_FSM.setPrev(NOMINAL);

	TEST_FSM.beacon_received=true;

	TEST_FSM.event_Handler();  // TEST FUNCTION

	REQUIRE( TEST_FSM.get() == TRANSMISSION );
	REQUIRE( TEST_FSM.getPrev() == TRANSMISSION );






	//From Nominal to Radex
	TEST_FSM.set(NOMINAL);
	TEST_FSM.setPrev(NOMINAL);


	TEST_FSM.timer_for_radex = 0;
	TEST_FSM.radex_scheduled=true;
	TEST_FSM.radex_finished=false;
	TEST_FSM.event_Handler();  // TEST FUNCTION

	REQUIRE( TEST_FSM.get() == RADEX_MODE );
	REQUIRE( TEST_FSM.getPrev() == RADEX_MODE );




	// Test  From Transmission to Nominal
	TEST_FSM.set(TRANSMISSION);
	TEST_FSM.setPrev(TRANSMISSION);

	TEST_FSM.transmission_finished=true;
	TEST_FSM.event_Handler();  // TEST FUNCTION

	REQUIRE( TEST_FSM.get() == NOMINAL );
	REQUIRE( TEST_FSM.getPrev() == NOMINAL );



	// Test  From Radex to Nominal
	TEST_FSM.set(RADEX_MODE);
	TEST_FSM.setPrev(RADEX_MODE);

	TEST_FSM.radex_finished=true;
	TEST_FSM.event_Handler();  // TEST FUNCTION

	REQUIRE( TEST_FSM.get() == NOMINAL );
	REQUIRE( TEST_FSM.getPrev() == NOMINAL );
}






TEST_CASE( "TEST della FSM - Passaggi di Stato", "[FSM-]" ) {

//    Modifica:     ES  std::vector<int> v( 5 );
//    Condizioni :  ES  REQUIRE( v.size() == 5 );

    GIVEN( "Partendo da IN_VECTOR" ) {
        TEST_FSM.set(IN_VECTOR);
        //FLAGS
        TEST_FSM.switch_vector= FALSE;			// Flag dello Switch Meccanico Cubesat-Lanciatore  0 = Attached, 1 = Detached. (Se switch_vector==0 (FALSE)  il thread di campionamento dello switch sará attivo.)
        TEST_FSM.beacon_received=FALSE;			// Flag di Beacon Received
        TEST_FSM.radex_scheduled=FALSE;			// Flag di Radex Scheduled
        TEST_FSM.radex_finished=FALSE;			// Flag di Radex Finished
        TEST_FSM.transmission_finished=FALSE;	// Flag di Fine Trasmissione


        	//TIMERS
        TEST_FSM.first_timer= CONST_SILENZIO_RADIO ; 		// 30 min  --> Requisito di silenzio radio
        TEST_FSM.second_timer = DETHUMBLING_TIMER ; 		// 10 min  --> Timer massimo di Dethumbling
        TEST_FSM.timer_for_radex = 0;		// Timer di Scheduling del Rad-ex
        TEST_FSM.radex_timer = CONST_RADEX_TIMER;			// Timer Time-Out del Rad-ex
        TEST_FSM.trx_timer = CONST_TRX_TIMER;			// Timer Time-Out Trasmissione
        TEST_FSM.angular_velocity= 8888888;	// Valore di inizializzazione Angular_velocity

        REQUIRE( TEST_FSM.get() == IN_VECTOR );
        REQUIRE( TEST_FSM.getPrev() == IN_VECTOR );

        WHEN( "Se faccio scattare il switch_vector" ) {
            TEST_FSM.switch_vector = 1;
        	TEST_FSM.event_Handler();  // TEST FUNCTION

            THEN( "Allora passerá automaticamente a WAIT_FIRST_TIMER (Sia lo stato Attuale che il Prev." ) {
                REQUIRE( TEST_FSM.get() == WAIT_FIRST_TIMER );
                REQUIRE( TEST_FSM.getPrev() == WAIT_FIRST_TIMER );
            }
        }
    }

    GIVEN( "Quando sono in WAIT_FIRST_TIMER" ) {
        TEST_FSM.set(WAIT_FIRST_TIMER);
        //FLAGS
        TEST_FSM.switch_vector= FALSE;			// Flag dello Switch Meccanico Cubesat-Lanciatore  0 = Attached, 1 = Detached. (Se switch_vector==0 (FALSE)  il thread di campionamento dello switch sará attivo.)
        TEST_FSM.beacon_received=FALSE;			// Flag di Beacon Received
        TEST_FSM.radex_scheduled=FALSE;			// Flag di Radex Scheduled
        TEST_FSM.radex_finished=FALSE;			// Flag di Radex Finished
        TEST_FSM.transmission_finished=FALSE;	// Flag di Fine Trasmissione


                	//TIMERS
       TEST_FSM.first_timer= CONST_SILENZIO_RADIO ; 		// 30 min  --> Requisito di silenzio radio
       TEST_FSM.second_timer = DETHUMBLING_TIMER ; 		// 10 min  --> Timer massimo di Dethumbling
       TEST_FSM.timer_for_radex = 0;		// Timer di Scheduling del Rad-ex
       TEST_FSM.radex_timer = CONST_RADEX_TIMER;			// Timer Time-Out del Rad-ex
       TEST_FSM.trx_timer = CONST_TRX_TIMER;			// Timer Time-Out Trasmissione
       TEST_FSM.angular_velocity= 8888888;	// Valore di inizializzazione Angular_velocity


        REQUIRE( TEST_FSM.get() == WAIT_FIRST_TIMER );
        REQUIRE( TEST_FSM.getPrev() == WAIT_FIRST_TIMER );

        WHEN( "Se finisce il primo timer " ) {
            TEST_FSM.first_timer = 0;
        	TEST_FSM.event_Handler();  // TEST FUNCTION

            THEN( "Allora lo stato passerá a DETUMBLE_SECOND_TIMER (Sia lo stato Attuale che il Prev." ) {
                REQUIRE( TEST_FSM.get() == DETUMBLE_SECOND_TIMER );
                REQUIRE( TEST_FSM.getPrev() == DETUMBLE_SECOND_TIMER );
            }
        }
    }


    GIVEN( "Quando sono in DETUMBLE_SECOND_TIMER" ) {
       TEST_FSM.set(DETUMBLE_SECOND_TIMER);
        //FLAGS
       TEST_FSM.switch_vector= FALSE;			// Flag dello Switch Meccanico Cubesat-Lanciatore  0 = Attached, 1 = Detached. (Se switch_vector==0 (FALSE)  il thread di campionamento dello switch sará attivo.)
       TEST_FSM.beacon_received=FALSE;			// Flag di Beacon Received
       TEST_FSM.radex_scheduled=FALSE;			// Flag di Radex Scheduled
       TEST_FSM.radex_finished=FALSE;			// Flag di Radex Finished
       TEST_FSM.transmission_finished=FALSE;	// Flag di Fine Trasmissione


                	//TIMERS
       TEST_FSM.first_timer= CONST_SILENZIO_RADIO ; 		// 30 min  --> Requisito di silenzio radio
       TEST_FSM.second_timer = DETHUMBLING_TIMER ; 		// 10 min  --> Timer massimo di Dethumbling
       TEST_FSM.timer_for_radex = 0;		// Timer di Scheduling del Rad-ex
       TEST_FSM.radex_timer = CONST_RADEX_TIMER;			// Timer Time-Out del Rad-ex
       TEST_FSM.trx_timer = CONST_TRX_TIMER;			// Timer Time-Out Trasmissione
       TEST_FSM.angular_velocity= 8888888;	// Valore di inizializzazione Angular_velocity


        REQUIRE( TEST_FSM.get() == DETUMBLE_SECOND_TIMER );
        REQUIRE( TEST_FSM.getPrev() == DETUMBLE_SECOND_TIMER );

        WHEN( "Se finisce il secondo timer " ) {
            TEST_FSM.second_timer = 0;
        	TEST_FSM.event_Handler();  // TEST FUNCTION

            THEN( "Allora lo stato passerá a NOMINAL (Sia lo stato Attuale che il Prev." ) {
                REQUIRE( TEST_FSM.get() == NOMINAL );
                REQUIRE( TEST_FSM.getPrev() == NOMINAL );
            }
        }
    }



}



////}
//
//
//
//
//
//
//
//
//
//
// SCENARIO( "vectors can be sized and resized", "[vector]" ) {
//     GIVEN( "A vector with some items" ) {
//         std::vector<int> v( 5 );
//         REQUIRE( v.size() == 5 );
//         REQUIRE( v.capacity() >= 5 );
//         WHEN( "the size is increased" ) {
//             v.resize( 10 );
//             THEN( "the size and capacity change" ) {
//                 REQUIRE( v.size() == 10 );
//                 REQUIRE( v.capacity() >= 10 );
//             }
//         }
//         WHEN( "the size is reduced" ) {
//             v.resize( 0 );
//             THEN( "the size changes but not capacity" ) {
//                 REQUIRE( v.size() == 0 );
//                 REQUIRE( v.capacity() >= 5 );
//             }
//         }
//         WHEN( "more capacity is reserved" ) {
//             v.reserve( 10 );
//             THEN( "the capacity changes but not the size" ) {
//                 REQUIRE( v.size() == 5 );
//                 REQUIRE( v.capacity() >= 10 );
//             }
//         }
//         WHEN( "less capacity is reserved" ) {
//             v.reserve( 0 );
//             THEN( "neither size nor capacity are changed" ) {
//                 REQUIRE( v.size() == 5 );
//                 REQUIRE( v.capacity() >= 5 );
//             }
//         }
//     }
//}
