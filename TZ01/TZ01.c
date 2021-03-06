/***********************************************************************/
/*                                                                     */
/*  FILE        :TZ01.c                                                */
/*  DATE        :Fri, Dec 01, 2017                                     */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :H8/3687                                               */
/*                                                                     */
/*  This file is generated by Renesas Project Generator (Ver.4.16).    */
/*                                                                     */
/***********************************************************************/
                  
#include "iodefine.h"
#include <machine.h>

void main(void);
#ifdef __cplusplus
extern "C" {
void abort(void);
}
#endif
void SW1_Motor_ON(){
	TZ0.GRC=12500;
	TZ0.TCNT=0;
	TZ.TOER.BIT.EC0=0;
	TZ.TSTR.BIT.STR0=1;
	IRR1.BIT.IRRI0=0;
}
void SW2_Motor_OFF(){
	TZ.TOER.BIT.EC0=1;
	TZ.TSTR.BIT.STR0=0;
	IRR1.BIT.IRRI1=0;
}
void main(void){
	set_imask_ccr(1);
	IO.PMR1.BYTE=0x30;
	IEGR1.BYTE=0x00;
	IENR1.BYTE=0x0F;
	IRR1.BYTE=0x30;
	
	TZ0.TCR.BYTE=0x23;
	TZ0.POCR.BYTE=0xF8;
	TZ.TPMR.BYTE=0x8E;
	TZ.TOCR.BYTE=0x0C;
	TZ0.GRA=25000;
	TZ0.GRC=0;
	TZ0.GRD=0;
	set_imask_ccr(0);
	
	while(1);
}

#ifdef __cplusplus
void abort(void)(int s
{

}
#endif
