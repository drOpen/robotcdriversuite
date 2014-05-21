#pragma config(Sensor, S1,     LEGOLS,              sensorLightInactive)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: lego-light-test1.c $
 */

/**
 * lego-light.h provides an API for the Lego Light Sensor.  This program
 * demonstrates how to use that API.
 *
 * Changelog:
 * - 0.1: Initial release
 * - 0.2: More comments
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 4.10 AND HIGHER

 * Xander Soldaat (xander_at_botbench.com)
 * 25 November 2009
 * version 0.2
 */
#include "lego-light.h"

task main() {
  int raw = 0;
  int nrm = 0;
  bool active = true;
  LSsetActive(LEGOLS);

  nNxtButtonTask  = -2;

  eraseDisplay();
  displayTextLine(0, "Light Sensor");
  displayTextLine(2, "Press orange");
  displayTextLine(3, "button to switch");

  while (true) {
    // The enter button has been pressed, switch
    // to the other mode
    if (nNxtButtonPressed == kEnterButton) {
      active = !active;
      if (!active)
        // Turn the light off
        LSsetInactive(LEGOLS);
      else
        // Turn the light on
        LSsetActive(LEGOLS);

      // wait 500ms to debounce the switch
      sleep(500);
    }

    displayClearTextLine(5);
    displayClearTextLine(6);

    // Get the raw value from the sensor
    raw = LSvalRaw(LEGOLS);

    // Get the normalised value from the sensor
    nrm = LSvalNorm(LEGOLS);

    displayTextLine(5, "Raw:  %4d", raw);
    displayTextLine(6, "Norm: %4d", nrm);
    sleep(50);
  }
}

/*
 * $Id: lego-light-test1.c $
 */
