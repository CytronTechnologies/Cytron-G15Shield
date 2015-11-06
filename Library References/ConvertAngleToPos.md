# ConvertAngleToPos() #

## Description ##
This is a macro which convert the angle value of 0 to 359 to position value of 0 to 1087. The return value is in word data format.

## Include ##
Cytron_G15Shield.h

## Prototype ##
```c
ConvertAngleToPos(angle);
```

## Parameters ##
**angle**: Angle position value, 0 to 359

## Returns ##
Position value, 0 to 1087

## Example ##
```c
word position;
position = ConvertAngleToPos(90); // Convert angle to position value
```