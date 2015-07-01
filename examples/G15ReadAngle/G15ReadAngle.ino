#include <G15.h>    // include the library
#include <LiquidCrystal.h>
#define LED_BOARD 13

// select the pins used on the LCD panel (RS,EN,DB4,DB5,DB6,DB7)
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
/*Return Error definitions & Mask
=====Higher 8 bits of Word=========
packet length error :       0x0100
packet header error:        0x0200
ID mismatch error:          0x0400
packet checksum mismatch :  0x0800
====Lower 8 bits of word==========
Error status return by G15:
INST			0x0040		
OVERLOAD		0x0020
CHECKSUM		0x0010
RANGE			0x0008
OVERHEAT		0x0004
ANGLELIMIT 	        0x0002
VOLTAGE		        0x0001
*/

//declaration of variables & object
word ERROR=0;
byte DATA[10]; 
word STATUS;

word stat,
     pos1=0,
     angleRead1;

//declare G15 Class Object
//servo1 ID=1
G15 servo1(1); 

void setup(){
  
//initialize the arduino main board's serial/UART and Control Pins
//void G15DriverInit(long baudrate, byte rx, byte tx, char G15_CTRL)
//  G15ShieldInit(19200,0,1,3);       //For SHIELD-G15 Rev1
G15ShieldInit(19200,0,1,2);       //For SHIELD-G15 Rev2 
  
//call the init function to init servo obj
servo1.init();           

//init LED indicator as output
pinMode(LED_BOARD,OUTPUT);  
digitalWrite(LED_BOARD, LOW); 
delay(500); 
digitalWrite(LED_BOARD, HIGH);

lcd.begin(16, 2);
lcd.setCursor(0, 0);
lcd.print(" READ G15 ANGLE ");
  
}



void G15_angleRead(){

  G15 servo1(1);
  servo1.GetPos(DATA); //get the current position from servo1
  pos1=DATA[0];
  pos1 = pos1 | ((DATA[1])<<8);
  angleRead1 =ConvertPos2Angle(pos1);
  lcd.setCursor(0, 1);
  lcd.print(" POSITION: ");
  lcd.setCursor(11, 1);
  lcd.print("   "); 
  lcd.setCursor(11, 1);
  lcd.print((int)angleRead1);
}

void loop(){  
  
    servo1.SetLED(ON,iWRITE_DATA);                     //Turn ON G15 LED
    servo1.SetSpeed(500,iWRITE_DATA);                  //Set G15 speed to 500
    servo1.SetPos(ConvertAngle2Pos(0),iWRITE_DATA);    //goto 0 degree pos 
    G15_angleRead();                                   //Read G15 angle position
    delay(1000);    
    
    servo1.SetLED(OFF,iWRITE_DATA);                    //Turn OFF G15 LED
    servo1.SetSpeed(250,iWRITE_DATA);                  //Set G15 speed to 250 
    servo1.SetPos(ConvertAngle2Pos(90),iWRITE_DATA);   //goto 90 degree pos
    G15_angleRead();                                   //Read G15 angle position
    delay(1000); 
}
