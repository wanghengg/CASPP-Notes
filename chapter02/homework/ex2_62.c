#include <stdio.h>

int int_shifts_are_arithmetic(void ) {
    int x = 0x01 << (sizeof(int) << 3 - 1); // 对于32位int，左移31位
    // 如果是算术移位，那么负数右移之后最高位肯定为1，和0x80000000按位与之后得到0x80000000
    return x == (x & (-3 >> 1));
}

int main() {
    printf("%d", int_shifts_are_arithmetic());
    return 0;
}