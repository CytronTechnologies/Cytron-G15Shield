# SetTemperatureLimit() #

## Description ##
This function sets the operating temperature limit of G15.

## Include ##
G15.h

## Prototype ##
word SetTemperatureLimit(byte Temperature);

## Parameters ##
**Temperature**: 0-120


## Returns ##
Error status in word. If return is non-zero, error occurred. Refer ReturnStatus.

## Example ##
word stat;

stat = servo1.SetTemperatureLimit(80);  //sets G15 to shut down at 80 degree celcius

## See Also ##
[G15 constructor](http://code.google.com/p/cytron-g15-shield/wiki/G15)


ReturnStatus