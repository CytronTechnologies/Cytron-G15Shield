# SetAlarmLED() #

## Description ##
This function sets the G15 alarm LED to blink on defined errors.

## Include ##
G15.h

## Prototype ##
word SetAlarmLED(byte AlarmLED);

## Parameters ##
**AlarmLED**:

Bit 7	Reserved

Bit 6	Instruction Error

Bit 5	Overload Error

Bit 4	Checksum Error

Bit 3	Range Error

Bit 2	Overheating Error

Bit 1	Angle Limit Error

Bit 0	Input Voltage Error


1 bytes of AlarmLED which every bits represent different errors. user set the alarm LED to blink of several errors by setting all the corresponding bit.



## Returns ##
Error status in word. If return is non-zero, error occurred. Refer ReturnStatus.

## Example ##
word stat;

stat = servo1.SetAlarmLED(0x7F);  //sets G15 alarm LED to blink on all errors.

## See Also ##
[G15 constructor](http://code.google.com/p/cytron-g15-shield/wiki/G15)


ReturnStatus