#include <stdio.h>

int lower_one_mask(int n) {
    int size = sizeof(int);
    unsigned x = ~0;
    x >>= ((size << 3) - n);
    return x;
}

int main() {
    printf("%.8x\n", lower_one_mask(6));
    printf("%.8x\n", lower_one_mask(17));

    return 0;
}