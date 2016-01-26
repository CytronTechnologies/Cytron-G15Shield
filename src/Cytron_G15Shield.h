/*
Original written by:
            Ing Hui, Cytron Technologies

Modified:
            Zamzuri, Cytron Technologies	- Fix SoftwareSerial bugs
  29/06/15  Idris, Cytron Technologies    - Point to IDE SoftwareSerial
                                          - Restructure the code style to follow standard Arduino library
*/

#ifndef Cytron_G15Shield_h
#define Cytron_G15Shield_h

#include "Arduino.h"
#include <SoftwareSerial.h>

// Arduino Leonardo
#if defined (__AVR_ATmega32U4__)
	#define Serial Serial1
#else
	#define Serial Serial
#endif

// definitions
//******************************************************************
//*	INSTRUCTIONS
//******************************************************************
#define iPING 			0x01 // Obtain a status packet
#define iREAD_DATA	0x02 // Read Control Table values
#define iWRITE_DATA	0x03 // Write Control Table values
#define iREG_WRITE 	0x04 // Write and wait for ACTION instruction
#define iACTION 		0x05 // Triggers REG_WRITE instruction
#define iRESET 			0x06 // Set factory defaults
#define iSYNC_WRITE	0x83 // Simultaneously control multiple actuators

#define SerialTimeOut 100L 
#define TxMode LOW  	// Master transmit to G15
#define RxMode HIGH		// Master receive from G15
#define ConvertAngleToPos(angle)		(uint16_t)((uint16_t)(angle) * 1088UL / 360UL)
#define ConvertPosToAngle(position) (float)((position) * 360.0 / 1088.0)
#define ConvertTime(time)						(uint16_t)(time * 10UL)
#define CW 	1
#define CCW 0
#define ON 	1
#define OFF 0

#define ALARM_INST				0x40		
#define ALARM_OVERLOAD		0x20
#define ALARM_CHECKSUM		0x10
#define ALARM_RANGE				0x08
#define ALARM_OVERHEAT		0x04
#define ALARM_ANGLELIMIT	0x02
#define ALARM_VOLTAGE			0x01

enum {
	MODEL_NUMBER_L,					// 0x00
	MODEL_NUMBER_H, 				// 0x01
	VERSION, 								// 0x02
	ID, 										// 0x03
	BAUD_RATE, 							// 0x04
	RETURN_DELAY_TIME, 			// 0x05
	CW_ANGLE_LIMIT_L, 			// 0x06
	CW_ANGLE_LIMIT_H, 			// 0x07
	CCW_ANGLE_LIMIT_L, 			// 0x08
	CCW_ANGLE_LIMIT_H, 			// 0x09
	RESERVED1, 							// 0x0A
	LIMIT_TEMPERATURE, 			// 0x0B
	DOWN_LIMIT_VOLTAGE, 		// 0x0C
	UP_LIMIT_VOLTAGE, 			// 0x0D
	MAX_TORQUE_L, 					// 0x0E
	MAX_TORQUE_H, 					// 0x0F
	STATUS_RETURN_LEVEL, 		// 0x10	
	ALARM_LED, 							// 0x11
	ALARM_SHUTDOWN, 				// 0x12
	RESERVED2, 							// 0x13
	DOWN_CALIBRATION_L, 		// 0x14
	DOWN_CALIBRATION_H, 		// 0x15
	UP_CALIBRATION_L, 			// 0x16
	UP_CALIBRATION_H, 			// 0x17
	TORQUE_ENABLE, 					// 0x18
	LED, 										// 0x19
	CW_COMPLIANCE_MARGIN, 	// 0x1A
	CCW_COMPLIANCE_MARGIN, 	// 0x1B
	CW_COMPLIANCE_SLOPE, 		// 0x1C
	CCW_COMPLIANCE_SLOPE, 	// 0x1D
	GOAL_POSITION_L, 				// 0x1E 
	GOAL_POSITION_H, 				// 0x1F 
	MOVING_SPEED_L, 				// 0x20 
	MOVING_SPEED_H,					// 0x21 
	TORQUE_LIMIT_L, 				// 0x22 
	TORQUE_LIMIT_H, 				// 0x23 
	PRESENT_POSITION_L, 		// 0x24 
	PRESENT_POSITION_H, 		// 0x25 
	PRESENT_SPEED_L, 				// 0x26 
	PRESENT_SPEED_H, 				// 0x27 
	PRESENT_LOAD_L, 				// 0x28 
	PRESENT_LOAD_H, 				// 0x29 
	PRESENT_VOLTAGE, 				// 0x2A 
	PRESENT_TEMPERATURE, 		// 0x2B 
	REGISTERED_INSTRUCTION,	// 0x2C 
	RESERVE3, 							// 0x2D 
	MOVING, 								// 0x2E 
	LOCK, 									// 0x2F 
	PUNCH_L, 								// 0x30
	PUNCH_H									// 0x31
};

//Hvoid set_act(char ctrl);  

class Cytron_G15Shield
{
	public:
		uint8_t ServoID;
		uint8_t _txpin, _rxpin, _ctrlpin;
		
		Cytron_G15Shield(uint8_t rxpin, uint8_t txpin, uint8_t ctrlpin); // SoftwareSerial
		Cytron_G15Shield(uint8_t ctrlpin); // HardwareSerial
		void begin(uint32_t baudrate);
		void end(void);
		
		//*=========Wheel Mode=====================================================================================
		//360 degree continous rotation. change CW and CCW Angle Limits to same value
		uint16_t setWheelMode(uint8_t servoID);
		uint16_t exitWheelMode(uint8_t servoID);
		uint16_t setWheelSpeed(uint8_t servoID, uint16_t speed, uint8_t direction);

		//*=========Normal Positioning Mode========================================================================
		//(Rotation limited by Angle Limit and Direction of Rotation determined by operation section of Angle Limit)
		uint16_t setPos(uint8_t servoID, uint16_t position);
		uint16_t setPosAngle(uint8_t servoID, uint16_t angle);
		uint16_t setPosSpeed(uint8_t servoID, uint16_t position, uint16_t speed);
		
		//*========Direction Positioning Mode======================================================================
		//(Rotation direction and angle is NOT limited by Angle Limit Control Register value)
		uint16_t rotateCW(uint8_t servoID, uint16_t position);
		uint16_t rotateCCW(uint8_t servoID, uint16_t position);
		
		//*=======Torque Enable and Speed Control==================================================================
		uint16_t setTorqueOnOff(uint8_t servoID, uint8_t onOff);
		uint16_t setSpeed(uint8_t servoID, uint16_t speed);
		uint16_t setTimeToGoal(uint8_t servoID, uint16_t time);
		
		//*=======Set Maximum Limits===============================================================================
		uint16_t setAngleLimit(uint8_t servoID, uint16_t cwAngle, uint16_t ccwAngle);
		uint16_t setTorqueLimit(uint8_t servoID, uint16_t torqueLimit); //in RAM area
		uint16_t setTemperatureLimit(uint8_t servoID, uint8_t temperature);
		uint16_t setVoltageLimit(uint8_t servoID, uint8_t voltageLow, uint8_t voltageHigh);
		
		uint16_t setID(uint8_t servoID, uint8_t newID);
		
		uint16_t setLED(uint8_t servoID, uint8_t onOff);
		uint16_t setAlarmLED(uint8_t servoID, uint8_t alarmLED);
		uint16_t setAlarmShutDown(uint8_t servoID, uint8_t alarm);
		
		//*========Servo Positioning Control Parameters============================================================
		uint16_t setMarginSlopePunch(uint8_t servoID, uint8_t CWMargin, uint8_t CCWMargin, uint8_t CWSlope, uint8_t CCWSlope, uint16_t punch);

		uint16_t setBaudRate(uint8_t servoID, uint32_t baudrate);
		uint16_t factoryReset(uint8_t servoID);
		uint16_t ping(uint8_t servoID, uint8_t *data);
		
		uint16_t getPos(uint8_t servoID, uint8_t *data);
		uint16_t getSpeed(uint8_t servoID, uint8_t *data);
		uint16_t getLoad(uint8_t servoID, uint8_t *data); 
		uint16_t getVoltage(uint8_t servoID, uint8_t *data); 
		uint16_t getTemperature(uint8_t servoID, uint8_t *data);
		uint16_t getTorqueOnOff(uint8_t servoID, uint8_t *data);		
		uint16_t isMoving(uint8_t servoID, uint8_t *data);
		
		//static void setAction(void);

	protected:
		void setRxMode(void);
		void setTxMode(void);
		uint16_t sendPacket(uint8_t servoID, uint8_t instruction, uint8_t* data, uint8_t parameterLength);
		//byte read_data(byte id, byte* data);
};

#endif
