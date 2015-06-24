# IsMoving() #

## Description ##
This function reads whether G15 Cube Servo has reached its goal position or still moving.


## Include ##
G15.h

## Prototype ##
word IsMoving(byte `*` data);

## Parameters ##
**byte**`*` data : pointer to an array to keep the retrieved data. At least 2 bytes size of array need to be declared first.

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer ReturnStatus.

## Example ##
word stat,mov=0;

byte data`[`4`]`;

stat = servo1.IsMoving(data);  //get the current moving status from servo1

mov=data`[`0`]`;



## See Also ##


ReturnStatus