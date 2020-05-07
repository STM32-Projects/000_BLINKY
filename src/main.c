/**
  ******************************************************************************
  * @file    main.c
  * @author  Supreeth
  * @version V1.0
  * @date    06-May-2020
  *
  * @brief   Blinky Application for stm32f446re
  *
  * Overview
  * --------
  * This application blinks User LED in a blinky fashion with software delays.
  *
  * User LED(LD2, Green) is connected to PA5.
  *
  * Runs on stm32f446re
  *
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "stm32f4xx_nucleo.h"

#define DELAY_CONSTANT 1000000UL

void LED_Init(void);

int main(void)
{
	LED_Init();

	for(;;) {
		HAL_GPIO_WritePin(LED2_GPIO_PORT, LED2_PIN, GPIO_PIN_SET);
		/* Busy wait loop for dummy delay */
		for (uint32_t i = 0; i < DELAY_CONSTANT; i++);
		HAL_GPIO_WritePin(LED2_GPIO_PORT, LED2_PIN, GPIO_PIN_RESET);
		/* Busy wait loop for dummy delay */
		for (uint32_t i = 0; i < DELAY_CONSTANT; i++);
	}
}

/**********************************************************************
 *
 * @brief PortA Initialization for User LED(LD2, Green)
 *
 * User LED(LD2, Green) is connected to PA5.
 *
 * @param None
 *
 * @return None
 *
 *********************************************************************/

void LED_Init(void)
{
	GPIO_InitTypeDef LEDGpio;

	/* Enable Clock to GPIOA Port */
	__HAL_RCC_GPIOA_CLK_ENABLE();

	LEDGpio.Mode = GPIO_MODE_OUTPUT_PP;
	LEDGpio.Pin = GPIO_PIN_5;
	LEDGpio.Speed = GPIO_SPEED_LOW;

	HAL_GPIO_Init(GPIOA, &LEDGpio);
}
