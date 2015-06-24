# SetAngleLimit() #

## Description ##
This function sets rotation angle limits of G15. This angle limit can limit G15 to do rotation in the angle sector limited the angle limits in normal positioning mode.


## Include ##
G15.h

## Prototype ##
word SetAngleLimit(word CW\_angle, word CCW\_angle);

## Parameters ##
**CW\_angle**: 0-1087

**CCW\_angle**: 0-1087


Please refer G15 user manual for the operation sector when CW angle > CCW angle and also when CCW angle > CW angle

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer ReturnStatus.

## Example ##
word stat;

stat = servo1.SetAngleLimit(100, 256);  //sets rotation angle limits of G15

## See Also ##
[G15 constructor](http://code.google.com/p/cytron-g15-shield/wiki/G15)


ReturnStatus