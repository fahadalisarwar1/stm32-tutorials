#include "stm32f7xx.h"                  // Device header
// We are going to use USART2 which is connected with APB1.
// to enable clock access, we need to set the bit 17 of RCC_APB1ENR to 1. 


void set_ahb1_periperhal_clock(uint32_t);
void set_ahb2_periperhal_clock(uint32_t);
void set_apb1_periperhal_clock(uint32_t);
void set_apb2_periperhal_clock(uint32_t);

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

	
	USART2->CR1 |= 0x0004; // Transmit Enable
	USART2->CR1 |= 0x0008; // Recevive Enable
	
	USART2->CR1 |= 0x0001; // enabling uart. 
}


void set_ahb1_periperhal_clock(uint32_t peripheral){
	SET_BIT(RCC->AHB1ENR, peripheral);
}
void set_ahb2_periperhal_clock(uint32_t peripheral){
	SET_BIT(RCC->AHB2ENR, peripheral);
	
}


void set_apb1_periperhal_clock(uint32_t peripheral){
	SET_BIT(RCC->APB1ENR, peripheral);
}

void set_apb2_periperhal_clock(uint32_t peripheral){
	SET_BIT(RCC->APB2ENR, peripheral);
}