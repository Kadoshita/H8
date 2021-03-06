/***********************************************************************/
/*                                                                     */
/*  FILE        :serial02R.c                                           */
/*  DATE        :Fri, Dec 22, 2017                                     */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :H8/3687                                               */
/*                                                                     */
/*  This file is generated by Renesas Project Generator (Ver.4.16).    */
/*                                                                     */
/***********************************************************************/
                  
#include "iodefine.h";
#include <machine.h>

unsigned char RevDt;

void main(void);
#ifdef __cplusplus
extern "C" {
void abort(void);
}
#endif

void wait(){
	int i;
	for(i=0;i<10000;i++){
		
	}
}

void func_sci(){
	if(SCI3_2.SSR.BIT.RDRF==1){
		RevDt=SCI3_2.RDR;
		if((RevDt&0x02)==0x02){
			IO.PDR2.BIT.B0=~IO.PDR2.BIT.B0;
		}else{
			IO.PDR3.BYTE=~IO.PDR3.BYTE;
		}
		
		SCI3_2.SSR.BIT.RDRF=0;
	}else{
		SCI3_2.SSR.BIT.OER=0;
		SCI3_2.SSR.BIT.FER=0;
		SCI3_2.SSR.BIT.PER=0;
	}
}


void main(void)
{
	IO.PCR2=0x01;
	IO.PCR3=0xFF;
	
	SCI3_2.SCR3.BIT.RE=0;
	SCI3_2.SMR.BYTE=0x00;
	SCI3_2.BRR=64;
	
	SCI3_2.SSR.BIT.OER=0;
	SCI3_2.SSR.BIT.FER=0;
	SCI3_2.SSR.BIT.PER=0;
	
	wait();
	
	SCI3_2.SCR3.BIT.RE=1;
	SCI3_2.SCR3.BIT.RIE=1;
	
	IO.PDR3.BYTE=0xAA;
	
	while(1);
}

#ifdef __cplusplus
void abort(void)
{

}
#endif
