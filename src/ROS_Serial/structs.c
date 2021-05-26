/*
 * structs.c
 *
 *  Created on: Dec 6, 2018
 *      Author: jifei
 */

#include "structs.h"

/* general */

/*  checkSize need to be updated whenever a new structure is defined.
 *
 */
bool checkSize(id type, uint16_t size){
    switch (type) {
        case NAT:
            return (size == 0);
        case cmd_t:
            return (size == 4);
        default:
            return false;
    }
}

/* CMD */
void writeCMD(cmd* p_cmd, uint8_t byte, uint16_t index)
{
    switch (index) {
        case 0: //MS of v_left
            p_cmd->v_left = (p_cmd->v_left & 0x00ff) | ( ((uint16_t)byte) << 8 );
            break;
        case 1: //LS of v_left
            p_cmd->v_left |= (uint16_t)byte;
            break;
        case 2: //MS of v_right
            p_cmd->v_right = (p_cmd->v_right & 0x00ff) | ( ((uint16_t)byte) << 8);
            break;
        case 3: //LS of v_right
            p_cmd->v_right |= ((uint16_t)byte);
            break;
        default:
            break;
    }
}
uint8_t readCMD(cmd* p_cmd, uint16_t index)
{
    switch (index) {
        case 0: //MS of v_left
            return p_cmd->v_left >> 8;
        case 1: //LS of v_left
            return p_cmd->v_left & 0xff;
        case 2: //MS of v_right
            return p_cmd->v_right >> 8;
        case 3: //LS of v_right
            return p_cmd->v_right & 0xff;
        default:
            return 0;
    }
}
