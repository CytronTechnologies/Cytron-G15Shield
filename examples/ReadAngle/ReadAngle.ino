/*
This example shows how to read G15 knob position/angle. User need to move the knob
manually, and see the value on Arduino monitor.

Function:
  getPos(G15_ID, data); // data represent for knob position
                        // It have 2 bytes

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

word error = 0;
byte data[10];
word position = 0;

void setup()
{
  g15.begin(19200);
  Serial.begin(9600);

  pinMode(LED, OUTPUT);  
  digitalWrite(LED, LOW);

  delay(2000);
}

void loop()
{
  error = g15.getPos(G15_1, data); // Get G15 ID1 knob position
  if(error == 0) // No error
  {
    digitalWrite(LED, LOW);
    position = data[0];
    position = position | (data[1] << 8);
    Serial.print(position); // Print position
    Serial.print("   ");
    Serial.println(ConvertPosToAngle(position)); // Print angle
  }
  else // Error occur, LED on CT UNO will light up
  {
    digitalWrite(LED, HIGH);
  }
  delay(200);
}
