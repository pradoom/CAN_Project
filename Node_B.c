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

#define RBS (C1GSR&1)

void CAN_RX(CAN1 *C1ptr)
{
		while(RBS==0);
		C1ptr->id=C1RID;
		C1ptr->dlc=(C1RFS>>16)&0xF;
		C1ptr->rtr=(C1RFS>>30)&1;
		if(C1ptr->rtr==0)
		{
			C1ptr->byteA=C1RDA;
			C1ptr->byteB=C1RDB;
		}
	
		C1CMR=(1<<2);//relese reciver buffer
	
}
