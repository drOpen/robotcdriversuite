#pragma config(Sensor, S1,     HTSMUX,              sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: lego-light-SMUX-test1.c $
 */

/**
 * lego-light.h provides an API for the Lego Light Sensor.  This program
 * demonstrates how to use that API through a SMUX.
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

#include "hitechnic-sensormux.h"
#include "lego-light.h"

// The sensor is connected to the first port
// of the SMUX which is connected to the NXT port S1.
// To access that sensor, we must use msensor_S1_1.  If the sensor
// were connected to 3rd port of the SMUX connected to the NXT port S4,
// we would use msensor_S4_3

// Give the sensor a nice easy to use name
const tMUXSensor LEGOLS = msensor_S1_1;

task main() {
  int raw = 0;
  int nrm = 0;
  bool active = true;

  // Turn the light on
  LSsetActive(LEGOLS);

  nNxtButtonTask  = -2;

  displayCenteredTextLine(0, "Lego");
  displayCenteredBigTextLine(1, "LIGHT");
  displayCenteredTextLine(3, "SMUX Test");
  displayCenteredTextLine(5, "Connect SMUX to");
  displayCenteredTextLine(6, "S1 and sensor to");
  displayCenteredTextLine(7, "SMUX Port 1");
  sleep(2000);

  displayClearTextLine(7);
  displayTextLine(5, "Press [enter]");
  displayTextLine(6, "to toggle light");
  sleep(2000);

  while (true) {
    // The enter button has been pressed, switch
    // to the other mode
    if (nNxtButtonPressed == kEnterButton) {
      active = !active;
      if (!active)
        LSsetInactive(LEGOLS);
      else
        LSsetActive(LEGOLS);

      // wait 500ms to debounce the switch
      sleep(500);
    }

    displayClearTextLine(5);
    displayClearTextLine(6);
    raw = LSvalRaw(LEGOLS);
    nrm = LSvalNorm(LEGOLS);
    displayTextLine(5, "Raw:  %4d", raw);
    displayTextLine(6, "Norm: %4d", nrm);
    sleep(50);
  }
}

/*
 * $Id: lego-light-SMUX-test1.c $
 */
