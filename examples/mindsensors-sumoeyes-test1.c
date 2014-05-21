#pragma config(Sensor, S2,     HTMSSUMO,            sensorLightActive)
#pragma config(Motor,  motorA,          RIGHT,         tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  motorB,          LEFT,          tmotorNormal, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: mindsensors-sumoeyes-test1.c $
 */

/**
 * mindsensors-sumoeyes.h provides an API for the Mindsensors Sumo Eyes Sensor.  This program
 * demonstrates how to use that API.
 *
 * Changelog:
 * - 0.1: Initial release
 *
 * Credits:
 * - Big thanks to Mindsensors for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 4.10 AND HIGHER

 * Xander Soldaat (xander_at_botbench.com)
 * 20 February 2011
 * version 0.4
 */

#include "mindsensors-sumoeyes.h"

 /*
  =============================================================================
  main task with some testing code

 */
task main() {
  // Standard range is set to short range
  bool shortrange = true;
  tObstacleZone zone = 0;
  nNxtButtonTask  = -2;

  eraseDisplay();

  displayCenteredTextLine(0, "Mindsensors");
  displayCenteredBigTextLine(1, "SUMO Eyes");
  displayCenteredTextLine(3, "Test 1");
  displayCenteredTextLine(5, "Press enter to");
  displayCenteredTextLine(6, "switch between");
  displayCenteredTextLine(7, "ranges");
  sleep(2000);
  eraseDisplay();

  // Set the sensor to short range
  MSSUMOsetShortRange(HTMSSUMO);

  while(true) {
    if (time1[T1] > 1000) {
      if (shortrange == false) {
        // set the sensor to short range and display this
        MSSUMOsetShortRange(HTMSSUMO);
        displayClearTextLine(1);
        displayTextLine(1, "Short range");
        shortrange = true;
      } else {
        // set the sensor to long range and display this
        MSSUMOsetLongRange(HTMSSUMO);
        displayClearTextLine(1);
        displayTextLine(1, "Long range");
        shortrange = false;
      }
	    playSound(soundBeepBeep);
	    while(bSoundActive)
      time1[T1] = 0;
    }

    while(nNxtButtonPressed != kEnterButton) {
      // Read the zone data
      zone = MSSUMOreadZone(HTMSSUMO);

	    switch (zone) {
	      case MSSUMO_FRONT: displayCenteredBigTextLine(4, "FRONT"); break;
	      case MSSUMO_LEFT:  displayCenteredBigTextLine(4, "LEFT");  break;
	      case MSSUMO_RIGHT: displayCenteredBigTextLine(4, "RIGHT"); break;
	      case MSSUMO_NONE:  displayCenteredBigTextLine(4, "NONE");  break;
	    }
      sleep(50);
    }
  }
}

/*
 * $Id: mindsensors-sumoeyes-test1.c $
 */
