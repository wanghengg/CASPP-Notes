#include <stdio.h>

unsigned srl(unsigned x, int k) {
    unsigned xsra = (int)x >> k;
    unsigned w = sizeof(int) << 3;
    // (1 << k) - 1刚好使低k位全为1，然后再左移w - k位，使最高k位全部位1，
    // 最后取反使高k位全为0，低w-k位全为1，即为掩码
    unsigned mask = ~(((1 << k) - 1) << (w - k));
    return xsra & mask;
}

int sra(int x, int k) {
    int xsrl = (unsigned) x >> k;
    unsigned w = sizeof(int) << 3;
    unsigned y = (1 << (w - k - 1)) & xsrl;
    y = (y << 1) - 1;
    unsigned mask = ~y;
    return xsrl | mask;
}

int main() {
    unsigned x1 = 0xf1000000;
    int x2 = 0xf1000000;
    printf("%x\n", srl(x1, 2));
    printf("%x\n", sra(x2, 2));

    return 0;
}