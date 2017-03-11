#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
  int fd1, fd2;
  int status;
  int count;
  char buf[20];

  if ((fd1 = open("oldfile", O_RDONLY)) == -1)
    exit(1);
  if (fork() == 0) {
    if ((fd2 = creat("newfile1", 0664)) == -1)
      exit(1);
    printf("child: fd1: %d, fd2: %d\n", fd1, fd2);
    while ((count = read(fd1, buf, 20)) != 0) {
      write(fd2, buf, count);
      write(fd2, "\n", 1);
      write(1, "child\n", 6);
      sleep(1);
    }
  }
  else {
    if ((fd2 = creat("newfile2", 0664)) == -1)
        exit(1);
    printf("parent: fd1: %d, fd2: %d\n", fd1, fd2);
    while ((count = read(fd1, buf, 20)) != 0) {
      write(fd2, buf, count);
      write(fd2, "\n", 1);
      write(1, "parent\n", 7);
      sleep(1);
    }
    wait(&status);
  }
}
