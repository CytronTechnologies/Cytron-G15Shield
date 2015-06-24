# GetPos() #

## Description ##
This function retrieve the current position of the servo.
The position is in the range of 0 to 1087.

Use ConvertPos2Angle() macro to convert to angle value in degree. The macro return value in float format.

## Include ##
G15.h

## Prototype ##
word GetPos(byte `*` data);

## Parameters ##
**byte**`*` data : pointer to an array to keep the retrieved data. At least 2 bytes size of array need to be declared first.

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer ReturnStatus.

## Example ##
word stat,pos=0;

byte data`[`4`]`;

stat = servo1.GetPos(data);  //get the current position from servo1

pos=data`[`0`]`;

pos|=word(data`[`1`]`)<<8;

Angle =ConvertPos2Angle(pos);


## See Also ##


ReturnStatus