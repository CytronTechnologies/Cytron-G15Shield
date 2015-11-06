# setTorqueLimit() #

## Description ##
This function is to set torque limit of G15. Torque limit is cleared to zero when overload occurred.

## Include ##
Cytron_G15Shield.h

## Prototype ##
```c
uint16_t setTorqueLimit(servoID, uint16_t torqueLimit);
```

## Parameters ##
**servoID**: G15's servo ID<br/>
**torqueLimit**: 0 to 1023

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer Return Status.

## Example ##
```c
g15.setTorqueLimit(1, 512); // Set G15 with ID number 1 torque limit to half of maximum torque
```