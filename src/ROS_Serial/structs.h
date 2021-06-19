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

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * structure for receiving command from serial port
 * uint16 v_left, v_right are in mm/s
 */

/* general */
typedef enum types{ NAT = 0,    //not a type (for initialization or error)
                    cmd_t = 1   // cmd structure
} id;
bool checkSize(id type, uint16_t size);

/* type CMD */
typedef struct {
    int16_t v_left, v_right;
} cmd;
void writeCMD(cmd* p_cmd, uint8_t byte, uint16_t index);
uint8_t readCMD(cmd* p_cmd, uint16_t index);


#ifdef __cplusplus
} // closing brace for extern "C"
#endif

#endif /* STRUCTS_H_ */
