/*
 * TestControlBolck.h
 *
 *  Created on: Jul 30, 2024
 *      Author: jdeutsch
 */

#ifndef TESTCONTROLBLOCK_H_
#define TESTCONTROLBLOCK_H_

typedef struct
{
	uint32_t psp_value;
	uint32_t block_count;
	uint8_t current_state;
	uint8_t task_priority;
	void (*task_handler)(void);
} TCB_t;




#endif /* TESTCONTROLBLOCK_H_ */
