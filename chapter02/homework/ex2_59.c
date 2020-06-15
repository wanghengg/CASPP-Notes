#include <stdio.h>

int merge(int x, int y) {
    return (x & 0x000000FF) | (y & 0xFFFFFF00);
}

int main() {
    int a = merge(0x89ABCDEF, 0x76543210);
    printf("%x\n", a);
    return 0;
}