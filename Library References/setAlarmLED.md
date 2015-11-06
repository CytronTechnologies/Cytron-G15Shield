# setAlarmLED() #

## Description ##
This function sets the G15 alarm LED to blink on defined errors.

## Include ##
Cytron_G15Shield.h

## Prototype ##
```c
uint16_t setAlarmLED(servoID, uint8_t alarmLED);
```

## Parameters ##
**servoID**: G15's servo ID<br/>
**alarmLED**: 1 bytes of alarmLED which every bits represent different errors. User can set the alarm LED to blink on several errors by setting the corresponding bit.<br/>
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
g15.setAlarmLED(1, 0x7F); // Set G15 with ID number 1 to alarm LED on all errors
```