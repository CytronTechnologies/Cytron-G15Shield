/*
This example shows how to move G15 knob to certain angle with different speed.

Function:
  setLED(G15_ID, onOff); // Control G15 LED. onOff: ON or OFF
  setSpeed(G15_ID, speed); // Set G15 speed: 0 - 1023
  setPosAngle(G15_ID, angle); // Set G15 angle: 0 - 359

Product page:
  Cytron G15 Shield: http://www.cytron.com.my/p-shield-g15
  G15 Cube Servo: http://www.cytron.com.my/p-g15
  CT-UNO: http://www.cytron.com.my/p-ct-uno

Original written by:
            Ing Hui, Cytron Technologies

Modified:
  29/06/15  Idris, Cytron Technologies
*/

#include <SoftwareSerial.h>
#include <Cytron_G15Shield.h>

Cytron_G15Shield g15(2, 3, 8); // SoftwareSerial: Rx, Tx and Control pin
//Cytron_G15Shield g15(8); // HardwareSerial: Control pin

#define G15_1 1
#define G15_2 2
#define LED 13

void setup()
{
  g15.begin(19200);

  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  delay(500);
  digitalWrite(LED, HIGH);

  // Make sure G15 in position mode
  g15.exitWheelMode(G15_1);
  g15.exitWheelMode(G15_2);
}

void loop()
{
  // Controlling G15 with ID 1
  g15.setLED(G15_1, ON);
  g15.setSpeed(G15_1, 500); // Set G15 (ID = 1) speed to 500, 
  g15.setPosAngle(G15_1, 0); // Set G15 (ID = 1) position to 0 deg
  delay(1000);

  g15.setLED(G15_1, OFF);
  g15.setSpeed(G15_1, 250);
  g15.setPosAngle(G15_1, 90); // Set G15 (ID = 1) position to 90 deg
  delay(1000); 

  // Controlling G15 with ID 2
  g15.setLED(G15_2, ON);
  g15.setSpeed(G15_2, 250);
  g15.setPosAngle(G15_2, 0); // Set G15 (ID = 2) position to 0 deg
  delay(1000);

  g15.setLED(G15_2, OFF);
  g15.setSpeed(G15_2, 500);
  g15.setPosAngle(G15_2, 90); // Set G15 (ID = 2) position to 90 deg
  delay(1000);
}
