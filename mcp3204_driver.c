#include <LPC21xx.H>
#include "header20.h"

unsigned short int mcp3204_adc_read(int ch_num)
{
unsigned char byteH=0,byteL=0,channel=0;
unsigned short int res;

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