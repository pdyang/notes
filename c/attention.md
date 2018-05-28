# 注意事项

## 变量

* 局部变量

  声明与初始化要同步进行, 未初始化的局部变量值是随机的.
  ```c
  /*
   * 此程序中局部变量未初始化, 第一次调用 add_range 结果与预期一样.
   * 但是第二次, 由于sum未初始化, 此次sum初值为上次函数执行结果.
   */
  #include <stdio.h>

  int add_range(int low, int high)
  {
      int i, sum;
      for (i = low; i <= high; i++)
      sum = sum + i;
      return sum;
  }

  int main(void)
  {
      int result[100];
      result[0] = add_range(1, 10);
      result[1] = add_range(1, 100);
      printf("result[0]=%d\nresult[1]=%d\n", result[0], result[1]);
      return 0;
  }
  /*
   * 结果:
   * result[0]=55
   * result[1]=5105
   */
  ```

* 全局变量

  必须用常量初始化, 局部变量未有此限制.

## 结构体

* 声明时, 不允许初始化结构体内元素.

## 指针

* 指针声明后, 若要用于存储需要手动分配内存.

## 函数

* void* malloc(size_t size)

  malloc是以字节为单位来分配空间的, 分配size bytes.
