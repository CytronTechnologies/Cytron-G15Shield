# SetSpeed() #

## Description ##
This function sets the servo moving speed.

The second parameter is InstructionSet.


## Include ##
G15.h

## Prototype ##
word SetSpeed(word speed, byte inst);

## Parameters ##
**speed**: moving speed (decimal: 0 - 1023; 0 = No torque control max speed)

**inst**: iWRITE\_DATA or iREG\_WRITE

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer ReturnStatus.

## Example ##
word stat;
stat = servo1.SetSpeed(300,iWRITE\_DATA);  //sets servo1's moving speed to 300 immediately.

## See Also ##
[G15 constructor](http://code.google.com/p/cytron-g15-shield/wiki/G15)

InstructionSet

ReturnStatus