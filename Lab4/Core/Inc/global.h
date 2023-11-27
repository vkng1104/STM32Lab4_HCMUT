/*
 * global.h
 *
 *  Created on: Nov 26, 2023
 *      Author: ASUS
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include <stdio.h>
#include <string.h>
#include "software_timer.h"
#include "main.h"

// Static command
#define COMMAND_START 		'!'
#define COMMAND_END   		'#'

// Status for uart communication
#define RECEIVE_RST 				3
#define SEND_ADC					4
#define RECEIVE_OK 				5
#define MAX_BUFFER_SIZE 		30

extern int uart_status;

extern uint8_t temp;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;

extern uint32_t ADC_value;
extern char str[MAX_BUFFER_SIZE];	// read string from uart

// Status for command parser
#define INIT 							0
#define READ 						1

extern int command_status;

extern uint8_t command_flag;
extern uint8_t command_buffer[MAX_BUFFER_SIZE];
extern uint8_t command_index;



#endif /* INC_GLOBAL_H_ */
