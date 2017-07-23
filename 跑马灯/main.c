#include <reg52.h>

void main(){
    P0 = 0x01;
    while(1){
        if(P0>=0x00){
        P0=P0<<1;
           }
    }
}