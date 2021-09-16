
// PB 0 = Green LED.
// to access port B, we need  AHB1  bus. 
// to enable clock access to AHB1 and port B, we need to use the following register
// RCC -> AHB1ENR
// GPIOx_MODR where x is the port in this case B. 
// GPIOx_ODR
#include "stm32f7xx.h"                  // Device header

void delay_ms(int delay);

int main(void){
	
	RCC->AHB1ENR |= 0x00000002; // enable clock access to port B. 
	// bitwise OR operation to make sure we dont change any other bit. 
	
	GPIOB->MODER |= 0x00000001;    //0b 0000 0000 0000 0000 0000 0000 0001 corresponding to PB0.  
	
	while(1){
		GPIOB->ODR = 0x000000001;
		delay_ms(100);
		GPIOB->ODR &=~0x000000001;
		delay_ms(100);
	}
}



void delay_ms(int delay){
	int i;
	for(; delay > 0 ; delay--){
		for (i = 0; i <3195; i++);
	}
}
