# RotateCCW() #

## Description ##
This function sets G15 to rotate in counter clockwise direction to a goal position. The rotation is not limited by the angle limits setting of G15.

## Include ##
G15.h

## Prototype ##
word RotateCCW (word Position, byte Write\_Reg);

## Parameters ##
**position**: goal position (decimal: 0 - 1087)

**inst**: iWRITE\_DATA or iREG\_WRITE

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer ReturnStatus for details.

## Example ##
servo1.RotateCCW (1050, iWRITE\_DATA);  //command servo1 to move to the position of 1050 in counter clockwise direction immediately using user defined speed or default speed.

servo1.RotateCCW (ConvertAngle2Pos(180), iWRITE\_DATA); //command servo1 to move to angle 180 degree in counter clockwise direction immediately using the defined speed or default speed.

## See Also ##
[G15 constructor](http://code.google.com/p/cytron-g15-shield/wiki/G15)

InstructionSet

RotateCW

ReturnStatus

SetSpeed