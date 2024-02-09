#include <LPC21xx.H>
#include"Header.h"
CAN1 v;
int main()
{
	CAN_INIT();
	
	v.id=0x123;
	v.rtr=0;
	v.dlc=8;
	v.byteA=0x44332211;
	v.byteB=0x88776655;
	
	while(1)
	{
		CAN1_TX(v);
		//dalley_ms(1000);
	}
}

