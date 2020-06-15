#include <stdio.h>
#include <stdint.h>

typedef unsigned char *byte_pointer;

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