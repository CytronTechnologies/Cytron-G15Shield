# SetTorqueLimit() #

## Description ##
This function sets torque limit of G15.
Torque limit is cleared to zero when overload occurred.


## Include ##
G15.h


## Prototype ##
word SetTorqueLimit(word TorqueLimit);


## Parameters ##
**TorqueLimit**: 0-1023


## Returns ##
Error status in word. If return is non-zero, error occurred. Refer ReturnStatus.


## Example ##
word stat;

stat = servo1.SetTorqueLimit(512);  //sets torque limit to half of max torque.


## See Also ##
[G15 constructor](http://code.google.com/p/cytron-g15-shield/wiki/G15)


ReturnStatus