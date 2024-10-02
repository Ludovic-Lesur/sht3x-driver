/*
 * sht3x.h
 *
 *  Created on: 27 aug. 2024
 *      Author: Ludo
 */

#ifndef __SHT3X_H__
#define __SHT3X_H__

#ifndef SHT3X_DRIVER_DISABLE_FLAGS_FILE
#include "sht3x_driver_flags.h"
#endif
#include "types.h"

/*** SHT3x structures ***/

/*!******************************************************************
 * \enum SHT3X_status_t
 * \brief SHT3X driver error codes.
 *******************************************************************/
typedef enum {
    // Driver errors.
    SHT3X_SUCCESS = 0,
    SHT3X_ERROR_NULL_PARAMETER,
    // Low level drivers errors.
    SHT3X_ERROR_BASE_I2C = 0x0100,
    SHT3X_ERROR_BASE_DELAY = (SHT3X_ERROR_BASE_I2C + SHT3X_DRIVER_I2C_ERROR_BASE_LAST),
    // Last base value.
    SHT3X_ERROR_BASE_LAST = (SHT3X_ERROR_BASE_DELAY + SHT3X_DRIVER_DELAY_ERROR_BASE_LAST)
} SHT3X_status_t;

#ifndef SHT3X_DRIVER_DISABLE

/*** SHT3x functions ***/

/*!******************************************************************
 * \fn SHT3X_status_t SHT3X_init(void)
 * \brief Init SHT3X driver.
 * \param[in]   none
 * \param[out]  none
 * \retval      Function execution status.
 *******************************************************************/
SHT3X_status_t SHT3X_init(void);

/*!******************************************************************
 * \fn SHT3X_status_t SHT3X_de_init(void)
 * \brief Release SHT3X driver.
 * \param[in]   none
 * \param[out]  none
 * \retval      Function execution status.
 *******************************************************************/
SHT3X_status_t SHT3X_de_init(void);

/*!******************************************************************
 * \fn SHT3X_status_t SHT3X_get_temperature_humidity(uint8_t i2c_address, int32_t* temperature_degrees, int32_t* humidity_percent)
 * \brief Perform temperature and humidity measurements.
 * \param[in]   i2c_address: I2C address of the sensor.
 * \param[out]  temperature_degrees: Pointer to integer that will contain the temperature in Celsius degrees.
 * \param[out]  humidity_percent: Pointer to integer that will contain the humidity in percent.
 * \retval      Function execution status.
 *******************************************************************/
SHT3X_status_t SHT3X_get_temperature_humidity(uint8_t i2c_address, int32_t* temperature_degrees, int32_t* humidity_percent);

/*******************************************************************/
#define SHT3X_exit_error(base) { ERROR_check_exit(sht3x_status, SHT3X_SUCCESS, base) }

/*******************************************************************/
#define SHT3X_stack_error(base) { ERROR_check_stack(sht3x_status, SHT3X_SUCCESS, base) }

/*******************************************************************/
#define SHT3X_stack_exit_error(base, code) { ERROR_check_stack_exit(sht3x_status, SHT3X_SUCCESS, base, code) }

#endif /* SHT3X_DRIVER_DISABLE */

#endif /* __SHT3X_H__ */
