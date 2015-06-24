# SetTimetoGoal() #

## Description ##
This function sets G15 to move to goal position in a defined time frame. The actual time to reach the goal position is affected if the power to G15 is inadequate.

This is an alternative way to set the rotation speed of G15 Cube Servo

## Include ##
G15.h

## Prototype ##
word SetTimetoGoal(word Time, byte inst);

## Parameters ##
**Time**: 1-4095 which represents 0.1 seconds to 409.5 seconds.

**inst**: iWRITE\_DATA or iREG\_WRITE

## Returns ##
Error status in word. If return is non-zero, error occurred.

## Example ##
servo1.SetTimetoGoal(200, iWRITE\_DATA);  //set the time to goal position  to 20 seconds.


## See Also ##
[G15 constructor](http://code.google.com/p/cytron-g15-shield/wiki/G15)

InstructionSet


SetSpeed


ReturnStatus