# SetAction() #

## Description ##
This function sets G15 Cube Servo to run the registered/ pending action


## Include ##
G15.h

## Prototype ##
static void SetAction(void);


## Parameters ##
non


## Returns ##
non

## Example ##


servo1.SetPos(ConvertAngle2Pos(0),iREG\_WRITE);    //goto 0 degree pos


servo2.SetPos(ConvertAngle2Pos(0),iREG\_WRITE);    //goto 0 degree pos


servo1.SetLED(ON, iWRITE\_DATA);


servo2.SetLED(ON, iWRITE\_DATA);


delay(1000);


G15::SetAction();


## See Also ##
[G15 constructor](http://code.google.com/p/cytron-g15-shield/wiki/G15)

InstructionSet

ReturnStatus

SetSpeed