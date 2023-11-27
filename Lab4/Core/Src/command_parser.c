/*
 * command_parser.c
 *
 *  Created on: Nov 26, 2023
 *      Author: ASUS
 */

#include "command_parser.h"

/**
 * @brief Parses incoming characters to identify commands.
 *
 * @param command_status The status of command parser.
 * @param command_buffer The buffer to store the command.
 * @param command_index The index in the command buffer.
 * @param command_flag Flag indicating if a complete command is ready.
 */

void command_parser_fsm() {
	switch (command_status) {
	case INIT:
		if (temp == COMMAND_START) {
			command_status = READ;
			command_index = 0;
		}

		break;

	case READ:
		if (temp == COMMAND_START) {
			command_index = 0;
		} else if (temp == COMMAND_END) {
			command_flag = 1;
			command_status = INIT;
			command_buffer[command_index] = '\0'; // null terminator
		} else {
			command_buffer[command_index++] = temp;

			if (command_index >= MAX_BUFFER_SIZE) {
				command_index = 0;
			}
		}

		break;
	default:
		break;
	}
}
