# ConvertAngle2Pos() #

## Description ##
This is a macro which convert the **angle** value of 0 to 359 to position value of 0 to 1087.  The return value is in word data format.

## Include ##
G15.h

## Prototype ##
ConvertAngle2Pos(Angle)

## Parameters ##
**Angle**: Position value from 0 to 359

## Returns ##
The position value(0-1087).

## Example ##
word pos;

pos= ConvertAngle2Pos(90);


## See Also ##
http://code.google.com/p/cytron-g15-shield/wiki/ConvertPos2Angle

http://code.google.com/p/cytron-g15-shield/wiki/SetPos