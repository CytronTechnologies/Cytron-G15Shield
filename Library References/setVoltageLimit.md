# setVoltageLimit() #

## Description ##
This function is to set the operating voltage limit for G15.

## Include ##
Cytron_G15Shield.h

## Prototype ##
```c
uint16_t setVoltageLimit(servoID, uint8_t voltageLow, uint8_t voltageHigh);
```

## Parameters ##
**servoID**: G15's servo ID<br/>
**voltageLow**: 65 to 178<br/>
**voltageHigh**: 65 to 178<br/>
Note: 65 to 178 represent for 6.5V to 17.8V

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer Return Status.

## Example ##
```c
g15.setVoltageLimit(1, 80, 120); // Set voltage limit for G15 with ID number 1, start from 8V to 12V
```