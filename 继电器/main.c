//
// Created by Li on 2017/7/23.
//
#include <reg52.h>

sbit K1 = P0 ^0;
sbit RELAY = P1 ^4;

// 继电器
void main() {
    if (K1 == 0) {
        RELAY = 0;
    } else {
        RELAY = 1;
    }
}
