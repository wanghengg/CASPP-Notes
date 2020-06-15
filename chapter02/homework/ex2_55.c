#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    for (size_t i = 0; i < len; ++i)
        printf("%.2x", start[i]);
    printf("\n");
}

void show_short(short x) {
    show_bytes((byte_pointer) &x, sizeof(short));
}

void show_unsigned(unsigned x) {
    show_bytes((byte_pointer) &x, sizeof(unsigned));
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_long(long x) {
    show_bytes((byte_pointer) &x, sizeof(long));
}

void show_long_long(long long x) {
    show_bytes((byte_pointer) &x, sizeof(long long));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_double(double x) {
    show_bytes((byte_pointer) &x, sizeof(double));
}

int main() {
    long long x = 123;
    show_long_long(x);
    double y = 3.14;
    show_double(y);
    return 0;
}