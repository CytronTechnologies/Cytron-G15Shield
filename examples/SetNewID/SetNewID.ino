/*
This example shows how to set G15 to new ID. If succeed, G15 LED will blink,
else LED on CT UNO will blink. Note: Please connect one servo at a time.

Function:
  setID(G15_ID, NEW_ID); // Set current ID (G15_ID) to new ID (NEW_ID)

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

#define NEW_ID    1 // Change the desired ID here
#define BROADCAST 0xFE
#define LED       13

word error = 0;
byte data[10];

void setup()
{  
  g15.begin(19200);

  pinMode(LED, OUTPUT);  
  digitalWrite(LED, LOW);
  delay(1000);
}

void loop()
{
  g15.setID(BROADCAST, NEW_ID);
  
  error = g15.ping(BROADCAST, data);

  if(error == 0 || error == 0x0400) // Ignore ID mistmatch since broadcast ID is used to ping the servo
  {
    if(data[0] == NEW_ID) // Succeed change to new ID!
    {
      while(1)
      {
        g15.setLED(NEW_ID, ON);
        delay(500);
        g15.setLED(NEW_ID, OFF);
        delay(500);
      }
    }
    else // Fail, new ID is different
    {
      while(1)
      {
        digitalWrite(LED, LOW);
        delay(500);
        digitalWrite(LED, HIGH); 
        delay(500);
      }
    }
  }
  else // Fail, other error occur
  {
    while(1)
    {
      digitalWrite(LED, LOW); 
      delay(100); 
      digitalWrite(LED, HIGH); 
      delay(100); 
    }
  }
}
