/*
 * sht3x_hw.h
 *
 *  Created on: 27 aug. 2024
 *      Author: Ludo
 */

#ifndef __SHT3X_HW_H__
#define __SHT3X_HW_H__

#include "sht3x.h"
#include "types.h"

/*** SHT3X HW functions ***/

/*!******************************************************************
 * \fn SHT3X_status_t SHT3X_HW_init(void)
 * \brief Init SHT3X hardware interface.
 * \param[in]  	none
 * \param[out] 	none
 * \retval		Function execution status.
 *******************************************************************/
SHT3X_status_t SHT3X_HW_init(void);

/*!******************************************************************
 * \fn SHT3X_status_t SHT3X_HW_de_init(void)
 * \brief Release SHT3X hardware interface.
 * \param[in]  	none
 * \param[out] 	none
 * \retval		Function execution status.
 *******************************************************************/
SHT3X_status_t SHT3X_HW_de_init(void);

/*!******************************************************************
 * \fn SHT3X_status_t SHT3X_HW_i2c_write(uint8_t i2c_address, uint8_t* data, uint8_t data_size_bytes, uint8_t stop_flag)
 * \brief Write data to sensor over I2C bus.
 * \param[in]  	i2c_address: 7-bits sensor address.
 * \param[in]	data: Byte array to send.
 * \param[in]	data_size_bytes: Number of bytes to send.
 * \param[in]	stop_flag: Generate stop condition at the end of the transfer if non zero.
 * \param[out] 	none
 * \retval		Function execution status.
 *******************************************************************/
SHT3X_status_t SHT3X_HW_i2c_write(uint8_t i2c_address, uint8_t* data, uint8_t data_size_bytes, uint8_t stop_flag);

/*!******************************************************************
 * \fn SHT3X_status_t SHT3X_HW_i2c_read(uint8_t i2c_address, uint8_t* data, uint8_t data_size_bytes)
 * \brief Read data from sensor over I2C bus.
 * \param[in]  	i2c_address: 7-bits sensor address.
 * \param[in]	data_size_bytes: Number of bytes to read.
 * \param[out]	data: Byte array that will contain the read data.
 * \retval		Function execution status.
 *******************************************************************/
SHT3X_status_t SHT3X_HW_i2c_read(uint8_t i2c_address, uint8_t* data, uint8_t data_size_bytes);

/*!******************************************************************
 * \fn SHT3X_status_t SHT3X_HW_delay_milliseconds(uint32_t delay_ms)
 * \brief Delay function.
 * \param[in]  	delay_ms: Delay to wait in ms.
 * \param[out] 	none
 * \retval		Function execution status.
 *******************************************************************/
SHT3X_status_t SHT3X_HW_delay_milliseconds(uint32_t delay_ms);

#endif /* __SHT3X_HW_H__ */
