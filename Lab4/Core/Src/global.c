/*
 * global.c
 *
 *  Created on: Nov 26, 2023
 *      Author: ASUS
 */

#include "global.h"

int uart_status = RECEIVE_RST;
uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

uint32_t ADC_value = 0;
char str[MAX_BUFFER_SIZE];

int command_status = INIT;
uint8_t command_buffer[MAX_BUFFER_SIZE];
uint8_t command_index = 0;
uint8_t command_flag = 0;



