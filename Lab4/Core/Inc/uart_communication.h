/*
 * uart_communication.h
 *
 *  Created on: Nov 26, 2023
 *      Author: ASUS
 */

#ifndef INC_UART_COMMUNICATION_H_
#define INC_UART_COMMUNICATION_H_

#include "global.h"

void uart_communiation_fsm(ADC_HandleTypeDef hadc1, UART_HandleTypeDef huart2);

#endif /* INC_UART_COMMUNICATION_H_ */
