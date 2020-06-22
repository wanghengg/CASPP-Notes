 ## 2.55

```c++
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
```

## 2.58

```c++
#include <stdio.h>
#include <stdint.h>

int is_little_endian(void) {
    int32_t i = 1;
    unsigned char *p = (unsigned char *) &i;
    if (*p)
        return 1;
    return 0;
}

int main() {
    if (is_little_endian())
        printf("is_little_endian");
    else
        printf("is_big_endian");
    return 0;
}
```

## 2.59

```c++
#include <stdio.h>

int merge(int x, int y) {
    return (x & 0x000000FF) | (y & 0xFFFFFF00);
}

int main() {
    int a = merge(0x89ABCDEF, 0x76543210);
    printf("%x\n", a);
    return 0;
}
```

## 2.60

```c++
#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b) {
    unsigned char *p = (unsigned char *) &x;
    p[i] = b;
    return *(unsigned *)p;
}

int main() {
    printf("%x\n", replace_byte(0x12345678, 2, 0xAB));
    printf("%x\n", replace_byte(0x12345678, 0, 0xAB));

    return 0;
}
```

## 2.61

```c++
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
```

## 2.62

```c++
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
```

## 2.63

```c++
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
```

## 2.64

```c++
#include <stdio.h>

int any_odd_one(unsigned x) {
    return (x & 0xaaaaaaaa) != 0;
}

int main() {
    printf("%d\n", any_odd_one(0x8));
    return 0;
}
```

## 2.65

```c++
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
```



## 2.68

```c++
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
```



## 2.76

```c++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *calloc(size_t nmemb, size_t size) {
    void *p;
    // nmemb * size为0或者malloc分配内存失败时，返回空指针，当malloc(size_t size)为0时，
    // 行为未定义，所以必须要判断nmemb * size是否为0
    if (!(nmemb * size) || !(p = malloc(nmemb * size)))
        return NULL;
    // 判断nmemb * size是否溢出，如果溢出要释放内存，避免内存泄漏
    else if((nmemb * size) / size != nmemb)
    {
        printf("size * nmemb overflow size_t.\n");
        free(p);
        return NULL;
    } else {
        memset(p, 0, nmemb * size);
        return p;
    }
}

int main() {
    size_t number = 200;
    int *p = (int *)calloc(number, sizeof(int ));
    if (p) {
        for (int i = 0; i < number; ++i)
            printf("%d\t", p[i]);
    }
    free(p);
    return 0;
}
```

