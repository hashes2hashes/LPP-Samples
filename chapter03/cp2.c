#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  int fd1, fd2;
  int count;
  char buf[20];
  
  if ((fd1 = open(argv[1], O_RDONLY)) == -1) {
    printf("open error: %s\n", argv[1]);
    exit(1);
  }
  if ((fd2 = creat(argv[2], 0664)) == -1) {
    printf("creat error: %s\n", argv[2]);
    exit(1);
  }
  while ((count = read(fd1, buf, 1)) != 0)
    write(fd2, buf, count);
}
