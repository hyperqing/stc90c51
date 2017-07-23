//
// Created by Li on 2017/7/23.
//
#include <reg52.h>

#define LED P0
#define KEY_BOARD P1

unsigned char keydown();

void delay10ms(void);

// 使用LED显示，当前所按的按钮
void main() {
    while (1) {
        LED = keydown();
    }

}

/**
 * 返回按下的字节码
 * @return
 */
unsigned char keydown() {
    // 检测两次,未按键盘都是高电平0xff
    unsigned char keyvalue = 0xff;
    if (KEY_BOARD != 0xff) {
        delay10ms();
        if (KEY_BOARD != 0xff) {
            keyvalue = KEY_BOARD;
        }
    }
    delay10ms();
    return keyvalue;
}

void delay10ms(void)   //误差 -0.000000000002us
{
    unsigned char a, b;
    for (b = 151; b > 0; b--)
        for (a = 29; a > 0; a--);
}

