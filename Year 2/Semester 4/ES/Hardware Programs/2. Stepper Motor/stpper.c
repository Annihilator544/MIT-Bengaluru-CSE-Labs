#include <LPC17xx.H>
void clock_wise(void);
void anti_clock_wise(void);
unsigned long int var1,var2;
unsigned int i=0,j=0,k=0;

int main(void)
{
	LPC_PINCON->PINSEL4 = 0x00000000;		//P2.0 to P2.3 GPIO
	LPC_GPIO2->FIODIR = 0x0000000F;			//P2.0 to P2.3 output
	while(1)
	{
		for(j=0;j<30;j++)           			//50 times in Clock wise Rotation
			clock_wise();				
		
		for(k=0;k<50000;k++);        			//Delay to show  anti_clock Rotation 
		
		for(j=0;j<30;j++)          				//50 times in  Anti Clock wise Rotation
			anti_clock_wise();

		for(k=0;k<50000;k++) ;       			//Delay to show clock Rotation 
	} 																	//End of while(1)
} 																		//End of main
void clock_wise(void)
{
		var1 = 0x00000001;         				//For Clockwise
    for(i=0;i<=3;i++)         				//for A B C D Stepping
	{
	   LPC_GPIO2->FIOCLR =  0X0000000F;
	   LPC_GPIO2->FIOSET =  var1;
		 var1 = var1<<1;        					//For Clockwise
     for(k=0;k<15000;k++) ;						//for step speed variation         
  }
}
void anti_clock_wise(void)
{
		var1 = 0x0000008;      						//For Anticlockwise
    for(i=0;i<=3;i++)       					//for A B C D Stepping
    {
	    LPC_GPIO2->FIOCLR =  0X0000000F;
			LPC_GPIO2->FIOSET =  var1;
			var1 = var1>>1;      						//For Anticlockwise
      for(k=0;k<15000;k++); 					//for step speed variation 
    }
}

