## 头文件
intrins.h
在C51单片机编程中，头文件INTRINS.H的函数使用起来，就会让你像在用汇编时一样简便.
内部函数 描述编辑
_crol_ 字符循环左移
_cror_ 字符循环右移
_irol_ 整数循环左移
_iror_ 整数循环右移
_lrol_ 长整数循环左移
_lror_ 长整数循环右移
_nop_ 空操作 （相当于8051 NOP 指令）
_testbit_ 测试并清零位 （相当于8051 JBC 指令）

## LED相关实验
LED对应接口

A B C D F E G H
D11 D12 D13 D14 D15 D16 D17 D18

### LED全亮

使用P0端口，P0对应J12，正反任意

### LED二进制加法

使用P0端口，P0.0对应J12.H

### 流水灯

同上

## 跑马灯

同上

## 键盘

### 键盘检测

```c
#define KEY_BOARD P1
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
```

### 八个独立按键

未按键时电路未通，按键一侧与端口等电势。如果按钮的另一侧是接地的，则按下按钮后将拉低电平。

使用P0、P1端口。
P0接J12，P0.0对应J12.H。
P1接JP5，P1.0对应JP5.K8。


