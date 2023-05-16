// program to generate square wave with DAC interface
/*********************************************************************
 * EXP5:External DAC interface (Square Wave)
 * Developed by
 * Advanced Electronics Systems, Bengaluru
 *--------------------------------------------------------------------
 * Controller	: LPC1768
 * Project		: ALS-SDA-ARMCTXM3-06
 * Description	: This example explains about how Sqaure Wave is generated.P0.4 to P0.11 are used to get the Digital values.
 
			
       	0xff  ________
             |				|					|
             |				|					|
             | 				|					|
						 |				|					|
				0x00 |				|_________|
 
 ***************************************************************************/
#include <LPC17xx.H>

void delay(void);

int main ()
{
		LPC_PINCON->PINSEL0 &= 0xFF0000FF ;						// Configure P0.4 to P0.11 as GPIO
    LPC_GPIO0->FIODIR  |= 0x00000FF0 ;
		LPC_GPIO0->FIOMASK = 0XFFFFF00F;
	while(1)
    {
    	LPC_GPIO0->FIOPIN  = 0x00000FF0 ;
        delay();
        LPC_GPIO0->FIOCLR  = 0x00000FF0 ;
        delay();
    }
}   
 
void delay(void)
{
	unsigned int i=0;
   	for(i=0;i<=9500;i++);
}
 
