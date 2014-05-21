#pragma config(Sensor, S1,     HTCS2,               sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: hitechnic-colour-v2-configure.c $
 */

/**
 * hitechnic-colour-v2.h provides an API for the HiTechnic Color V2 Sensor.  This program
 * allows you to configure the operating frequency of the sensor to either 50 or 60Hz.
 * This reduces the amount of interference from the mains frequency affecting the lights
 * in the room.
 *
 * Changelog:
 * - 0.1: Initial release
 * - 0.2: More comments
 *
 * Credits:
 * - Big thanks to HiTechnic for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 4.10 AND HIGHER

 * Xander Soldaat (xander_at_botbench.com)
 * 03 August 2009
 * version 0.2
 */

#include "hitechnic-colour-v2.h"

task main () {
  bool selected_50hz = true;

  displayCenteredTextLine(0, "HiTechnic");
  displayCenteredBigTextLine(1, "Color V2");
  displayCenteredTextLine(4, "Config operating");
  displayCenteredTextLine(5, "frequency to");
  displayCenteredTextLine(6, "50 or 60 Hz");
  sleep(2000);

  eraseDisplay();
  displayCenteredTextLine(0, "Use arrow keys");
  displayCenteredTextLine(1, "to select a");
  displayCenteredTextLine(2, "frequency");
  displayCenteredBigTextLine(4, "50 60");
  displayCenteredTextLine(6, "[enter] to set");
  displayCenteredTextLine(7, "[exit] to cancel");

  drawRect(19, 34, 44, 16);

  while (true) {
    // Do nothing while no buttons are pressed
    while (nNxtButtonPressed == kNoButton) {
      sleep(1);
    }

    switch (nNxtButtonPressed) {
      // if the left button is pressed, set the sensor for 50Hz
      case kLeftButton:
            if (selected_50hz) {
              playSound(soundBlip);
              while(bSoundActive) {sleep(1);}
            } else {
              selected_50hz = true;
              eraseRect(55, 34, 80, 16);
              displayCenteredBigTextLine(4, "50 60");
              drawRect(19, 34, 44, 16);
            }
            break;

       // if the right button is pressed, set the sensor for 60Hz
       case kRightButton:
						if (!selected_50hz) {
						  playSound(soundBlip);
						  while(bSoundActive) {sleep(1);}
						} else {
						  selected_50hz = false;
						  eraseRect(19, 34, 44, 16);
						  displayCenteredBigTextLine(4, "50 60");
						  drawRect(55, 34, 80, 16);
						}
            break;

        // Make the setting permanent by saving it to the sensor
        case kEnterButton:
            eraseDisplay();
            displayCenteredTextLine(2, "The Sensor is");
            displayCenteredTextLine(3, "configured for");
            if (selected_50hz) {
              _HTCSsendCommand(HTCS2, 0x35);
              displayCenteredTextLine(4, "50 Hz operating");
            } else {
              _HTCSsendCommand(HTCS2, 0x36);
              displayCenteredTextLine(4, "60 Hz operating");
            }
            displayCenteredTextLine(5, "frequency");
            for (int i = 5; i > 0; i--) {
              displayCenteredTextLine(7, "Exiting in %d sec", i);
              sleep(1000);
            }
            stopAllTasks();
            break;
    }

    // Debounce the button
    while (nNxtButtonPressed != kNoButton) {
      sleep(1);
    }

  }
}

/*
 * $Id: hitechnic-colour-v2-configure.c $
 */
