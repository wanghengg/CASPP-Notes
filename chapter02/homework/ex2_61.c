#include <stdio.h>

int A(int x) {
    return !(~x);   // -1的补码表示为0xFFFFFFFF
}

int B(int x) {
    return !x;
}

int C(int x) {
    return !((x & 0xff) ^ 0xff);
}

int D(int x) {
    return !((x >> ((sizeof(int) - 1) << 3)) & 0xff);
}

int main() {
    printf("%d\n", A(-1));
    printf("%d\n", B(0));
    printf("%d\n", C(0x34ff));
    printf("%d\n", D(0x1ffffff));
    return 0;
}