/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32l1xx.h"
#include "stm32l1xx_nucleo.h"
			

int main(void)
{

	for(;;);
}

void uart_gpio_init()
{
	//pin PC10->TX(UART 4)
	//pin PC11->RX(UART 4)
	// AFR->8 both

	RCC->AHBENR |= RCC_AHBENR_GPIOCEN;

	//Moder setup for PC10
	GPIOC->MODER &= ~GPIO_MODER_MODER10_0;
	GPIOC->MODER |= GPIO_MODER_MODER10_1;

	//Moder setup for PC11
	GPIOC->MODER &= ~GPIO_MODER_MODER11_0;
	GPIOC->MODER |= GPIO_MODER_MODER11_1;

	//AFR setup for PC10
	GPIOC->AFR[1] = 0x00000800;

	//AFR setup for PC11
	GPIOC->AFR[1] = 0x00008000;



}

void uart_init()
{
	//Enabling clock for UART
	RCC->APB1ENR |= RCC_APB1ENR_UART4EN;

	//Enabling the uart
	UART4->CR1 |= USART_CR1_UE;

	//baud rate selection
	UART4->BRR = (6<0) | (208<4);

	// enable receiver and transmitter
	UART4->CR1 |= USART_CR1_RE;
	UART4->CR1 |= USART_CR1_TE;

}
