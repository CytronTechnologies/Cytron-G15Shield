# GetVoltage() #

## Description ##
This function retrieve the current voltage of the servo.


## Include ##
G15.h

## Prototype ##
word GetVoltage(byte `*` data);

## Parameters ##
**byte**`*` data : pointer to an array to keep the retrieved data. At least 2 bytes size of array need to be declared first.

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer ReturnStatus.

## Example ##
word stat,voltage=0;

byte data`[`4`]`;

stat = servo1.GetVoltage(data);  //get the current voltage from servo1

voltage=data`[`0`]`;



## See Also ##


ReturnStatus