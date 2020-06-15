#include <stdio.h>

int any_odd_one(unsigned x) {
    return (x & 0xaaaaaaaa) != 0;
}

int main() {
    printf("%d\n", any_odd_one(1011));
    return 0;
}