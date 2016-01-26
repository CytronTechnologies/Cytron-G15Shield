/*
Original written by:
            Ing Hui, Cytron Technologies

Modified:
            Zamzuri, Cytron Technologies	- Fix SoftwareSerial bugs
  29/06/15  Idris, Cytron Technologies    - Point to IDE SoftwareSerial
                                          - Restructure the code style to follow standard Arduino library
*/

//#include "HardwareSerial.h"
#include "Cytron_G15Shield.h"

boolean hardwareSerial;
SoftwareSerial* G15Serial;

// This Code is using Serial library
// baudrate 300, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 38400, 57600, or 115200

Cytron_G15Shield::Cytron_G15Shield(uint8_t rxpin, uint8_t txpin, uint8_t ctrlpin)
{
  _rxpin = rxpin;
  _txpin = txpin;
  _ctrlpin = ctrlpin;
}

Cytron_G15Shield::Cytron_G15Shield(uint8_t ctrlpin)
{
	_rxpin = 0;
  _txpin = 1;
  _ctrlpin = ctrlpin;
}

void Cytron_G15Shield::begin(uint32_t baudrate)
{
  if(_rxpin == 0 &&_txpin == 1)
  {
    hardwareSerial = true;
    Serial.begin(baudrate);
    while (!Serial);
    Serial.setTimeout(SerialTimeOut);
  }
  else
  {
    hardwareSerial = false;
    pinMode(_rxpin, INPUT);
    pinMode(_txpin, OUTPUT);
    G15Serial = new SoftwareSerial(_rxpin, _txpin);
    G15Serial->begin(baudrate);
    G15Serial->setTimeout(SerialTimeOut);
  }
  pinMode(_ctrlpin, OUTPUT);
  setTxMode();
}

void Cytron_G15Shield::end(void)
{
  if(_rxpin == 0 &&_txpin == 1)
  {
    Serial.end();
  }
  else
  {
    pinMode(_rxpin, INPUT);
    pinMode(_txpin, INPUT);
    G15Serial->end();
  }
  pinMode(_ctrlpin, INPUT);
}

void Cytron_G15Shield::setTxMode(void)
{
	digitalWrite(_ctrlpin, TxMode); 
}

void Cytron_G15Shield::setRxMode(void)
{
  digitalWrite(_ctrlpin, RxMode); 
}

// Send packet
// Caution: At least 2 bytes of data array need to be passed into the function 
uint16_t Cytron_G15Shield::sendPacket(uint8_t servoID, uint8_t instruction, uint8_t* data, uint8_t parameterLength)	
{
	uint8_t readCount = 0;
	uint8_t i;
  uint8_t packetLength = 0;
  uint8_t txBuffer[16];
  uint8_t status[16];
	uint8_t checksum = 0; // Checksum = ~(ID + Length + Instruction + Parameter1 + ... + Parameter n)
	uint16_t error = 0;
	
	setTxMode();
	
  txBuffer[0] = 0xFF; // Header is 0xFF
  txBuffer[1] = 0xFF; // Header is not included in checksum
  txBuffer[2] = servoID;              checksum += txBuffer[2]; // 0-254, 0xFE = broadcast id
  txBuffer[3] = parameterLength + 2;	checksum += txBuffer[3]; // Instruction + parameters (start add + values) + checksum                                                                                                        //0xFF and ID not included
  txBuffer[4] = instruction;          checksum += txBuffer[4];	

  for(i = 0; i < parameterLength; i++)
  {
		txBuffer[i + 5] = data[i];
		checksum += txBuffer[i + 5];
  }
  txBuffer[i+5] = ~checksum;

  packetLength = txBuffer[3] + 4; // Number of bytes for the whole packet

	if(hardwareSerial == true)
	{
		for(i = 0; i < packetLength; i++) {
			Serial.write(txBuffer[i]);
		}
		Serial.flush();
	}
	else
	{
		G15Serial->listen();
		for(i = 0; i < packetLength; i++) {
			G15Serial->write(txBuffer[i]);
		}
		G15Serial->flush();
	}
	
  // G15 only response if it was not broadcast command
  if((ID != 0xFE) || (instruction == iPING))
	{
    if(instruction == iREAD_DATA)
		{
			parameterLength = data[1]; 
      packetLength = data[1] + 6;
		}
    else {
      packetLength = 6;
		}

		setRxMode();

		if(hardwareSerial == true) {
			readCount = Serial.readBytes(status, packetLength); 
    }
		else {
			readCount = G15Serial->readBytes(status, packetLength); 
    }
		
		setTxMode();
		
		error = 0;
		if(readCount != packetLength) {
			error |= 0x0100;
		}
		if((status[0] != 0xFF) || (status[1] != 0xFF)) {
			error |= 0x0200;
		}
		if(status[2] != servoID) {
			error |= 0x0400;
		}
		if(status[4] != 0) {
			error |= status[4];
		}

		// Calculate checksum
		checksum = 0;
    for(i = 2; i < packetLength; i++) {
      checksum += status[i];
    }
    if(checksum != 0xFF) {
      error |= 0x0800;
    }
		if(status[4] == 0x00 && (error & 0x0100) == 0x00)	// Copy data only if there is no packet error
		{
			if(instruction == iPING) {
				data[0] = status[2];
			} 
			else if(instruction == iREAD_DATA)
			{
				for(i = 0; i < parameterLength; i++) {
					data[i] = status[i + 5];
        }
			}
		}
  }
  return(error);
}

uint16_t Cytron_G15Shield::setWheelMode(uint8_t servoID)
{		
	uint16_t error = 0; 
	error = setAngleLimit(servoID, 0, 0); // Enable wheel mode
	if(error != 0) {
    return(error);
  }
	
	error = setTorqueOnOff(servoID, ON); // Enable torque
	
	return(error);
}

uint16_t Cytron_G15Shield::exitWheelMode(uint8_t servoID)
{
	return(setAngleLimit(servoID, 0, 1087)); // Reset to default angle limit
}

uint16_t Cytron_G15Shield::setWheelSpeed(uint8_t servoID, uint16_t speed, uint8_t direction)
{
	speed = speed & 0x03FF; // Eliminate bits which are non speed
	if(direction == CW) {
		speed = speed | 0x0400; 
	}
	return(setSpeed(servoID, speed));
}

//******************************************************************
//*	SET GOAL POSITION
//* 	eg:	dat[0] = 0xC8;				// Position lower byte
//*			dat[1] = 0x00;				// Position upper byte
//*			SetPos(dat,iWRITE_DATA);	// Send to servo 2 & action!
//******************************************************************
uint16_t Cytron_G15Shield::setPos(uint8_t servoID, uint16_t position)
{
	uint8_t txBuffer[3];	
	
  txBuffer[0] = GOAL_POSITION_L; // Control Starting Address
	txBuffer[1] = position & 0x00FF; // Goal pos bottom 8 bits
  txBuffer[2] = position >> 8; // Goal pos top 8 bits
	
	return(sendPacket(servoID, iWRITE_DATA, txBuffer, 3));
}

uint16_t Cytron_G15Shield::setPosAngle(uint8_t servoID, uint16_t angle)
{
	uint8_t txBuffer[3];	
	uint16_t position = ConvertAngleToPos(angle);

  txBuffer[0] = GOAL_POSITION_L; // Control Starting Address
	txBuffer[1] = position & 0x00FF; // Goal pos bottom 8 bits
  txBuffer[2] = position >> 8; // Goal pos top 8 bits
	
	return(sendPacket(servoID, iWRITE_DATA, txBuffer, 3));
}

uint16_t Cytron_G15Shield::setPosSpeed(uint8_t servoID, uint16_t position, uint16_t speed)
{
	uint8_t txBuffer[5];	
	
  txBuffer[0] = GOAL_POSITION_L; // Control Starting Address
	txBuffer[1] = position & 0x00FF; // Goal pos bottom 8 bits
  txBuffer[2] = position >> 8; // Goal pos top 8 bits
	txBuffer[3] = speed & 0x00FF; // Speed bottom 8 bits
  txBuffer[4] = speed >> 8; // Speed top 8 bits

	return(sendPacket(servoID, iWRITE_DATA, txBuffer, 5));
}

uint16_t Cytron_G15Shield::rotateCW(uint8_t servoID, uint16_t position)
{
	position = position | 0xC000;

	return(setPos(servoID, position));
}

uint16_t Cytron_G15Shield::rotateCCW(uint8_t servoID, uint16_t position)
{
	position = position | 0x8000;
	position = position & 0xBFFF;
	
	return(setPos(servoID, position));
}

//******************************************************************
//*	SET TORQUE ON OFF
//* 	eg:	SetTorqueOnOff(1,iREG_WRITE);	// Turn on torque of servo 2
//******************************************************************
uint16_t Cytron_G15Shield::setTorqueOnOff(uint8_t servoID, uint8_t onOff)
{
	uint8_t txBuffer[2];

  txBuffer[0] = TORQUE_ENABLE;
	txBuffer[1] = onOff; // ON = 1, OFF = 0

  return(sendPacket(servoID, iWRITE_DATA, txBuffer, 2));
}
//******************************************************************
//*	SET SPEED
//* 	eg:	dat[0] = 0x0A;				// Speed lower byte
//*			dat[1] = 0x02;				// Speed upper byte
//*			SetSpeed(dat,iREG_WRITE);	// Save data in servo 2 register &
//*										// wait for action command
//******************************************************************
uint16_t Cytron_G15Shield::setSpeed(uint8_t servoID, uint16_t speed)
{
	uint8_t txBuffer[3];

  txBuffer[0] = MOVING_SPEED_L;
	txBuffer[1] = speed & 0x00FF; // Speed bottom 8 bits
  txBuffer[2] = speed >> 8; // Speed top 8 bits
	
  return(sendPacket(servoID, iWRITE_DATA, txBuffer, 3));
} 

//********************************************************************
uint16_t Cytron_G15Shield::setTimeToGoal(uint8_t servoID, uint16_t time)
{
	time = time & 0x0FFF;
	time = time | 0x8000; // Bit 15 represents the time to goal pos mode
	
	return(setSpeed(servoID, time)); 
}


//******************************************************************
//*	SET ANGLE LIMIT
//* byte SetAngleLimit(word CW_angle, word CCW_angle)	
//*	CW_angle & CCW_angle are not in degree value
//*	Use ConverAngle to convert angle values if needed		
//*	
//*		
//******************************************************************
uint16_t Cytron_G15Shield::setAngleLimit(uint8_t servoID, uint16_t CW_angle, uint16_t CCW_angle)
{
	uint8_t txBuffer[5];
	uint16_t error; 

  txBuffer[0] = CW_ANGLE_LIMIT_L;
	txBuffer[1] = CW_angle & 0x00FF; // CW limit bottom 8 bits
  txBuffer[2] = CW_angle >> 8; // CW limit top 8 bits
	txBuffer[3] = CCW_angle & 0x00FF; // CCW limit bottom 8 bits
	txBuffer[4] = CCW_angle >> 8; // CCW limit top 8 bits

	error = sendPacket(servoID, iWRITE_DATA, txBuffer, 5); 
	delay(10); // Delay for eeprom write
  return(error);
}

uint16_t Cytron_G15Shield::setTorqueLimit(uint8_t servoID, uint16_t TorqueLimit)
{
	uint8_t txBuffer[3];

  txBuffer[0] = TORQUE_LIMIT_L;
	txBuffer[1] = TorqueLimit & 0x00FF; // Torque limit bottom 8 bits
  txBuffer[2] = TorqueLimit >> 8; // Torque limit top 8 bits

  return(sendPacket(servoID, iWRITE_DATA, txBuffer, 3));
}

uint16_t Cytron_G15Shield::setTemperatureLimit(uint8_t servoID, uint8_t temperature)
{
	uint8_t txBuffer[2];
	uint16_t error;

  txBuffer[0] = LIMIT_TEMPERATURE;			//Starting Address
	txBuffer[1] = temperature;  				//temperature

	error = sendPacket(servoID, iWRITE_DATA, txBuffer, 2);
	delay(10); // Delay for eeprom write
  return(error);
}

uint16_t Cytron_G15Shield::setVoltageLimit(uint8_t servoID, uint8_t voltageLow, uint8_t voltageHigh)
{
	uint8_t txBuffer[3];
	uint16_t error; 

  txBuffer[0] = DOWN_LIMIT_VOLTAGE;
	txBuffer[1] = voltageLow; // Lower voltage limit 
  txBuffer[2] = voltageHigh; // Higher voltage limit 

	error=sendPacket(servoID, iWRITE_DATA, txBuffer, 3);
	delay(10); // Delay for eeprom write
  return(error);
}

//******************************************************************
//*	SET ID
//* 	eg:	SetID(MAIN,0xFE,3);	// Change the ID of any number to 3
//******************************************************************
uint16_t Cytron_G15Shield::setID(uint8_t servoID, uint8_t newID)
{
  uint8_t txBuffer[2];
	uint16_t error; 
	
  txBuffer[0] = ID;
	txBuffer[1] = newID;	
	
	error = sendPacket(servoID, iWRITE_DATA, txBuffer, 2);
	delay(10); // Delay for eeprom write
  return(error);
}	

//******************************************************************
//*	SET LED
//* 	eg:	SetLED(1,iWRITE_DATA);	// Turn on LED of servo 2
//******************************************************************
uint16_t Cytron_G15Shield::setLED(uint8_t servoID, uint8_t onOff)
{
	uint8_t txBuffer[2];

  txBuffer[0] = LED; // Control Starting Address
	txBuffer[1] = onOff; // ON = 1, OFF = 0

  return(sendPacket(servoID, iWRITE_DATA, txBuffer, 2));
}

uint16_t Cytron_G15Shield::setAlarmLED(uint8_t servoID, uint8_t alarmLED)
{
	uint8_t alarmValue = 0x00; 	
	uint8_t txBuffer[2];
	uint16_t error; 
	
	alarmValue = alarmValue | alarmLED; 

  txBuffer[0] = ALARM_LED;
	txBuffer[1] = alarmValue; // Alarm value
   
	error = sendPacket(servoID, iWRITE_DATA, txBuffer, 2); 
	delay(10);
  return(error);
}

uint16_t Cytron_G15Shield::setAlarmShutDown(uint8_t servoID, uint8_t alarm)
{
	uint8_t alarmValue = 0x00; 	
	uint8_t txBuffer[2];
	uint16_t error; 
	
	alarmValue = alarmValue | alarm; 

  txBuffer[0] = ALARM_SHUTDOWN; // Control Starting Address
	txBuffer[1] = alarmValue; // Alarm
  
  error = sendPacket(servoID, iWRITE_DATA, txBuffer, 2); 
  delay(10); // Delay for eeprom write
  return(error);
}

uint16_t Cytron_G15Shield::setMarginSlopePunch(uint8_t servoID, uint8_t CWMargin, uint8_t CCWMargin, uint8_t CWSlope, uint8_t CCWSlope, uint16_t punch)
{
	uint8_t txBuffer[5];	
	uint16_t error = 0; 

  txBuffer[0] = CW_COMPLIANCE_MARGIN;		//Control Starting Address
	txBuffer[1] = CWMargin;	
	txBuffer[2] = CCWMargin; 
	txBuffer[3] = CWSlope; 
	txBuffer[4] = CCWSlope; 
	
  error = sendPacket(servoID, iWRITE_DATA, txBuffer, 5);

	if(error != 0) {
		return(error); 
  }
	
	txBuffer[0] = PUNCH_L;				//Control Starting Address
	txBuffer[1] = punch & 0x00FF;		//punch Lower 8 bits
	txBuffer[2] = punch >> 8; 		//punch Higher 8 bits
	
  error = sendPacket(servoID, iWRITE_DATA, txBuffer, 3);
	
	return(error); 
}

//******************************************************************
//*	SET BAUDRATE
//* 	eg:	SetBaud(1,2,1);	// Turn on torque of servo 2
//******************************************************************
uint16_t Cytron_G15Shield::setBaudRate(uint8_t servoID, uint32_t baudrate)
{
	uint8_t txBuffer[2];
	uint16_t error; 
	
  txBuffer[0] = BAUD_RATE;
	txBuffer[1] = (2000000 / baudrate) - 1;	// Baudrate = 32M / (16*(n + 1)) = 2000000 / (n+1)
									
	error = sendPacket(servoID, iWRITE_DATA, txBuffer, 2); 
	delay(10); // Delay for eeprom write
  return(error);
}

//******************************************************************
//*	RESET TO FACTORY SETTINGS
//* 	eg:	FactoryReset(1,1);// Reset servo 1
//******************************************************************
uint16_t Cytron_G15Shield::factoryReset(uint8_t servoID)
{
	uint8_t txBuffer[1]; // Dummy byte
	uint16_t error; 
	
	error = sendPacket(servoID, iRESET, txBuffer, 0);
	delay(100); // Delay for eeprom write
  return(error);
}
//******************************************************************
//*	PING
//* 	eg:	Ping(MAIN,1,dat);	// Ping servo 1, dat is array's pointer
//******************************************************************
uint16_t Cytron_G15Shield::ping(uint8_t servoID, uint8_t *data)
{
  return(sendPacket(servoID, iPING, data, 0));
}

//******************************************************************
//*	GET CURRENT POSITION
//******************************************************************
uint16_t Cytron_G15Shield::getPos(uint8_t servoID, uint8_t *data)		
{
  data[0] = PRESENT_POSITION_L;	// Starting address where data to be read
  data[1] = 0x02; // No of bytes to be read
  
  return(sendPacket(servoID, iREAD_DATA, data, 2));
}

uint16_t Cytron_G15Shield::getSpeed(uint8_t servoID, uint8_t *data)
{	
  data[0] = PRESENT_SPEED_L; // Starting address where data to be read
  data[1] = 0x02; // No of bytes to be read
    
  return(sendPacket(servoID, iREAD_DATA, data, 2));
}

uint16_t Cytron_G15Shield::getLoad(uint8_t servoID, uint8_t *data)
{
  data[0] = PRESENT_LOAD_L; // Starting address where data to be read
  data[1] = 0x02; // No of bytes to be read
    
  return(sendPacket(servoID, iREAD_DATA, data, 2));
}

uint16_t Cytron_G15Shield::getVoltage(uint8_t servoID, uint8_t *data)
{
	data[0] = PRESENT_VOLTAGE; // Starting address where data to be read
  data[1] = 0x01; // No of bytes to be read
    
  return(sendPacket(servoID, iREAD_DATA, data, 2));
}

uint16_t Cytron_G15Shield::getTemperature(uint8_t servoID, uint8_t *data)
{
	data[0] = PRESENT_TEMPERATURE; // Starting address where data to be read
  data[1] = 0x01; // No of bytes to be read
    
  return(sendPacket(servoID, iREAD_DATA, data, 2));
}

//******************************************************************
//*	GET TORQUE (ON/OFF?)
//******************************************************************
uint16_t Cytron_G15Shield::getTorqueOnOff(uint8_t servoID, uint8_t *data)
{
  data[0] = TORQUE_ENABLE; // Starting address where data to be read
  data[1] = 0x01; // No of bytes to be read

  return(sendPacket(servoID, iREAD_DATA, data, 2));
}

//******************************************************************
//*	IS MOTOR MOVING?
//******************************************************************
uint16_t Cytron_G15Shield::isMoving(uint8_t servoID, uint8_t *data)
{
  data[0] = MOVING; // Starting address where data to be read
  data[1] = 0x01; // No of bytes to be read
    
	return(sendPacket(servoID, iREAD_DATA, data, 2));
}



//******************************************************************
//*	SET ACTION
//* 	eg:	SetAction(1);	// All servo action!
//******************************************************************
/*void Cytron_G15Shield::setAction(void)
{	
	 // byte TxBuff[1];	//dummy byte
	 // sendPacket(0xFE, iACTION, TxBuff, 0);	
	set_act(_ctrlpin); 
}

void set_act(uint8_t ctrl){

	int i; 
	byte packet_len = 0;
    byte TxBuff[16];
    byte chksum = 0;	//Check Sum = ~ (ID + Length + Instruction + Parameter1 + ... Parameter N)
 
	digitalWrite(ctrl,TxMode); 

    TxBuff[0] = 0xFF;			//0xFF not included in checksum
    TxBuff[1] = 0xFF;
    TxBuff[2] = 0xFE; 			chksum += TxBuff[2];	//0-254, 0xFE = broadcast id
    TxBuff[3] =  2;	chksum += TxBuff[3];	//INSTRUCTION + PARAMETERS( START ADDR + VALUES ) + CHECKSUM
                                                                                                            //0xFF and ID not included
    TxBuff[4] = iACTION;			chksum += TxBuff[4];	//

    TxBuff[5] = ~chksum; 				//Checksum with Bit Inversion

    packet_len = TxBuff[3] + 4;			//# of bytes for the whole packet
    
	if(hardwareSerial==true)
	{
		for(i=0; i<packet_len;i++){
			Serial.write(TxBuff[i]);
		}
		Serial.flush();
	}
	else
	{
		for(i=0; i<packet_len;i++){
			G15Serial->write(TxBuff[i]);
		}
		G15Serial->flush();	
	}
}*/
