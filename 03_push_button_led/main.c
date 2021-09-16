#include "stm32f7xx.h"                  // Device header


int main(void){
	
	RCC ->AHB1ENR |= 0x00000004;  // enables port C. (bit 3)
	RCC ->AHB1ENR |= 0x00000002;  // enable port B. 
	
	GPIOB->MODER |=  0x00000001;  // set the mode to output
	GPIOC->MODER |=  0x00000000;  // set the mode to input ( by default the pins are input)
	while(1){
		if (GPIOC->IDR & 0x00002000){ //if PC13 is high
			GPIOB->ODR = 0x00001; // if pressed , turn on LED
	}else{
		GPIOB->ODR = 0x0000;
		
	}
}
}
