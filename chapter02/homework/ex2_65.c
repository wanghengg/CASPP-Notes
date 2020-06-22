#include <stdio.h>

#define POW(c) (1 << (c))   // 2^c
#define MASK(c) (((unsigned long)-1) / (POW(POW(c)) + 1)) // 以2^c为单位分组，相间地全为0和全为1

#define ROUND(n, c) (((n) & MASK(c)) + ((n) >> POW(c) & MASK(c)))

// 计算x中包含1的个数，如果1的个数为奇数，返回1，如果是偶数返回0
int add_ones(unsigned x) {
    x = ROUND(x, 0);    // 以2为分组单位，各组内前1为和后1位累加，得到原先这2位中1的数目
    x = ROUND(x, 1);    // 以4为分组单位，各组内前2为和后2位累加，得到原先这4位中1的数目
    x = ROUND(x, 2);    // 以8为分组单位，各组内前4为和后4位累加，得到原先这8位中1的数目
    x = ROUND(x, 3);    // 以2为分组单位，各组内前8为和后8位累加，得到原先这16位中1的数目
    x = ROUND(x, 4);    // 以2为分组单位，各组内前16为和后16位累加，得到原先这32位中1的数目
    return x & 1;
}

int main() {
    unsigned x1 = 0xff00ff00;
    unsigned x2 = 0xff01ff00;
    printf("%d\t%d\n", add_ones(x1), add_ones(x2));

    return 0;
}