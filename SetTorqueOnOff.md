# SetTorqueOnOff() #

## Description ##
This function turns the servo torque on or off. When turned on, the servo will hold its shaft in position; when turned off the shaft can be freely turned by hand.

If on\_off = 1, torque is on and if on\_off = 0, torque is off.

The second parameter is InstructionSet.


## Include ##
G15.h

## Prototype ##
word SetTorqueOnOff(byte on\_off, byte inst);

## Parameters ##
**on\_off**: on = 1, off = 0

**inst**: iWRITE\_DATA or iREG\_WRITE

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer ReturnStatus.

## Example ##
word stat;

stat = servo1.SetTorqueOnOff(1,iWRITE\_DATA);  //turned on servo1's torque immediately.

## See Also ##
[G15 constructor](http://code.google.com/p/cytron-g15-shield/wiki/G15)

InstructionSet

ReturnStatus