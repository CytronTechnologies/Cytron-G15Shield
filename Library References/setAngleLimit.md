# setAngleLimit() #

## Description ##
This function sets rotation angle limits of G15. This angle limit can limit G15 to do rotation in the angle sector limited the angle limits in normal positioning mode.

## Include ##
Cytron_G15Shield.h

## Prototype ##
```c
uint16_t setAngleLimit(servoID, uint16_t cwAngle, uint16_t ccwAngle);
```

## Parameters ##
**servoID**: G15's servo ID<br/>
**cwAngle**: 0 to 1087<br/>
**ccwAngle**: 0 to 1087<br/>
Note: Please refer G15 user manual for the operation sector when CW angle > CCW angle and also when CCW angle > CW angle

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer Return Status.

## Example ##
```c
g15.setAngleLimit(1, 100, 256); // Set rotation angle limit of G15 with ID number 1
```