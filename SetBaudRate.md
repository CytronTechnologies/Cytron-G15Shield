# SetBaudRate() #

## Description ##
This function sets the baudrate of a servo.

The user controller will need to reconfigure its serial baudrate too after it has set the servo to new baudrate.

## Include ##
G15.h

## Prototype ##
word SetBaudRate(long bps);

## Parameters ##
**bps**: baud per second (eg: 9600, 38400, 57600, 115200...)

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer ReturnStatus.

## Example ##
word stat;

stat = servo1.SetBaudRate(57600);  //sets servo1 baudrate to 57600

## See Also ##
[G15 constructor](http://code.google.com/p/cytron-g15-shield/wiki/G15)

InstructionSet

ReturnStatus