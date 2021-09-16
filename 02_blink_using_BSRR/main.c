#include "stm32f7xx.h"                  // Device header

int main(void){
	RCC->AHB1ENR |= 0x2;
	
	GPIOB->MODER |= 0x01;
	
	while (1){
		GPIOB->BSRR = 0x01;  // set PB0 high
	
	}
	
}
