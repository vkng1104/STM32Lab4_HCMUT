/*
 * uart_communication.c
 *
 *  Created on: Nov 26, 2023
 *      Author: ASUS
 */

#include "uart_communication.h"

void uart_communiation_fsm(ADC_HandleTypeDef hadc1, UART_HandleTypeDef huart2) {
	switch (uart_status) {
	case RECEIVE_RST:
		if (command_flag == 1) {
			command_flag = 0;

			if (strcmp((char*)command_buffer, "RST") == 0) {
				HAL_ADC_Start(&hadc1);
				ADC_value = HAL_ADC_GetValue(&hadc1);
				HAL_ADC_Stop(&hadc1);

				HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "\r\n"), 1000);
				uart_status = SEND_ADC;
				setTimer(2, 3000);
			}
		}

		break;

	case SEND_ADC:
		HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "!ADC=%lu#\r\n", ADC_value), 1000);
		uart_status = RECEIVE_OK;
		break;

	case RECEIVE_OK:
		if (command_flag == 1) {
			command_flag = 0;

			if (strcmp((char*)command_buffer, "OK") == 0) {
				HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "\r\n"), 1000);
				uart_status = RECEIVE_RST;
			}
		}

		if (timer_flag[2] == 1) {
			uart_status = SEND_ADC;
			setTimer(2, 3000);
		}

		break;

	default:
		break;
	}
}
