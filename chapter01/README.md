* 　c/c++没有越界访问检查，直到程序运行时才会出错。

  ```c++
  #include <stdio.h>
  
  typedef struct {
      int a[2];
      double d;
  } struct_t;
  
  double fun(int i) {
      volatile struct_t s;
      s.d = 3.14;
      s.a[i] = 1073741824;
      return s.d;
  }
  
  int main() {
      printf("%ld\n", sizeof(struct_t));  // 查看struct_t占多少个字节
      // 当ｉ>= 2时，访问s.a[i]就已经越界，但是直到当ｉ>５时，程序才错误中断
      printf("s.d = %f", fun(5));
  
      return 0;
  }
  ```

  

