#include <LPC21xx.H>
#include"Header.h"

void CAN_INIT(void)
{
	PINSEL1|=0x00040000;//p0.25 ->RD1
	VPBDIV=1;//Pclk=60
	C1MOD=1;//select reset
	C1BTR=0x001C001D;//125 kbps
	AFMR=2;//accept all incoming message
	C1MOD=0;//cancle reset mode
}

void CAN1_TX(CAN1 C1)
{
	C1TID1=C1.id;
	C1TFI1=C1.dlc<<16;//rtr=0
	if(C1.rtr==0)
	{
		C1TDA1=C1.byteA;
		C1TDB1=C1.byteB;
	}
}

