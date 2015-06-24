# SetAlarmShutDown() #

## Description ##
This function sets the G15 alarm LED to blink on defined errors.

## Include ##
G15.h

## Prototype ##
word SetAlarmShutDown(byte Alarm);

## Parameters ##
**Alarm**:

Bit 7	Reserved

Bit 6	Instruction Error

Bit 5	Overload Error

Bit 4	Checksum Error

Bit 3	Range Error

Bit 2	Overheating Error

Bit 1	Angle Limit Error

Bit 0	Input Voltage Error


1 bytes of Alarm which every bits represent different errors. User can set several Alarm bits to set G15 to shutdown on the corresponding errors.



## Returns ##
Error status in word. If return is non-zero, error occurred. Refer ReturnStatus.

## Example ##
word stat;

stat = servo1.SetAlarmShutDown(0x36);  //sets G15 to shut down on Overload Error, Checksum Error, Overheating Error and Angle Limit Error

## See Also ##
[G15 constructor](http://code.google.com/p/cytron-g15-shield/wiki/G15)


ReturnStatus