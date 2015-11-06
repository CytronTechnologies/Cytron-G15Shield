# exitWheelMode() #

## Description ##
This function is to exit wheel mode and reset the angle limit to the default value.

## Include ##
Cytron_G15Shield.h

## Prototype ##
```c
uint16_t exitWheelMode(servoID);
```

## Parameters ##
**servoID**: G15's servo ID

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer Return Status.

## Example ##
```c
g15.exitWheelMode(1); // Exit wheel mode for G15 with ID number 1
```