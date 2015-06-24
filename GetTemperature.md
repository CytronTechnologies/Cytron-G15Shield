# GetTemperature() #

## Description ##
This function retrieve the current temperature of the G15 Cube Servo.


## Include ##
G15.h

## Prototype ##
word GetTemperature(byte `*` data);

## Parameters ##
**byte**`*` data : pointer to an array to keep the retrieved data. At least 2 bytes size of array need to be declared first.

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer ReturnStatus.

## Example ##
word stat,temp=0;

byte data`[`4`]`;

stat = servo1.GetTemperature(data);  //get the current temperature from servo1

temp=data`[`0`]`;



## See Also ##


ReturnStatus