#include "stm32f7xx.h"                  // Device header

void set_AHB1_peripheral_clock(uint32_t); // function prototypes for enabling clocks to peripheral bus 
void set_AHB2_peripheral_clock(uint32_t);
void set_APB1_peripheral_clock(uint32_t);
void set_APB2_peripheral_clock(uint32_t);
uint16_t compute_uart_div(uint32_t peripheral_clock, uint32_t baud_rate);
void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t Peripheral_clock, uint32_t baudrate);

#define USART2_Enable (1<<17)

/*
1: Enable clock access to GPIOA.
2: Set PA2 and PA3 to alternate function mode.
3: set the alternate function to AF7(0b0111), meaning USART2.

4: Enable clock access to USART2.
5: Set USART2 parameters like baud rate, parity etc. 
6: Enable USART2. this should be the last step. 

*/

void usart2_init(void);

int main(void){
	usart2_init();
	
	
}


void usart2_init(){
	// GPIOA is connected to AHB1, so we will enable clock access
	set_AHB1_peripheral_clock(0x00000001);
	
	// setting PA2 to alternate function
	GPIOA->MODER |= 0x00000020;
	
		// setting PA3 to alternate function
	GPIOA->MODER |= 0x00000080;
	
	// setting alternate function to USART.
	// for pin PA2.
	GPIOA->AFR[0] |= 0x700;   // 0111 0000 0000 for pin2 
	
	GPIOA->AFR[0] |= 0x7000;  // 0111 0000 0000 0000 for pin 3. 
	
	
	set_APB1_peripheral_clock(USART2_Enable);
	
	
	USART2->CR1 |= 1<<10; // Enabling parity 
	USART2->CR1 |= 0<<9; // selecting even parity. 
	
	USART2->CR1 |= 0U<<12;
	USART2->CR1 |= 0U<<28; // 1 start bit, 8 data bits.
	
	USART2->CR2 |= 0U<<12;
	USART2->CR2 |= 0U<<13; // selecting 1 stop bit by code 00 for bit 12 and 13
	
	uart_set_baudrate(USART2, 16000000, 115200);
	USART2->CR1 |= 0x00000001; // enabling usart2. 
}

void set_AHB1_peripheral_clock(uint32_t peripheral){
	SET_BIT(RCC->AHB1ENR,peripheral);
}
void set_AHB2_peripheral_clock(uint32_t peripheral){
	SET_BIT(RCC->AHB2ENR,peripheral);
}

void set_APB1_peripheral_clock(uint32_t peripheral){
	SET_BIT(RCC->APB1ENR,peripheral);
}

void set_APB2_peripheral_clock(uint32_t peripheral){
	SET_BIT(RCC->APB2ENR,peripheral);
}

void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t Peripheral_clock, uint32_t baudrate){
	
	USARTx->BRR = compute_uart_div(Peripheral_clock, baudrate);
}
uint16_t compute_uart_div(uint32_t peripheral_clock, uint32_t baud_rate){
	return (peripheral_clock + (baud_rate/2U))/baud_rate;
}
