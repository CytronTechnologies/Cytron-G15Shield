# SetPosSpeed() #

## Description ##
This function sets the goal position of servo and moving speed in one single data packet.

The first parameter is goal position in word (decimal: 0 - 1087).

The Second parameter is moving speed  (decimal: 0 - 1023).

The third parameter is InstructionSet.

## Include ##
G15.h

## Prototype ##
word SetPosSpeed(word Position, word Speed, byte Write\_Reg);

## Parameters ##
**position**: goal position (decimal: 0 - 1087)

**Speed** : moving speed (decimal: 0 - 1023)

**inst**: iWRITE\_DATA or iREG\_WRITE

## Returns ##
Error status in word. If return is non-zero, error occurred.

## Example ##
servo1.SetPosSpeed(1050, 512, iWRITE\_DATA);  //command servo1 to move to position 1050 immediately using moving speed of 512.

servo1.SetPosSpeed(ConvertAngle2Pos(180), 1023, iWRITE\_DATA); //command servo1 to move to angle 180 degree immediately using the moving speed of 1023.

## See Also ##
[G15 constructor](http://code.google.com/p/cytron-g15-shield/wiki/G15)

InstructionSet

ReturnStatus

SetPos

SetSpeed