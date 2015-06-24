# Return Status #

## Parameter Type Definition ##
word (2 bytes)

## Description ##
This return status word consists of return packet error byte and servo returned error byte.

Return Packet Error (higher byte; bit 15 - 8)

Servo Returned Error (lower byte; bit 7 - 0)

|Bit|<Return Packet Error>|
|:--|:--------------------|
|15 |--                   |
|14 |--                   |
|13 |--                   |
|12 |--                   |
|11 |Checksum error       |
|10 |ID mismatch          |
|9  |Wrong header         |
|8  |Packet lost or receive time out|
|   | |
|Bit|<Servo Returned Error>|
|7  |--                   |
|6  |Instruction error    |
|5  |Overload error       |
|4  |Checksum error       |
|3  |Range error          |
|2  |Overheating error    |
|1  |Angle limit error    |
|0  |Input voltage error  |

For Servo Returned Error, please refer to [G15 User Manual](http://www.cytron.com.my/viewProduct.php?pid=NzgIAyY1NzkGDzITKjMRIYYmFZsFAKCVNg2CEuolxkk=) for more info.