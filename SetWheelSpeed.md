# SetWheelSpeed() #

## Description ##
This function sets the rotation speed of G15 when G15 is in wheel mode.


## Include ##
G15.h

## Prototype ##
word SetWheelSpeed(word Speed, byte CW\_CCW);

## Parameters ##
**Speed**: Rotation speed (0-1023)
**CW\_CCW**: Rotation direction (CW or CCW ; CW is defined as value 1 and CCW is defined as value 0 in G15.h)

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer ReturnStatus.

## Example ##
word stat;

stat = servo1.SetWheelSpeed(100, CW);  //sets servo1 to rotate at a PWM value of 100, and in clockwise direction.

stat = servo1.SetWheelSpeed(255, CCW);  //sets servo1 to rotate at a PWM value of 255, and in counter clockwise direction.

## See Also ##
[G15 constructor](http://code.google.com/p/cytron-g15-shield/wiki/G15)

SetWheelMode


ExitWheelMode


ReturnStatus