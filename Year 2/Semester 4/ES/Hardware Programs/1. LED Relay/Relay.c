#include <LPC17xx.H>
int main(void)
{
	LPC_PINCON->PINSEL1 = 0x00000000;								//P0.24,P0.25 GPIO
	LPC_GPIO0->FIODIR = 0x03000000;									//P0.24 configured output for buzzer,P0.25 configured output for Relay/Led
   while(1)
   {
				if(!(LPC_GPIO2->FIOPIN & 0x00000800))			//Is GP_SW(SW4) is pressed??
				{
					 LPC_GPIO0->FIOSET = 0x03000000;				//relay on
				}	
				else
				{
					 LPC_GPIO0->FIOCLR = 0x03000000;				//relay off
				}
	 }
}																									//end int main(void)
