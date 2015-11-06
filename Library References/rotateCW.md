# rotateCW() #

## Description ##
This function sets G15 to rotate in clockwise direction to a goal position. The rotation is not limited by the angle limits setting of G15.

## Include ##
Cytron_G15Shield.h

## Prototype ##
```c
uint16_t rotateCW(servoID, uint16_t position);
```

## Parameters ##
**servoID**: G15's servo ID<br/>
**position**: Set goal position, start from 0 to 1087.

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer Return Status.

## Example ##
```c
g15.rotateCW(1, 1000); // Command G15 with ID number 1 to rotate to the position of 1000 in clockwise direction
g15.rotateCW(ConvertAngleToPos(180), 1000); // Command G15 with ID number 1 to rotate to the angle of 180 degree in clockwise direction
```