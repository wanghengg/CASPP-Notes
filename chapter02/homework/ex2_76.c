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