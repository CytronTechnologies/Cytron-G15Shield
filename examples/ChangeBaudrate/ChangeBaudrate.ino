/*
This example shows how to do factory reset on G15. If succeed, G15 LED will blink,
else LED on CT UNO will blink. Note: Please connect one servo at a time.

Function:
  factoryReset(G15_ID); // Do factory reset to the selected ID

Product page:
  Cytron G15 Shield: http://www.cytron.com.my/p-shield-g15
  G15 Cube Servo: http://www.cytron.com.my/p-g15
  CT-UNO: http://www.cytron.com.my/p-ct-uno

Original written by:
            Ing Hui, Cytron Technologies

Modified:
  26/01/16  Idris, Cytron Technologies
*/

#include <SoftwareSerial.h>
#include <Cytron_G15Shield.h>

Cytron_G15Shield g15(2, 3, 8); // SoftwareSerial: Rx, Tx and Control pin
//Cytron_G15Shield g15(8); // HardwareSerial: Control pin

#define G15_ID        1
#define BROADCAST     0xFE
#define NEW_BAUDRATE  115200
#define LED 13

word error = 0;
byte data[10];

void setup()
{
  g15.begin(19200); // Current baudrate
  pinMode(LED, OUTPUT);

  g15.setBaudRate(G15_ID, NEW_BAUDRATE); // Change G15 baudrate to 115200
  delay(100);
  g15.end();
  delay(100);
  g15.begin(NEW_BAUDRATE);
}

void loop()
{
  error = g15.ping(BROADCAST, data);

  if(error == 0 || error == 0x0400) // Ignore ID mistmatch since broadcast ID is used to ping the servo
  {
    if(data[0] == G15_ID) // Succeed change to new ID!
    {
      while(1)
      {
        g15.setLED(G15_ID, ON);
        delay(1000);
        g15.setLED(G15_ID, OFF);
        delay(1000);
      }
    }
    else // Fail, new ID is different
    {
      while(1)
      {
        digitalWrite(LED, LOW);
        delay(1000);
        digitalWrite(LED, HIGH); 
        delay(1000);
      }
    }
  }
  else // Fail, other error occur
  {
    while(1)
    {
      digitalWrite(LED, LOW); 
      delay(200); 
      digitalWrite(LED, HIGH); 
      delay(200); 
    }
  }
}