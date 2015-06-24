# FactoryReset() #

## Description ##
This function resets servo's control registers values to factory default. This includes ID and baudrate. Please refer to [G15 User Manual](http://www.cytron.com.my/viewProduct.php?pid=NzgIAyY1NzkGDzITKjMRIYYmFZsFAKCVNg2CEuolxkk=) for more info.

## Include ##
G15.h

## Prototype ##
word FactoryReset(void);

## Parameters ##
none

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer ReturnStatus.

## Example ##
word stat;

stat = servo1.FactoryReset();  //reset servo1 to factory default

## See Also ##
[G15 constructor](http://code.google.com/p/cytron-g15-shield/wiki/G15)

InstructionSet

ReturnStatus