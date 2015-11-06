# setTemperatureLimit() #

## Description ##
This function is to set the G15's temperature limit to automatic shutdown.

## Include ##
Cytron_G15Shield.h

## Prototype ##
```c
uint16_t setTemperatureLimit(servoID, uint8_t temperature);
```

## Parameters ##
**servoID**: G15's servo ID<br/>
**temperature**: G15's temperature limit, starts from 0 to 120 degree celcius

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer Return Status.

## Example ##
```c
g15.setTemperatureLimit(1, 100); // Set G15 with ID number 1 with temperature limit 100 degree celcius
```