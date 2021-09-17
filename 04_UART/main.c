#include "stm32f7xx.h"                  // Device header
// We are going to use USART2 which is connected with APB1.
// to enable clock access, we need to set the bit 17 of RCC_APB1ENR to 1. 


void USART2_init(void);
int main(void){
	while (1){
	
	}
}



void USART2_init(void){
	RCC->APB1ENR |= ( 1 << 17 ); 
	
	
	
	RCC->AHB1ENR |= 0x00000001;  // enabling port A since tx and rx is connected to port A
	
	GPIOA->MODER |= (1 << 5 );
	GPIOA->AFR[0] |= 0x00000700;  // to set alternate function to UART_TX
	GPIOA->AFR[0] |= 0x00007000;  // to set alternate function to UART_R X
	
	USART2->BRR |= 0x2BF2;
	USART2->CR1 |= 0x0001;
	
	USART2->CR1 |= 0x0004;
	USART2->CR1 |= 0x0008;
}
