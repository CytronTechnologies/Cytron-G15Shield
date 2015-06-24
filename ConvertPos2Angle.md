# ConvertPos2Angle() #

## Description ##
This is a macro which convert the position value of 0 to 1087 to angle values in degree. The return value is in floating point format.

## Include ##
G15.h

## Prototype ##
ConvertPos2Angle(Pos)

## Parameters ##
**Pos**: Position value from 0 to 1087

## Returns ##
The position value in degree (0-359)

## Example ##
word Angle;

Angle = ConvertPos2Angle(270);


## See Also ##
http://code.google.com/p/cytron-g15-shield/wiki/GetPos