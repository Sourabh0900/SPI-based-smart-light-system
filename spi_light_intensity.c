#include"header20.h"
#include <LPC21xx.H>



int main()
{
float vout,v;
unsigned short int ret;
uart0_init(9600);
uart0_tx_string("spi0 adc\r\n");
spi0_init();
lcd_init();
 IODIR0=1<<17;
 lcd_cmd(0x80);
lcd_string("LIGHT INTENSITY");
while(1)
{
 ret=mcp3204_adc_read(2);
 delay_ms(1000);
vout= (ret*3.3)/4095;
lcd_cmd(0x80);
v=(vout/3.3)*100;
lcd_cmd(0xc0);
lcd_float(v);
lcd_data('%');

if(ret>3000)
IOSET0=1<<17;
else
IOCLR0=1<<17;
//lcd_cmd(0x01);
//uart0_tx_string("\r\n");
}

}														                        


