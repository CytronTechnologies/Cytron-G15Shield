# SetPos() #

## Description ##
This function sets the goal position of servo.

The first parameter is goal position in word (decimal: 0 - 1087).

The second parameter is InstructionSet.

## Include ##
G15.h

## Prototype ##
word SetPos(word position, byte inst);

## Parameters ##
**position**: goal position (decimal: 0 - 1087)

**inst**: iWRITE\_DATA or iREG\_WRITE

## Returns ##
Error status in word. If return is non-zero, error occurred.

## Example ##
servo1.SetPos(1050, iWRITE\_DATA);  //command servo1 to move to position 1050 immediately using user defined speed or default speed.

servo1.SetPos(ConvertAngle2Pos(180), iWRITE\_DATA); //command servo1 to move to angle 180 degree immediately using the defined speed or default speed.

## See Also ##
[G15 constructor](http://code.google.com/p/cytron-g15-shield/wiki/G15)

InstructionSet

ReturnStatus

SetSpeed