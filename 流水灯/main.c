#include <reg52.h>

void delay100ms(void);

// 流水灯
void main(){
    P0 = 0x01;
    while(1){
        P0=P0<<1;
        if(P0 == 0x00){
            P0 = 0x01;
        }
        delay100ms();
    }
}

void delay100ms(void)   //误差 -0.000000000021us
{
    unsigned char a,b,c;
    for(c=35;c>0;c--)
        for(b=10;b>0;b--)
            for(a=130;a>0;a--);
}
