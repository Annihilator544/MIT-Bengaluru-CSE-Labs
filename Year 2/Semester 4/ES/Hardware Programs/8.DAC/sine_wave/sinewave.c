/*********************************************************************
 * EXP5:External DAC interface (Sine Wave)
 * Developed by
 * Advanced Electronics Systems, Bengaluru
 *--------------------------------------------------------------------
 * Controller	: LPC1768
 * Project		: ALS-SDA-ARMCTXM3-06
 * Description	: This example explains about how Sine Wave is generated. Here Y = Asin(@) since 48 samples are 
 used to generate the sine wave so 360/48 = 7.5 degree/sample. 
 for example for 15deg Y = 1.25 + Asin(@) = 1.25 + 1.25sin(15)  = 1.5735
 
				for 2.5V    -----------------> 0xff
			then  1.5735V -----------------> 0xA1
 
   
			|0xff		  .  .																				--|2.5V for Uni polar
			|      .        .																				|
			|   . 15            .																		|
			| .                   .																	|
0x7f	|-------------------------------------------------			|1.25V
			|                         .										.					|
			|                           .								.						|
			|                              .         .							|
	____|_________________________________.___._________________--|0V
			|0x00

***********************************************************************/

#include <LPC17xx.H>

int count=0,sinevalue,value;
unsigned char sine_tab[49]=
	{ 0x80,0x90,0xA1,0xB1,0xC0,0xCD,0xDA,0xE5,0xEE,0xF6,0xFB,0xFE,
      0xFF,0xFE,0xFB,0xF6,0xEE,0xE5,0xDA,0xCD,0xC0,0xB1,0xA1,0x90,
      0x80,0x70,0x5F,0x4F,0x40,0x33,0x26,0x1B,0x12,0x0A,0x05,0x02,
      0x00,0x02,0x05,0x0A,0x12,0x1B,0x26,0x33,0x40,0x4F,0x5F,0x70,0x80};

int main(void)
{
	LPC_PINCON->PINSEL0 &= 0xFF0000FF ;						// Configure P0.0 to P0.15 as GPIO
  LPC_GPIO0->FIODIR  |= 0x00000FF0 ;
	LPC_GPIO0->FIOMASK = 0XFFFFF00F;
 
	count = 0;
	while(1)
	{
		for(count=0;count<48;count++)
		{
			sinevalue = sine_tab[count];//+0X10 ;
			value= 0x00000FF0 & (sinevalue << 4);
			LPC_GPIO0->FIOPIN = value;
		}
	}
}

 
    
 



