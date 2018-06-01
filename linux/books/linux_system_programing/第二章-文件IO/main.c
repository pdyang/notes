/*
 * 本源文件包含有关文件I/O的系统调用的简单用法:
 *  open()
 *  read(), write()
 *  close()
 *
 */

// perror()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// errno
#include <errno.h>

// open()...
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// close(), read(), write()
#include <unistd.h>

int main(int argc, char const *argv[]) {
    int fd; // 文件描述符

    fd = open("./test.txt", O_RDWR | O_APPEND | O_CREAT,
                0644);
    if (-1 == fd) {
        perror("open");
    }

    const char* str = "yang pengda.";
    ssize_t wret;
    wret = write(fd, str, strlen(str));
    if (-1 == wret) {
        perror("write");
    }

    size_t len = 100;
    char* buf = (char*) malloc(len);
    ssize_t rret = 0;
    while (len != 0 && (rret = read(fd, buf, len)) != 0) {
        if (-1 == rret) {
            if (errno == EINTR) {
                continue;
            }
            perror("read");
            break;
        }
        len -= rret;
        if (rret > 0 && rret < len) {
            buf += rret;
        }

    }
    //free(buf);

    close(fd);

    return 0;
}
