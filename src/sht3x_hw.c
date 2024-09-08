/*
 * sht3x_hw.c
 *
 *  Created on: 27 aug. 2024
 *      Author: Ludo
 */

#include "sht3x_hw.h"

#ifndef SHT3X_DRIVER_DISABLE_FLAGS_FILE
#include "sht3x_driver_flags.h"
#endif
#include "sht3x.h"
#include "types.h"

#ifndef SHT3X_DRIVER_DISABLE

/*** SHT3X HW functions ***/

/*******************************************************************/
SHT3X_status_t __attribute__((weak)) SHT3X_HW_init(void) {
	// Local variables.
	SHT3X_status_t status = SHT3X_SUCCESS;
	/* To be implemented */
	return status;
}

/*******************************************************************/
SHT3X_status_t __attribute__((weak)) SHT3X_HW_de_init(void) {
	// Local variables.
	SHT3X_status_t status = SHT3X_SUCCESS;
	/* To be implemented */
	return status;
}

/*******************************************************************/
SHT3X_status_t __attribute__((weak)) SHT3X_HW_i2c_write(uint8_t i2c_address, uint8_t* data, uint8_t data_size_bytes, uint8_t stop_flag) {
	// Local variables.
	SHT3X_status_t status = SHT3X_SUCCESS;
	/* To be implemented */
	UNUSED(i2c_address);
	UNUSED(data);
	UNUSED(data_size_bytes);
	UNUSED(stop_flag);
	return status;
}

/*******************************************************************/
SHT3X_status_t __attribute__((weak)) SHT3X_HW_i2c_read(uint8_t i2c_address, uint8_t* data, uint8_t data_size_bytes) {
	// Local variables.
	SHT3X_status_t status = SHT3X_SUCCESS;
	/* To be implemented */
	UNUSED(i2c_address);
	UNUSED(data);
	UNUSED(data_size_bytes);
	return status;
}

/*******************************************************************/
SHT3X_status_t __attribute__((weak)) SHT3X_HW_delay_milliseconds(uint32_t delay_ms) {
	// Local variables.
	SHT3X_status_t status = SHT3X_SUCCESS;
	/* To be implemented */
	UNUSED(delay_ms);
	return status;
}

#endif /* SHT3X_DRIVER_DISABLE */
