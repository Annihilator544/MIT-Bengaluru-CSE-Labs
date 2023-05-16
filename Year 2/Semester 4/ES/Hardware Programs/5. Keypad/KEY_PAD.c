#include <LPC17xx.h>
#include "lcd.h"
void scan(void);

unsigned char Msg1[14] = "ALS BENGALURU";
unsigned char Msg2[13] = "KEY PRESSED=";
unsigned char col,row,var,flag,key,*ptr;
unsigned long int i,var1,temp,temp3;

unsigned char SCAN_CODE[16] = {0x1E,0x1D,0x1B,0x17,
 							  	0x2E,0x2D,0x2B,0x27,
							  	0x4E,0x4D,0x4B,0x47,
							  	0x8E,0x8D,0x8B,0x87};

unsigned char ASCII_CODE[16] = {'0','1','2','3',
 								 '4','5','6','7',
								 '8','9','A','B',
								 'C','D','E','F'};

int main(void)
{
	LPC_PINCON->PINSEL3 = 0x00000000; 			//P1.20 to P1.23 MADE GPIO
	LPC_PINCON->PINSEL0 = 0x00000000;  			//P0.15 as GPIO
	LPC_PINCON->PINSEL1 = 0x00000000; 			//P0.16 t0 P0.18 made GPIO
	LPC_GPIO0->FIODIR &= ~0x00078000; 			//made INput P0.15 to P0.18 (cols)
	LPC_GPIO1->FIODIR |= 0x00F00000; 				//made output P1.20 to P1.23 (rows)
	LPC_GPIO1->FIOSET = 0x00F00000;  

	lcd_init();

	temp1 = 0x80;														//point to first line of LCD
	lcd_com();
	delay_lcd(800);
	lcd_puts(&Msg1[0]);	 										//display the messsage

	temp1 = 0xC0;														//point to first line of LCD
	lcd_com();
	delay_lcd(800);
	lcd_puts(&Msg2[0]);	 										//display the messsage

	while(1)
	{
		while(1)
		{
			for(row=1;row<5;row++)
			{
				if(row == 1)
				var1 = 0x00100000;
				else if(row == 2)
				var1 = 0x00200000;
				else if(row == 3)
				var1 = 0x00400000;
				else if(row == 4)
				var1 = 0x00800000;
			
				temp = var1;

				LPC_GPIO1->FIOSET = 0x00F00000;
				LPC_GPIO1->FIOCLR = var1;

				flag = 0;
				scan();
				if(flag == 1)
				break;
		
			} 																	//end for(row=1;row<5;row++)

			if(flag == 1)
			break;
		
		}							 												//2nd while(1)

		for(i=0;i<16;i++)
		{
			if(key == SCAN_CODE[i])
			{
				key = ASCII_CODE[i];
				break;
			} 																//end if(key == SCAN_CODE[i])

		}																		//end for(i=0;i<16;i++)

		temp1 = 0xCC;
		lcd_com();
		delay_lcd(800);
		lcd_puts(&key);
		
	}																		//end while 1
}																			//end main

void scan(void)
{
 	unsigned long temp3;
	temp3 = LPC_GPIO0->FIOPIN;	
	temp3 &= 0x00078000;
	if(temp3 != 0x00078000)
	{
		for(i=0;i<500;i++);
		temp3 = LPC_GPIO0->FIOPIN;	
		temp3 &= 0x00078000;
		if(temp3 != 0x00078000)
		{
			flag = 1;
			temp3 >>= 15;									//Shifted to come at LN of byte
			temp >>= 16;									//shifted to come at HN of byte
			key = temp3|temp;	
		}																//2nd if(temp3 != 0x00000000)
	}																	//1st if(temp3 != 0x00000000)
}																		//end scan

