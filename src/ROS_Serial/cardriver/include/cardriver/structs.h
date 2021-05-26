/*
 * structs.h
 *
 * Whenever a new structure is defined, the following code must be updated:
 * 1. the checkSize function.
 * 2. The enum types
 * 3. read/write function for the structure.
 *
 *  Created on: Dec 5, 2018
 *      Author: jifei
 */

#ifndef STRUCTS_H_
#define STRUCTS_H_

#ifndef __cplusplus
#include <stdint.h>
#include <stdbool.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * structure for receiving command from serial port
 * uint16 v_left, v_right are in mm/s
 */
#define START_CHAR '*'
#define STOP_CHAR '#'

/* general */
//#### more struct, more enum
typedef enum types{ NAT = 0,    //not a type (for initialization or error)
                    cmd_t = 1,   // cmd structure
                    sw_t = 2,   // switch structure, 1 byte, only 6 LS bits are used.
                    ir_t = 3,    // infrared structure, 5 byte, each byte represent a ir sensor, [ ir_left, ir_middle, ir_right, ir_rear_left, ir_rear_right ]
                    imu_t = 4,
                    encoder_t = 5
                  } id;
//#### more struct, more checksize enum.
bool checkSize(id type, uint16_t size);

//#### more struct, more read/write/struct
/* type CMD */
typedef struct {
  int16_t v_left, v_right;
} cmd;
void writeCMD(cmd* p_cmd, uint8_t byte, uint16_t index);
uint8_t readCMD(cmd* p_cmd, uint16_t index);

/* type switch */
#ifndef BUMP_SWICHES
#define Bump_SW1  0x01  //0000 0001
#define Bump_SW2  0x02  //0000 0010
#define Bump_SW3  0x04  //0000 0100
#define Bump_SW4  0x08  //0000 1000
#define Bump_SW5  0x10  //0001 0000
#define Bump_SW6  0x20  //0010 0000
#endif

typedef struct {
  uint8_t switches;
} sw;
void writeSW(sw* p_sw, uint8_t byte);
uint8_t readSW(sw* p_sw);

/*! type infrared */
typedef struct {
  uint8_t ir_left, ir_middle, ir_right, ir_rear_left, ir_rear_right;
} ir;
void writeIR(ir* p_ir, uint8_t byte, uint16_t index);
uint8_t readIR(ir* p_ir, uint16_t index);

/*! type IMU */
typedef struct {
  int16_t pitch,roll,yaw;
} imu;
void writeIMU(imu* p_imu, uint8_t byte, uint16_t index);
uint8_t readIMU(imu* p_imu, uint16_t index);

/*! type ENCODER */
typedef struct {
  int16_t left,right,leftPos,rightPos;
} encoder;
void writeEncoder(encoder* p_encoder, uint8_t byte, uint16_t index);
uint8_t readEncoder(encoder* p_encoder, uint16_t index);

/* structure that contains all types */
//#### more struct, more types
typedef struct {
  cmd command;
  sw switchSensor;
  ir irSensor;
  imu imuSensor;
  encoder encoderSensor;
} returnT;
//#### more struct, more initializer/write/switch.
id updateData(uint8_t data, returnT* rvalues);



#ifdef __cplusplus
} // closing brace for extern "C"
#endif

#endif /* STRUCTS_H_ */
