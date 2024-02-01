#include <LPC21xx.H>
#include "header20.h"

#define cs (1<<7)
#define SPIF ((S0SPSR>>7)&1)

void spi0_init(void)
{
PINSEL0|=0x1500;
IODIR0|=cs;
IOSET0|=cs;
S0SPCR=0x20;
S0SPCCR=15;
}

unsigned char spi0(unsigned char data)
{
S0SPDR=data;
while(SPIF==0);
return S0SPDR;
}



unsigned short int mcp3204_adc_read(int ch_num)
{
unsigned char byteH=0,byteL=0,channel=0;
unsigned short int res=0;

channel=ch_num<<6;

IOCLR0=cs;
spi0(0x06); //1st byte
byteH=spi0(channel);  //2nd byte
byteL=spi0(0x00);	  //3rd byte
IOSET0=cs;

byteH&=0x0f;
res=(byteH<<8)|(byteL);

return res;

}