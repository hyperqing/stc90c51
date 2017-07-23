#include <reg52.h>

void delay100ms(void);

void main(){
    // 用于区分方向
    unsigned char direction;
    direction = 0;
    P0=0x01;
    while(1){
        if(direction == 0){
            P0=P0<<1;
            // 已经到左端的情况，则换向
            if(P0==0x80){
                direction = 1;
            }
        }else{
            P0=P0>>1;
            // 已经到右端的情况，则换向
            if(P0==0x01){
                direction = 0;
            }
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
