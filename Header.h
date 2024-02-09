//structure

typedef struct CAN_1
{
	unsigned int id;
	unsigned char rtr;
	unsigned char dlc;
	unsigned int byteA;//lower byte data
	unsigned int byteB;//upper byte data
}CAN1;

extern void CAN_INIT(void);

extern void CAN1_TX(CAN1 C1);

extern void dalley_sec(unsigned int sec);

extern void dalley_ms(unsigned int ms);
























