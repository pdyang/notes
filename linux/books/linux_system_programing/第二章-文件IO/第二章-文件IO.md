# 第二章-文件IO

内核为每个进程维护一个打开的文件列表(file table), 该表由文件描述符索引. 子进程会获得一份父进程的文件表拷贝.

## 打开文件

### 文件权限

open()创建文件的权限计算规则:

1. umask掩码取反
2. 函数中mode参数与取反后的掩码相与

默认权限:

* 目录: umask掩码与777进行位异或
* 文件: umask掩码与777进行位异或, 再去掉执行权限. (创建普通文件时不分配执行权限, 用chmod后期修改)

## 读取文件

### read()的不同返回值

* 返回-1

  函数出错返回-1，并设置errno

  如：可恢复的读取: 函数执行出错返回-1, 并设置errno为EINTR

* 返回值大于0小于期望值
  1. 可供读取的字节数小于count
  2. 系统调用被信号打断
  3. 管道被破坏
  4. 等等

### read()读取字节数量限制

SSIZE_MAX

### 阻塞与非阻塞I/O

阻塞：即等待，也就是说如果没有收到数据，那么线程或者进程就会被挂起，直到收到数据.

非阻塞：不会等待，没有数据时，如read()`(需要设置非阻塞模式)`会立即返回-1，并设置errno.但是用户要不断轮询读取或写入.

## 写文件
