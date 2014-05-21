#pragma config(Sensor, S1,     HTCS,                sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: hitechnic-colour-v1-test2.c $
 */

/**
 * hitechnic-colour-v1.h provides an API for the HiTechnic Color Sensor.  This program
 * demonstrates how to use that API.  This program allows you to calibrate the white
 * value for the Color Sensor.  Point the sensor at something you want the sensor to
 * detect as white and press the [enter] button.
 *
 * Changelog:
 * - 0.1: Initial release
 * - 0.2: More comments
 * - 0.3: Removed common.h from includes
 *
 * Credits:
 * - Big thanks to HiTechnic for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 4.10 AND HIGHER

 * Xander Soldaat (xander_at_botbench.com)
 * 20 February 2011
 * version 0.3
 */

#include "hitechnic-colour-v1.h"

task main () {
  // Get control over the buttons
  nNxtButtonTask  = -2;

  eraseDisplay();
  displayTextLine(0, "HTCS Test 2");
  displayTextLine(2, "Press orange");
  displayTextLine(3, "button to start");
  displayTextLine(4, "calibration.");
  displayTextLine(5, "Press grey");
  displayTextLine(6, "button to exit.");

  while(nNxtButtonPressed != kEnterButton) EndTimeSlice();
  eraseDisplay();
  displayTextLine(3, "Starting");
  displayTextLine(4, "calibration.");

  // This call calibrates the white value.
  if (!HTCScalWhite(HTCS)) {
    eraseDisplay();
    playSound(soundException);
    displayTextLine(3, "ERROR!!");
    displayTextLine(5, "Calibration");
    displayTextLine(6, "failed!!");
    sleep(2000);
    stopAllTasks();
  }
  sleep(1000);
}

/*
 * $Id: hitechnic-colour-v1-test2.c $
 */
