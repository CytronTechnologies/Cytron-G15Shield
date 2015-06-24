# GetSpeed() #

## Description ##
This function retrieve the current speed of the servo.


## Include ##
G15.h

## Prototype ##
word GetSpeed(byte `*` data);


## Parameters ##
**byte**`*` data : pointer to an array to keep the retrieved data. At least 2 bytes size of array need to be declared first.

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer ReturnStatus.

## Example ##
word stat,speed=0;

byte data`[`4`]`;

stat = servo1.GetSpeed(data);  //get the current Speed from servo1

speed=data`[`0`]`;

speed|=word(data`[`1`]`)<<8;



## See Also ##


ReturnStatus