/*
 * 本源文件包含有关文件I/O的系统调用的简单用法:
 *  open()
 *  read(), write()
 *  close()
 *
 */

#include <stdio.h>
#include <stdlib.h>

// 变量errno
#include <errno.h>

// open()...
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// close(), read()
#include <unistd.h>

int main(int argc, char const *argv[]) {
    int fd; // 文件描述符

    /*
     * int open(const char* pathname, int flags, mode_t mode);
     *
     * flags:
     *  O_RDONLY, O_WRONLY, O_RDWR 这三者必须包含其一
     *  O_APPEND, O_CREAT... 或者位或一个、多个这些选项
     *
     * mode(权限):
     *  S_IRGRP, S_IWGRP, S_IXOTH...
     *  可以是数字形式, 如: 0644
     */
    fd = open("/home/yangpengda/.bashrc", O_RDONLY);
    if (-1 == fd) {
        perror("open");
    }

    size_t len = 100;
    char* buf = (char*) malloc(len);
    ssize_t ret = 0;
    while (len != 0 && (ret = read(fd, buf, len)) != 0) {
        if (-1 == ret) {
            if (errno == EINTR) {
                continue;
            }
            perror("read");
            break;
        }
        len -= ret;
        if (ret > 0 && ret < len) {
            buf += ret;
        }

    }
    free(buf);

    close(fd);

    return 0;
}
