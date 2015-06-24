# Instruction Set Table #

## Description ##
|Macro|Instruction|Description|Remark|
|:----|:----------|:----------|:-----|
|iPING|0x01       |Used to obtain a status packet|Handled in function|
|iREAD\_DATA|0x02       |Read values from Control Register|Handled in function|
|iWRITE\_DATA|0x03       |Write values to Control Register|Pass to function|
|iREG\_WRITE|0x04       |Similar to WRITE\_DATA instruction but pending execution until iACTION Instruction is called|Pass to function|
|iACTION|0x05       |Triggers the pending action registered by REG\_WRITE instruction|Handled in function|
|iRESET|0x06       |Resetting the Control Register values to factory defaults|Handled in function|
|iSYNC\_WRITE|0x83       |Controlling multiple G15 in one single instruction packet|User program|

Pass a Macro to related function to initiate desired action.

## Example ##
servo1.SetPos(1050,iWRITE\_DATA); //this line commands the servo to move to position 1050 immediately.

servo1.SetPos(ConvertAngle2Pos(0),iREG\_WRITE); //goto 0 degree pos after action instruction called

G15::SetAction();