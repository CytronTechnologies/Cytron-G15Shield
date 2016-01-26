/*
This example shows how to do factory reset on G15. It will reset your G15
to default ID (0x01) and baudrate (19200 bps). If succeed, G15 LED will blink,
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

#define DEFAULT_ID  0x01
#define BROADCAST   0xFE
#define LED 13

word error = 0;
byte data[10];
int baudrateMode = 0;

void setup()
{
  pinMode(LED, OUTPUT);
}

void loop()
{
  switch(baudrateMode)
  {
    case 0:
      g15.begin(1200);
      break;

    case 1:
      g15.begin(2400);
      break;

    case 2:
      g15.begin(4800);
      break;

    case 3:
      g15.begin(9600);
      break;

    case 4:
      g15.begin(19200);
      break;

    case 5:
      g15.begin(38400);
      break;

    case 6:
      g15.begin(57600);
      break;

    case 7:
      g15.begin(115200);
      break;

    default:
      break;
  }

  g15.factoryReset(BROADCAST);
  delay(100);
  error = g15.ping(BROADCAST, data);

  if(error == 0 || error == 0x0400) // Ignore ID mistmatch since broadcast ID is used to ping the servo
  {
    if(data[0] == DEFAULT_ID) // Success
    {
      g15.setBaudRate(DEFAULT_ID, 19200); // Change to default baudrate
      delay(100);
      g15.end();
      delay(100);
      g15.begin(19200);
      delay(100);
      
      while(1)
      {
        g15.setLED(DEFAULT_ID, ON);
        delay(500);
        g15.setLED(DEFAULT_ID, OFF);
        delay(500);
      }
    }
    else // Fail, new ID is different
    {
      g15.end();
      if(baudrateMode < 8) {
        baudrateMode++;
      }
      else {
        while(1)
        {
          digitalWrite(LED, LOW);
          delay(1000);
          digitalWrite(LED, HIGH); 
          delay(1000);
        }
      }
    }
  }
  else // Fail, other error occur
  {
    g15.end();
    if(baudrateMode < 8) {
      baudrateMode++;
    }
    else {
      while(1)
      {
        digitalWrite(LED, LOW); 
        delay(200); 
        digitalWrite(LED, HIGH); 
        delay(200); 
      }
    }
  }
  delay(100);
}