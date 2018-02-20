/***********************************************************************/
/*                                                                     */
/*  FILE        :ENC01.c                                               */
/*  DATE        :Fri, Dec 15, 2017                                     */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :H8/3687                                               */
/*                                                                     */
/*  This file is generated by Renesas Project Generator (Ver.4.16).    */
/*                                                                     */
/***********************************************************************/
                  
#include "iodefine.h";
#include <machine.h>
#include "lcd_func.h";

#define MSK_WKP0 0x01
#define MSK_WKP1 0x02

void main(void);
#ifdef __cplusplus
extern "C" {
void abort(void);
}
#endif

void WKP_func(){
	static int count=0;
	lcd_clear();
	if((IWPR.BYTE&MSK_WKP0)==MSK_WKP0){
		if(IWPR.BIT.IWPF1==0)
			count++;
		else
			count--;
		
		lcd_xy(1,1);
		lcd_dataout(count);
		IWPR.BIT.IWPF0=0;
		IWPR.BIT.IWPF1=0;
		return;
	}
}

void main(void)
{
	lcd_init();
	IO.PCR5=0xF0;
	IO.PUCR5.BYTE=0x3F;
	
	set_imask_ccr(1);
	
	IO.PMR5.BYTE=0x03;
	IEGR2.BYTE=0x03;
	IENR1.BIT.IENWP=1;
	IWPR.BYTE=0x00;
	
	set_imask_ccr(0);
	
	while(1);
}

#ifdef __cplusplus
void abort(void)
{

}
#endif