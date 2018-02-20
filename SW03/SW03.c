/***********************************************************************/
/*                                                                     */
/*  FILE        :SW03.c                                                */
/*  DATE        :Fri, Nov 17, 2017                                     */
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

typedef struct{
	int sw1;
	int sw2;
	int sw3;
	int sw4;
}SwitchStats;

SwitchStats ss;

void SW1(){
	ss.sw1=(ss.sw1==0)?1:0;
	if(ss.sw1==0){
		IO.PDR3.BIT.B1 = 1;
	}else{
		IO.PDR3.BIT.B1 = 0;
	}
	IRR1.BIT.IRRI0=0;
}
void SW2(){
	ss.sw2=(ss.sw2==0)?1:0;
	if(ss.sw2==0){
		IO.PDR3.BIT.B2 = 1;
	}else{
		IO.PDR3.BIT.B2 = 0;
	}
	IRR1.BIT.IRRI1=0;
}
void SW3(){
	ss.sw3=(ss.sw3==0)?1:0;
	if(ss.sw3==0){
		IO.PDR3.BIT.B3 = 1;
	}else{
		IO.PDR3.BIT.B3 = 0;
	}
	IRR1.BIT.IRRI2=0;
}
void SW4(){
	ss.sw4=(ss.sw4==0)?1:0;
	if(ss.sw4==0){
		IO.PDR3.BIT.B4 = 1;
	}else{
		IO.PDR3.BIT.B4 = 0;
	}
	IRR1.BIT.IRRI3=0;
}

void wait(unsigned int count){
	int i,n;
	for(n=0;n<10;n++){	
		for(i=0;i<count*10000;i++){
		
		}
	}
}
void main(void)
{
	IO.PCR3 = 0xFF;
	
	set_imask_ccr(1);
	
	IO.PMR1.BYTE=0xF0;
	IEGR1.BYTE=0x00;
	IENR1.BYTE=0x0F;
	IRR1.BYTE=0x30;
	
	set_imask_ccr(0);
	
	for(;;){
		IO.PDR3.BIT.B7 = 1;
		wait(10000);
		IO.PDR3.BIT.B7 = 0;
		wait(10000);
	}
}

#ifdef __cplusplus
void abort(void)
{

}
#endif