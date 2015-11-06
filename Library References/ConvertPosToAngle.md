# ConvertPosToAngle() #

## Description ##
This is a macro which convert the position value of 0 to 1087 to angle values in degree. The return value is in floating point format.

## Include ##
Cytron_G15Shield.h

## Prototype ##
```c
ConvertPosToAngle(position);
```

## Parameters ##
**position**: Angle position value, 0 to 1087

## Returns ##
Angle position value, 0 to 359

## Example ##
```c
word position;
position = ConvertPosToAngle(1000); // Convert position to angle value
```