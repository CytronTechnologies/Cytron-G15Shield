# init() #

## Description ##
This function will initialize the digital pin used as control pin in serial communication. It must be called before start sending communication packets to servo (G15 or AX12).

## Include ##
G15.h

## Prototype ##
init(void);

## Parameters ##
none

## Returns ##
None

## Example ##
servo1.init();
//initialize the digital pin used as servo1 control pin in serial communication. The digital pin is to be set in G15ShieldInit() function.

## See Also ##
G15ShieldInit()