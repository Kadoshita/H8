/***********************************************************************/
/*                                                                     */
/*  FILE        :lcd_func.c                                            */
/*  DATE        :Wed, Aug 27, 2008                                     */
/*  DESCRIPTION :LCD Display Program                                   */
/*  CPU TYPE    :H8/3687                                               */
/*                                                                     */
/*  This file is generated by Hitachi Project Generator (Ver.2.1).     */
/*                                                                     */
/***********************************************************************/
// ���֐��̊T�v�� lcd_func
//�ELCD�C���^�[�t�F�[�X�f�[�^���S�r�b�g�œ���\
//�EBF�`�F�b�N�ȗ�


#include "lcd_func.h"


#define BOARD_BUG


void _lcd_wait(unsigned int wait_time)  // �҂����Ԑݒ�֐�
{                                   //    wait_time=�P�ŁC��Pms���x�̃I�[�_�[
    unsigned int    loop1;
    unsigned int    loop2;
    for( loop1 =0; loop1 < wait_time; loop1++){
        for( loop2 =0; loop2 < loop_const; loop2++);
    }
}

void lcd_pcr_init(void)
{
#ifndef BOARD_BUG
	LCD_CB_PCR.BIT.RS  = OUTPUT_BIT;               //    LCD RW  �̃R���g���[���r�b�g���o�̓��[�h�ɐݒ�
	LCD_CB_PCR.BIT.E   = OUTPUT_BIT;               //    LCD E   �̃R���g���[���r�b�g���o�̓��[�h�ɐݒ�
	LCD_CB_PCR.BIT.RW  = OUTPUT_BIT;               //    LCD RS  �̃R���g���[���r�b�g���o�̓��[�h�ɐݒ�

	LCD_DB_PCR.BIT.DATA = OUTPUT_BYTE;             //    LCD DATA�̃R���g���[���r�b�g���o�̓��[�h�ɐݒ�
#else
	LCD_CB_PCR.BYTE   = OUTPUT_BYTE;
	LCD_CB_PCR.BIT.OT = INPUT_BYTE;

	LCD_DB_PCR.BYTE     = OUTPUT_BYTE;             //    LCD DATA�̃R���g���[���r�b�g���o�̓��[�h�ɐݒ�
//	LCD_DB_PCR.BIT.OTHR = INPUT_BYTE;              //    LCD OTHR�̃R���g���[���r�b�g����̓��[�h�ɐݒ�
#endif
}

void lcd_write_data(unsigned char data, unsigned char rs)
{                                           // LCD�R�}���h�^�f�[�^�������݊֐��i4�r�b�g�p�j
    unsigned char upper_data;               //    �f�[�^�R�[�h���4�r�b�g�̊i�[�ϐ�
    unsigned char lower_data;               //    �f�[�^�R�[�h����4�r�b�g�̊i�[�ϐ�
                                            //    
	lower_data = data;                      //    �f�[�^�R�[�h����4�r�b�g�𒊏o
	upper_data = data >> 4;                 //    �f�[�^�R�[�h���4�r�b�g�𒊏o
                                            //    
    _lcd_wait(1);                           //    ��1ms�E�G�C�g(�e�X�g������̕\�����Ԃ̊Ԋu�j----(lcd_test_4bit.c����ύX)

	LCD_CB.BIT.RS   = rs;                       //    rs=0(LCD_CMD)�Crs=1(LCD_DAT)
    LCD_CB.BIT.RW   = LCD_WRITE;                //    LCD �������݃��[�h�ݒ� (R/W=0) 
    LCD_CB.BIT.E    = 1;                        //    LCD E  --->High���x��
    LCD_DB.BIT.DATA = upper_data;               //    �f�[�^�R�[�h���4�r�b�g��LCD�֏�������
    LCD_CB.BIT.E    = 0;                        //    LCD E  --->Low���x��
    LCD_CB.BIT.E    = 1;                        //    LCD E  --->High���x��
    LCD_DB.BIT.DATA = lower_data;               //    �f�[�^�R�[�h����4�r�b�g��LCD�֏�������
    LCD_CB.BIT.E    = 0;                        //    LCD E  --->Low���x��
}

void lcd_init(void)                         // LCD���C�j�V�����C�Y����֐��i4�r�b�g�p�j
{                                           //    �N������1�񂾂��Ăяo��
    lcd_pcr_init();

    LCD_CB.BIT.RS   = LCD_CMD;                  //    LCD �R�}���h���[�h�ɐݒ�
    LCD_CB.BIT.RW   = LCD_WRITE;                //    LCD �������݃��[�h�ݒ� (R/W=0) 
    LCD_CB.BIT.E    = 0;                        //    LCD E  --->Low���x��
                                              
    _lcd_wait(15);                              //    ��15ms���x�̃E�G�C�g
    LCD_CB.BIT.E    = 1;                        //    LCD E  --->High���x��
    LCD_DB.BIT.DATA = LCD_INIT8B;               //    LCD �t�@���N�V�����Z�b�g(�f�[�^��8�r�b�g)
    LCD_CB.BIT.E    = 0;                        //    LCD E  --->Low���x��
                                              
    _lcd_wait(5);                               //    ��5ms���x�̃E�G�C�g
    LCD_CB.BIT.E    = 1;                        //    LCD E  --->High���x��
    LCD_DB.BIT.DATA = LCD_INIT8B;               //    LCD �t�@���N�V�����Z�b�g(�f�[�^��8�r�b�g)
    LCD_CB.BIT.E    = 0;                        //    LCD E  --->Low���x��
                                              
    _lcd_wait(1);                               //    ��1ms���x�̃E�G�C�g
    LCD_CB.BIT.E    = 1;                        //    LCD E  --->High���x��
    LCD_DB.BIT.DATA = LCD_INIT8B;               //    LCD �t�@���N�V�����Z�b�g(�f�[�^��8�r�b�g)
    LCD_CB.BIT.E    = 0;                        //    LCD E  --->Low���x��
                                              
    _lcd_wait(1);                               //    ��1ms���x�̃E�G�C�g
    LCD_CB.BIT.E    = 1;                        //    LCD E  --->High���x��
    LCD_DB.BIT.DATA = LCD_INIT4B;               //    LCD �t�@���N�V�����Z�b�g(�f�[�^��4�r�b�g)
    LCD_CB.BIT.E    = 0;                        //    LCD E  --->Low���x��


    lcd_write_data(LCD_FCSET4B, LCD_CMD);   //    LCD �t�@���N�V�����Z�b�g(�f�[�^��4�r�b�g),
                                            //          N=1(1/16�f���[�e�B), F=0(5*8�h�b�g)
    lcd_write_data(LCD_DISP_OFF, LCD_CMD);  //    LCD �\���I���^�I�t�R���g���[���̐ݒ�
                                            //          D=0(�\���I�t), C=0(�J�[�\���Ȃ�), B=0(�u�����N�Ȃ�)
    lcd_write_data(LCD_CLAR, LCD_CMD);      //    LCD �\���N���A�̐ݒ�
    lcd_write_data(LCD_ENTSET, LCD_CMD);    //    LCD �G���g�����[�h�̐ݒ�
                                            //          I/D=1(�C���N�������g), S=0(�\���V�t�g���Ȃ��j   
    lcd_write_data(LCD_DISP_NCUR, LCD_CMD); //    LCD �\���I���^�I�t�R���g���[���̐ݒ�--------------------(lcd_test_4bit.c����ύX)
                                            //      D=1(�\���I��), C=1(�J�[�\���Ȃ�), B=0(�u�����N�Ȃ�)
}

void lcd_putc(unsigned char c)
{
	lcd_write_data(c, LCD_DAT);
}

void lcd_puts( char *str)                   // ������\���֐�
{                                           //     (�������LCD�ɕ\��������)
    while(*str) {                           //     
        lcd_write_data(*str, LCD_DAT);      //     �����������\��
        str++;
    }
}

void lcd_xy(unsigned char x, unsigned char y)   // LCD �\���ʒu��ݒ肷��֐�
{                                               //     ��(x=1�`16)�C�s(y=1,2�j�͈̔�
        unsigned char adr;                      //     
        //adr=((x-1)+(y-1)*0x40) | 0x80;        //     �A�h���X�̎Z�o
        adr=((x-1)+(y-1)*0x40+0x80) | 0x80;
		lcd_write_data(adr, LCD_CMD);           //     DDRAM�ɃA�h���X�f�[�^����������
}

void lcd_dataout( unsigned long data )          // ���l�f�[�^��LCD�ɕ\������֐�--------------------(lcd_test_4bit.c����ǉ�)
{                                               //
    unsigned char temp;                         //
    char strtemp[16];                           //     �����R�[�h�̊i�[�ϐ����`
    int i, k;                                   //
    i=0;                                        //
    do {                                        //
        temp = data % 10;                       //     ���ʂ̌����琔���𒊏o
        strtemp[i++] = temp + '0';              //     �����𕶎��R�[�h�ɕϊ�
    } while (( data /= 10 ) != 0);              //     ���l�̌����܂Ń��[�v
    i--;                                        //
    for( k=i; k>=0; k-- ) {                     //     ��ʂ̌����珇��
        lcd_write_data( strtemp[k], LCD_DAT);   //     ���l������\��
    }                                           //
}

void lcd_puti(int data)
{
	int tmp;
	tmp = data / 10;
	if(tmp > 0)
		lcd_putc('0' + tmp);
	else
		lcd_putc(' ');
	lcd_putc('0' + (data % 10));
}

void lcd_clear()
{
	lcd_write_data( LCD_CLAR, LCD_CMD);
}


// 
void init_lcd(){ lcd_init(); }
void putc_lcd(unsigned char c){ lcd_putc(c); }
void puti_lcd(int data){ lcd_puti(data); }
void clear_lcd(){ lcd_clear(); }
void write_data_lcd(unsigned char data, unsigned char rs){ lcd_write_data(data, rs); }