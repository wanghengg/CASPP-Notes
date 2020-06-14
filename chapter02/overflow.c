#include <stdio.h>
#include <limits.h>

// 判断无符号数x,y相加之后是否溢出，不溢出返回1
int uadd_ok(unsigned x, unsigned y) {
    unsigned sum = x + y;
    if (sum < x)
        return 0;
    return 1;
}

// 判断有符号数x,y相加之后是否溢出
int tadd_ok(int x, int y) {
    int sum = x + y;
    if ((x < 0 && y < 0 && sum >= 0) &&
            (x > 0 && y > 0 && sum <= 0))
        return 0;
    return 1;
}

// 判断有符号数相减是否溢出，练习2.32
int tsub_ok(int x, int y) {
    if (y != INT_MIN)
        return tadd_ok(x, -y);
    else if (x > 0)
        return 0;
    else
        return 1;
}

int main() {
    int x = -1, y = INT_MIN;
    printf("%d", tsub_ok(x, y));
    return 0;
}