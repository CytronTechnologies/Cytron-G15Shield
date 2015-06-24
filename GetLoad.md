# GetLoad() #

## Description ##
This function retrieve the current load of the servo.


## Include ##
G15.h

## Prototype ##
word GetLoad(byte `*` data);


## Parameters ##
**byte**`*` data : pointer to an array to keep the retrieved data. At least 2 bytes size of array need to be declared first.

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer ReturnStatus.

## Example ##
word stat,load=0;

byte data`[`4`]`;

stat = servo1.GetLoad(data);  //get the current load from servo1

load=data`[`0`]`;

load|=word(data`[`1`]`)<<8;



## See Also ##


ReturnStatus