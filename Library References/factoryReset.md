# factoryReset() #

## Description ##
This function resets servo's control registers values to factory default. This includes ID and baudrate. Please refer to G15 User Manual for more info.

## Include ##
Cytron_G15Shield.h

## Prototype ##
		uint16_t factoryReset(servoID);

## Parameters ##
**servoID**: G15's servo ID

## Returns ##
Error status in 2 bytes. If return is non-zero, error occurred. Refer Return Status.

## Example ##
		g15.factoryReset(1); // Factory reset for G15 with ID number 1
