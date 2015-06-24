# ExitWheelMode() #

## Description ##
This function is to exit wheel mode and reset the angle limit to the default value.

## Include ##
G15.h

## Prototype ##
word ExitWheelMode(void);

## Parameters ##
non

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer ReturnStatus.

## Example ##
word stat;

stat = servo1.ExitWheelMode();  //servo1 exit wheel mode

## See Also ##
[G15 constructor](http://code.google.com/p/cytron-g15-shield/wiki/G15)


SetWheelMode


SetWheelSpeed


ReturnStatus