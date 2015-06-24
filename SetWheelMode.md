# SetWheelMode() #

## Description ##
This function sets G15 to go into wheel mode which rotate continously in the defined direction.

## Include ##
G15.h

## Prototype ##
word SetWheelMode(void);

## Parameters ##
none

## Returns ##
Error status in word. If return is non-zero, error occurred.

## Example ##
servo1.SetWheelMode();  //set servo 1 into wheel mode


## See Also ##
[G15 constructor](http://code.google.com/p/cytron-g15-shield/wiki/G15)


ExitWheelMode


SetWheelSpeed


ReturnStatus