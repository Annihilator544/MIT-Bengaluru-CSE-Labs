#include<LPC17xx.h>
void EINT3_IRQHandler(void);
unsigned char int3_flag=0;
int main(void)
{
	LPC_PINCON->PINSEL4 |= 0x04000000;		//P2.13 as EINT3
	LPC_PINCON->PINSEL4 &= 0xFCFFFFFF;		//P2.12 GPIO for LED
	LPC_GPIO2->FIODIR = 0x00001000;				//P2.12 is assigned output
	LPC_GPIO2->FIOSET = 0x00001000;				//Initiall LED is kept on
	
	LPC_SC->EXTINT = 0x00000008;					//writing 1 cleares the interrupt, get set if there is interrupt
	LPC_SC->EXTMODE = 0x00000008;					//EINT3 is initiated as edge senitive, 0 for level sensitive
	LPC_SC->EXTPOLAR = 0x00000000;				//EINT3 is falling edge sensitive, 1 for rising edge
																				//above registers, bit0-EINT0, bit1-EINT1, bit2-EINT2,bit3-EINT3	
	NVIC_EnableIRQ(EINT3_IRQn);						//core_cm3.h
	  
	while(1) ;
}

void EINT3_IRQHandler(void)
{
		LPC_SC->EXTINT = 0x00000008;				//cleares the interrupt
	
		if(int3_flag == 0x00)								//when flag is '0' off the LED
		{
			LPC_GPIO2->FIOCLR = 0x00001000;
			int3_flag = 0xff;
		}										
		else																//when flag is FF on the LED
		{
			LPC_GPIO2->FIOSET = 0x00001000;
			int3_flag = 0;
		}
}

