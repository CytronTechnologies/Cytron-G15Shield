# RotateCW() #

## Description ##
This function sets G15 to rotate in clockwise direction to a goal position. The rotation is not limited by the angle limits setting of G15.

## Include ##
G15.h

## Prototype ##
word RotateCW(word Position, byte inst);

## Parameters ##
**position**: goal position (decimal: 0 - 1087)

**inst**: iWRITE\_DATA or iREG\_WRITE

## Returns ##
Error status in word. If return is non-zero, error occurred.

## Example ##
servo1.RotateCW(1050, iWRITE\_DATA);  //command servo1 to move to the position of 1050 in clockwise direction immediately using user defined speed or default speed.

servo1.RotateCW(ConvertAngle2Pos(180), iWRITE\_DATA); //command servo1 to move to angle 180 degree in clockwise direction immediately using the defined speed or default speed.

## See Also ##
[G15 constructor](http://code.google.com/p/cytron-g15-shield/wiki/G15)

InstructionSet

RotateCCW

ReturnStatus

SetSpeed