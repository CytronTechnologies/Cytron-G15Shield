# getSpeed() #

## Description ##
This function retrieve the current speed of the servo.

## Include ##
Cytron_G15Shield.h

## Prototype ##
		uint16_t getSpeed(servoID, uint8_t *data);

## Parameters ##
**servoID**: G15's servo ID<br/>
**data**: Pointer to an array to keep the retrieved data. At least 2 bytes size of array need to be declared first.

## Returns ##
Error status in 2 bytes. If return is non-zero, error occurred. Refer Return Status.

## Example ##
		word status, load = 0;
		byte data[2];
		status = g15.getSpeed(1, data); // Read current speed from G15 with ID number 1
		load = data[0];
		load = load | (word)(data[1] << 8);

## See Also ##
Return Status