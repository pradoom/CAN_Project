#include <LPC21xx.H>
#include"Header.h"
CAN1 v1;
int main()
{
	
	CAN_INIT();
	
	
	while(1)
	{
		CAN_RX(&v1);
		if(v1.rtr==0)
		{
			
		}
		
	}
	
}
