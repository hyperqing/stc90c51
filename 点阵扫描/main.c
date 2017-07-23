//
// Created by Li on 2017/7/23.
//
#include <reg52.h>
#include <intrins.h>

#define uchar unsigned char


sbit SI = P3 ^4; // 数据位SER
sbit RCK = P3 ^5; // 输出存储器锁存时钟线
sbit SCK = P3 ^6; // 数据输入时钟线

void delay50ms(void);

void hc595_send(uchar data_list[]);

uchar tab0[] = {0x00, 0x01, 0x00, 0x02, 0x00, 0x04, 0x00, 0x08, 0x00, 0x10, 0x00, 0x20, 0x00, 0x40, 0x00, 0x80,
                0x01, 0x00, 0x02, 0x00, 0x04, 0x00, 0x08, 0x00, 0x10, 0x00, 0x20, 0x00, 0x40, 0x00, 0x80, 0x00};

uchar tab1[] =  {128,0,0,1,252,63,4,0,4,1,4,1,4,1,244,63,4,1,132,2,132,2,68,4,36,8,18,48,0,0,0,0};

void main() {
    int k, i, ms;
    uchar data_list[] = {0x5f, 0xfa, 0xff, 0xff};
    uchar data_listo[] = {0x00, 0x00, 0x80, 0x01};

//    hc595_send(data_list);
//    hc595_send(data_listo);


    i = 80;                                //显示时间
    while (1) {
        //--显示"亲"--//
        for (ms = i; ms > 0; ms--) {
            for (k = 0; k < 16; k++) {
                uchar asd[4];
                asd[0] = ~tab1[2 * k + 1];
                asd[1] = ~tab1[2 * k];
                asd[2] = tab0[2 * k];
                asd[3] = tab0[2 * k + 1];
                hc595_send(asd);
            }
        }
    }

}

/**
 * 发送数据到74HC595
 * @param data 4字节数组，为方便阅读，从高到低，[0]是最高位，以此类推
 */
void hc595_send(uchar data_list[]) {
    unsigned char i, j;
    for (i = 0; i < 4; i++) {
        uchar item = data_list[i];
        for (j = 0; j < 8; j++) {
            // 得到最右最低位
            SI = item >> 7;
            // 右移去掉一个最低位
            item <<= 1;
            // 制造上升沿存储数据
            SCK = 0;
            SCK = 1;
            _nop_(); // 空指令
        }
    }
    // 上升沿，输出锁存器值，下降沿存储器状态保持
    RCK = 0;
    RCK = 1;
    RCK = 0;
}

void delay50ms(void)   //误差 -0.00000000001us
{
    unsigned char a, b;
    for (b = 97; b > 0; b--)
        for (a = 236; a > 0; a--);
}
