/****************************************************************************
 *
 *   Copyright (c) 2013-2016 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * @file board_config.h
 *
 * AeroCore2 internal definitions
 */

#pragma once

/****************************************************************************************************
 * Included Files
 ****************************************************************************************************/

#include <px4_config.h>
#include <nuttx/compiler.h>
#include <stdint.h>

__BEGIN_DECLS

/* these headers are not C++ safe */
#include <stm32.h>
#include <arch/board/board.h>

#define UDID_START		0x1FFF7A10

/****************************************************************************************************
 * Definitions
 ****************************************************************************************************/

/* LEDs */
/* Blue */
#define GPIO_LED0	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_SET|GPIO_PORTE|GPIO_PIN9)
/* Yellow */
#define GPIO_LED1	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_SET|GPIO_PORTE|GPIO_PIN10)

/* Gyro */
#define GPIO_EXTI_GYRO_DRDY	(GPIO_INPUT|GPIO_FLOAT|GPIO_EXTI|GPIO_PORTD|GPIO_PIN2)
#define SENSOR_BOARD_ROTATION_DEFAULT	3 /* SENSOR_BOARD_ROTATION_270_DEG todo:check this*/

/* Accel & Mag */
#define GPIO_EXTI_MAG_DRDY	(GPIO_INPUT|GPIO_FLOAT|GPIO_EXTI|GPIO_PORTD|GPIO_PIN4)
#define GPIO_EXTI_ACCEL_DRDY	(GPIO_INPUT|GPIO_FLOAT|GPIO_EXTI|GPIO_PORTD|GPIO_PIN3)

/* GPS */
#define GPS_DEFAULT_UART_PORT	"/dev/ttyS0"

#define PX4_SPI_BUS_EXT		1
/* Nominal chip selects for devices on SPI bus #1 */
#define PX4_SPIDEV_EXT0		1
#define GPIO_SPI_CS_EXT0		(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_SET|GPIO_PORTA|GPIO_PIN4)

/* SPI3--Sensors */
#define PX4_SPI_BUS_SENSORS	3
#define PX4_SPI_BUS_BARO	PX4_SPI_BUS_SENSORS
/* Nominal chip selects for devices on SPI bus #3 */
#define PX4_SPIDEV_ACCEL_MAG	0
#define PX4_SPIDEV_GYRO		1
#define PX4_SPIDEV_BARO		2

#define GPIO_SPI_CS_ACCEL_MAG	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_SET|GPIO_PORTE|GPIO_PIN2)
#define GPIO_SPI_CS_GYRO	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_SET|GPIO_PORTE|GPIO_PIN3)
#define GPIO_SPI_CS_BARO	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_SET|GPIO_PORTE|GPIO_PIN4)

/* SPI4--Ramtron */
#define PX4_SPI_BUS_RAMTRON	4
#define GPIO_SPI_CS_FRAM	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_SET|GPIO_PORTE|GPIO_PIN11)


/* I2C busses */
#define PX4_I2C_BUS_EXPANSION	2
#define PX4_I2C_BUS_LED		PX4_I2C_BUS_EXPANSION

/*
 * ADC channels
 *
 * These are the channel numbers of the ADCs of the microcontroller that can be used by the Px4 Firmware in the adc driver
 */
#define ADC_CHANNELS (1 << 10) | (1 << 11) | (1 << 12) | (1 << 13)

// ADC defines to be used in sensors.cpp to read from a particular channel
#define ADC_BATTERY_VOLTAGE_CHANNEL	10
#define ADC_BATTERY_CURRENT_CHANNEL	((uint8_t)(-1))
#define ADC_AIRSPEED_VOLTAGE_CHANNEL	((uint8_t)(-1))


/* User GPIOs broken out on 4.1 Power & GPIO Header J11 */
#define GPIO_GPIO0_INPUT	(GPIO_INPUT|GPIO_PULLUP|GPIO_PORTA|GPIO_PIN10)
#define GPIO_GPIO1_INPUT	(GPIO_INPUT|GPIO_PULLUP|GPIO_PORTA|GPIO_PIN9)
#define GPIO_GPIO2_INPUT	(GPIO_INPUT|GPIO_PULLUP|GPIO_PORTA|GPIO_PIN8)
#define GPIO_GPIO3_INPUT	(GPIO_INPUT|GPIO_PULLUP|GPIO_PORTC|GPIO_PIN8)
#define GPIO_GPIO4_INPUT	(GPIO_INPUT|GPIO_PULLUP|GPIO_PORTC|GPIO_PIN7)
#define GPIO_GPIO5_INPUT	(GPIO_INPUT|GPIO_PULLUP|GPIO_PORTC|GPIO_PIN6)
#define GPIO_GPIO6_INPUT	(GPIO_INPUT|GPIO_PULLUP|GPIO_PORTE|GPIO_PIN6)
#define GPIO_GPIO7_INPUT	(GPIO_INPUT|GPIO_PULLUP|GPIO_PORTE|GPIO_PIN5)
#define GPIO_GPIO8_INPUT	(GPIO_INPUT|GPIO_PULLUP|GPIO_PORTB|GPIO_PIN0)
#define GPIO_GPIO9_INPUT	(GPIO_INPUT|GPIO_PULLUP|GPIO_PORTC|GPIO_PIN9)

#define GPIO_GPIO0_OUTPUT	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GGPIO_PORTA|GPIO_PIN10)
#define GPIO_GPIO1_OUTPUT	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GGPIO_PORTA|GPIO_PIN9)
#define GPIO_GPIO2_OUTPUT	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GGPIO_PORTA|GPIO_PIN8)
#define GPIO_GPIO3_OUTPUT	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GGPIO_PORTC|GPIO_PIN8)
#define GPIO_GPIO4_OUTPUT	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GGPIO_PORTC|GPIO_PIN7)
#define GPIO_GPIO5_OUTPUT	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GGPIO_PORTC|GPIO_PIN6)
#define GPIO_GPIO6_OUTPUT	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GGPIO_PORTE|GPIO_PIN6)
#define GPIO_GPIO7_OUTPUT	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GGPIO_PORTE|GPIO_PIN5)
#define GPIO_GPIO8_OUTPUT	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GGPIO_PORTB|GPIO_PIN0)
#define GPIO_GPIO9_OUTPUT	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GGPIO_PORTC|GPIO_PIN9)

/* PWM
 *
 * Eight PWM outputs are configured. On 3.1 PWM Header
 *
 * Pins:
 *
 * CH1 : PD12 : TIM4_CH1
 * CH2 : PD13 : TIM4_CH2
 * CH3 : PD14 : TIM4_CH3
 * CH4 : PD15 : TIM4_CH4
 * CH5 : PA0  : TIM2_CH1
 * CH6 : PA1  : TIM2_CH2
 * CH7 : PA2  : TIM2_CH3
 * CH8 : PA3  : TIM2_CH4
 */
#define GPIO_TIM4_CH1OUT	GPIO_TIM4_CH1OUT_2
#define GPIO_TIM4_CH2OUT	GPIO_TIM4_CH2OUT_2
#define GPIO_TIM4_CH3OUT	GPIO_TIM4_CH3OUT_2
#define GPIO_TIM4_CH4OUT	GPIO_TIM4_CH4OUT_2
#define GPIO_TIM2_CH1OUT	GPIO_TIM2_CH1OUT_1
#define GPIO_TIM2_CH2OUT	GPIO_TIM2_CH2OUT_1
#define GPIO_TIM2_CH3OUT	GPIO_TIM2_CH3OUT_1
#define GPIO_TIM2_CH4OUT	GPIO_TIM2_CH4OUT_1
#define DIRECT_PWM_OUTPUT_CHANNELS	8

#define GPIO_TIM4_CH1IN		GPIO_TIM4_CH1IN_2
#define GPIO_TIM4_CH2IN		GPIO_TIM4_CH2IN_2
#define GPIO_TIM4_CH3IN		GPIO_TIM4_CH3IN_2
#define GPIO_TIM4_CH4IN		GPIO_TIM4_CH4IN_2
#define GPIO_TIM2_CH1IN		GPIO_TIM2_CH1IN_1
#define GPIO_TIM2_CH2IN		GPIO_TIM2_CH2IN_1
#define GPIO_TIM2_CH3IN		GPIO_TIM2_CH3IN_1
#define GPIO_TIM2_CH4IN		GPIO_TIM2_CH4IN_1
#define DIRECT_INPUT_TIMER_CHANNELS	8

/* High-resolution timer */
#define HRT_TIMER		8	/* use timer 8 for the HRT */
#define HRT_TIMER_CHANNEL	1	/* use capture/compare channel */

/* PB9 TIM11_CH1 */
#define PWMIN_TIMER			11
#define PWMIN_TIMER_CHANNEL	1
#define GPIO_PWM_IN		GPIO_TIM11_CH1IN_1

/* PB8 Tone Alarm */
#define TONE_ALARM_TIMER	10	/* timer 10 */
#define TONE_ALARM_CHANNEL	1	/* channel 1 */
#define GPIO_TONE_ALARM_IDLE (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTB|GPIO_PIN8)
#define GPIO_TONE_ALARM		 (GPIO_ALT|GPIO_AF1|GPIO_SPEED_2MHz|GPIO_PUSHPULL|GPIO_PORTB|GPIO_PIN8)

#define BOARD_NAME "AEROCORE2"

#define BOARD_HAS_PWM	8

#define BOARD_FMU_GPIO_TAB  { \
		{GPIO_GPIO0_INPUT,       GPIO_GPIO0_OUTPUT,       0}, \
		{GPIO_GPIO1_INPUT,       GPIO_GPIO1_OUTPUT,       0}, \
		{GPIO_GPIO3_INPUT,       GPIO_GPIO3_OUTPUT,       0}, \
		{GPIO_GPIO4_INPUT,       GPIO_GPIO4_OUTPUT,       0}, \
		{GPIO_GPIO5_INPUT,       GPIO_GPIO5_OUTPUT,       0}, \
		{GPIO_GPIO6_INPUT,       GPIO_GPIO6_OUTPUT,       0}, \
		{GPIO_GPIO7_INPUT,       GPIO_GPIO7_OUTPUT,       0}, \
		{GPIO_GPIO8_INPUT,       GPIO_GPIO8_OUTPUT,       0}, \
		{GPIO_GPIO9_INPUT,       GPIO_GPIO9_OUTPUT,       0}

/****************************************************************************************************
 * Public Types
 ****************************************************************************************************/

/****************************************************************************************************
 * Public data
 ****************************************************************************************************/

#ifndef __ASSEMBLY__

/****************************************************************************************************
 * Public Functions
 ****************************************************************************************************/

/****************************************************************************************************
 * Name: stm32_spiinitialize
 *
 * Description:
 *   Called to configure SPI chip select GPIO pins for the PX4FMU board.
 *
 ****************************************************************************************************/

extern void stm32_spiinitialize(void);
#define board_spi_reset(ms)

extern void stm32_usbinitialize(void); //added

#define board_peripheral_reset(ms);

/****************************************************************************
 * Name: nsh_archinitialize
 *
 * Description:
 *   Perform architecture specific initialization for NSH.
 *
 *   CONFIG_NSH_ARCHINIT=y :
 *     Called from the NSH library
 *
 *   CONFIG_BOARD_INITIALIZE=y, CONFIG_NSH_LIBRARY=y, &&
 *   CONFIG_NSH_ARCHINIT=n :
 *     Called from board_initialize().
 *
 ****************************************************************************/

#ifdef CONFIG_NSH_LIBRARY
int nsh_archinitialize(void);
#endif

#include "../common/board_common.h"

#endif /* __ASSEMBLY__ */

__END_DECLS