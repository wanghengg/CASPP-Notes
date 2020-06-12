#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer;    // 指向unsigned char的指针

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; ++i) {
        printf("%.2x", start[i]);   // 以２位二进制打印
    }
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val) {
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

int main() {
    test_show_bytes(12345);
    const char *s = "abcdef";
    show_bytes((byte_pointer)s, strlen(s));

    int tu = -1;
    unsigned u = (unsigned )tu;
    // 强制类型转换二进制位值不变，只是转换方式发生变化
    printf("v = %u, uv = %d\n", u, tu);

    short sx = -12345;
    unsigned short ux = sx;
    printf("(unsigned short) sx = %u:\t", ux);
    show_bytes((byte_pointer)&ux, sizeof(unsigned short ));
    unsigned uy = sx;   // (unsigned)sx 等价于　(unsigned)(int)sx
    printf("uy = %u:\t", uy);
    show_bytes((byte_pointer)&uy, sizeof(unsigned ));

    return 0;
}
