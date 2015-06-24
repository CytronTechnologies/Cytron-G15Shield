# Ping() #

## Description ##
To request the status packet from a particular servo. The data byte is passed by pointer and it will be overwritten with ID of the servo if successful.

## Include ##
G15.h

## Prototype ##
word Ping(byte`*` data);

## Parameters ##
**data**: pass a variable declared as byte by pointer

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer ReturnStatus.

## Example ##
byte dat;

word stat;

stat = servo1.Ping(&dat);  //Ping servo1; if successful, dat contains servo1's ID.

## See Also ##
[G15 constructor](http://code.google.com/p/cytron-g15-shield/wiki/G15)

InstructionSet

ReturnStatus