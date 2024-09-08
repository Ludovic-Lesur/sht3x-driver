/*
 * sht3x.c
 *
 *  Created on: 27 aug. 2024
 *      Author: Ludo
 */

#include "sht3x.h"

#ifndef SHT3X_DRIVER_DISABLE_FLAGS_FILE
#include "sht3x_driver_flags.h"
#endif
#include "sht3x_hw.h"
#include "types.h"

#ifndef SHT3X_DRIVER_DISABLE

/*** SHT3x local macros ***/

#define SHT3X_FULL_SCALE					65535

#define SHT3X_MEASURE_COMMAND_BUFFER_SIZE	2
#define SHT3X_MEASURE_DATA_BUFFER_SIZE		6

/*** SHT3x functions ***/

/*******************************************************************/
SHT3X_status_t SHT3X_init(void) {
	// Local variables.
	SHT3X_status_t status = SHT3X_SUCCESS;
	// Init hardware interface.
	status = SHT3X_HW_init();
	return status;
}

/*******************************************************************/
SHT3X_status_t SHT3X_de_init(void) {
	// Local variables.
	SHT3X_status_t status = SHT3X_SUCCESS;
	// Release hardware interface.
	status = SHT3X_HW_de_init();
	return status;
}

/*******************************************************************/
SHT3X_status_t SHT3X_get_temperature_humidity(uint8_t i2c_address, int32_t* temperature_degrees, int32_t* humidity_percent) {
	// Local variables.
	SHT3X_status_t status = SHT3X_SUCCESS;
	uint8_t measure_command[SHT3X_MEASURE_COMMAND_BUFFER_SIZE] = {0x24, 0x00};
	uint8_t measure_buf[SHT3X_MEASURE_DATA_BUFFER_SIZE] = {0x00};
	int32_t data_16bits = 0;
	// Check parameters.
	if ((temperature_degrees == NULL) || (humidity_percent == NULL)) {
		status = SHT3X_ERROR_NULL_PARAMETER;
		goto errors;
	}
	// Trigger high repeatability measurement with clock stretching disabled.
	status = SHT3X_HW_i2c_write(i2c_address, measure_command, SHT3X_MEASURE_COMMAND_BUFFER_SIZE, 1);
	if (status != SHT3X_SUCCESS) goto errors;
	// Wait for conversion to complete (at least 15ms).
	status = SHT3X_HW_delay_milliseconds(30);
	if (status != SHT3X_SUCCESS) goto errors;
	// Read data.
	status = SHT3X_HW_i2c_read(i2c_address, measure_buf, SHT3X_MEASURE_DATA_BUFFER_SIZE);
	if (status != SHT3X_SUCCESS) goto errors;
	// Compute temperature.
	data_16bits = (int32_t) ((measure_buf[0] << 8) + measure_buf[1]);
	(*temperature_degrees) = (((175 * data_16bits) / (SHT3X_FULL_SCALE)) - 45);
	// Compute humidity.
	data_16bits = (int32_t) ((measure_buf[3] << 8) + measure_buf[4]);
	(*humidity_percent) = (100 * data_16bits) / (SHT3X_FULL_SCALE);
errors:
	return status;
}

#endif /* SHT3X_DRIVER_DISABLE */
