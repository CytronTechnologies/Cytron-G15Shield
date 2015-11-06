# ping() #

## Description ##
To request the status packet from a particular servo. The data byte is passed by pointer and it will be overwritten with ID of the servo if successful.

## Include ##
Cytron_G15Shield.h

## Prototype ##
```c
uint16_t ping(servoID, uint8_t *data);
```

## Parameters ##
**servoID**: G15's servo ID<br/>
**data**: Pointer to an array to keep the retrieved data. At least 2 bytes size of array need to be declared first.

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer Return Status.

## Example ##
```c
word status;
byte data[2];
status = g15.ping(1, data); // Ping G15 with ID number 1, if succeed correct ID number will be stored in data
```

## See Also ##
Return Status