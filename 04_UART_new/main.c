#include "stm32f7xx.h"                  // Device header
void uart2_init(void);
int main(void){
	
}


void uart2_init(){
		// first enable clock access to port A. 
		RCC->AHB1ENR |= 0x00000001;
	
}
