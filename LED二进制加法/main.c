#include <reg52.h>

void delay1s(void)   //误差 -0.00000000024us
{
    unsigned char a,b,c;
    for(c=95;c>0;c--)
        for(b=26;b>0;b--)
            for(a=185;a>0;a--);
}

// LED二进制加法
void main(){
    unsigned char num = 1;
    while(1){
        P0 = num;
        delay1s();
        num++;
    }
}

