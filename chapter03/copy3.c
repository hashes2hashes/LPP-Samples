#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
  int fd1, fd2;
  char ch;

  if ((fd1 = open("oldfile", O_RDONLY)) == -1)
    exit(1);
  //if ((fd2 = creat("newfile", 0664)) == -1) {
  if ((fd2 = open("newfile", O_WRONLY | O_CREAT, 0664)) == -1) {
    printf("open error\n");
    exit(1);
  }
  printf("fd1: %d, fd2: %d\n", fd1, fd2);
  while(read(fd1, &ch, 1) != 0)
    write(fd2, &ch, 1);
  close(fd1);
  close(fd2);
}
