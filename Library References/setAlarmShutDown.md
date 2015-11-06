# setAlarmShutDown() #

## Description ##
This function sets the G15 to shutdown on defined errors.

## Include ##
Cytron_G15Shield.h

## Prototype ##
```c
uint16_t setAlarmShutDown(servoID, uint8_t alarm);
```

## Parameters ##
**servoID**: G15's servo ID<br/>
**alarm**: 1 bytes of alarm which every bits represent different errors. User can set the alarm LED to blink on several errors by setting the corresponding bit.<br/>
Bit 7: Reserved<br/>
Bit 6: Instruction Error<br/>
Bit 5: Overload Error<br/>
Bit 4: Checksum Error<br/>
Bit 3: Range Error<br/>
Bit 2: Overheating Error<br/>
Bit 1: Angle Limit Error<br/>
Bit 0: Input Voltage Error

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer Return Status.

## Example ##
```c
g15.setAlarmShutDown(1, 0x36); // Set G15 with ID number 1 to shut down on Overload Error, Checksum Error, Overheating Error and Angle Limit Error
```