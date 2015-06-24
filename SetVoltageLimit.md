# SetVoltageLimit() #

## Description ##
This function sets the operating voltage limits of G15

## Include ##
G15.h

## Prototype ##
word SetVoltageLimit(byte VoltageLow, byte VoltageHigh);

## Parameters ##
**VoltageLow**: 65-178


**VoltageHigh**: 65-178


65-178 is corresponding to  6.5V to 17.8V


## Returns ##
Error status in word. If return is non-zero, error occurred. Refer ReturnStatus.

## Example ##
word stat;

stat = servo1.SetVoltageLimit(80, 120);  //sets G15 to give error when the voltage is out of range of 8V to 12V

## See Also ##
[G15 constructor](http://code.google.com/p/cytron-g15-shield/wiki/G15)


ReturnStatus