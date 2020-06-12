//
// Created by wangheng on 2020/6/12.
//

#include <stdio.h>

typedef unsigned char *byte_pointer;    // 指向unsigned char的指针

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; ++i) {
        printf("%.2x", start[i]);   // 以２位二进制打印
    }
    printf("\n");
}

int fun1(unsigned word) {
    return (int)((word << 24) >> 24);
}

int fun2(unsigned word) {
    return (((int)word << 24) >> 24);   // 有符号数算数右移，在左侧移出的位上添加最高位值
}

int main() {
    int w1 = 0x00000076;
    printf("fun1(w4) = %.6x, fun2(w4) = %.6x\n", fun1(w1), fun2(w1));
    int w2 = 0x87654321;
    printf("fun1(w2) = %.6x, fun2(w2) = %.6x\n", fun1(w2), fun2(w2));
    int w3 = 0x000000c9;
    printf("fun1(w3) = %.6x, fun2(w3) = %.6x\n", fun1(w3), fun2(w3));
    int w4 = 0xedcba987;
    printf("fun1(w4) = %.6x, fun2(w4) = %.6x\n", fun1(w4), fun2(w4));

    return 0;
}