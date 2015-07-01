/*
This example shows how to set and control G15 as wheel mode.

Function:
  setWheelMode(G15_ID); // Set G15 to wheel mode
  setWheelSpeed(G15_ID, speed, direction); // speed: 0 - 1023
                                           // direction: CW or CCW
  exitWheelMode(G15_ID); // Set G15 to angle mode

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
#define LED 13

void setup()
{
  g15.begin(19200); // G15 default baudrate
  
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  delay(1000);
}

void loop()
{
  digitalWrite(LED, HIGH);
  g15.setWheelMode(G15_1); // Set G15 to wheel mode
  g15.setWheelSpeed(G15_1, 1023, CW); // Full speed with CW direction
  delay(5000);

  g15.setWheelSpeed(G15_1, 512, CCW); // Half speed with CCW direction
  delay(5000);

  digitalWrite(LED, LOW);
  g15.exitWheelMode(G15_1); // Set G15 to angle mode
  delay(1000);
}
