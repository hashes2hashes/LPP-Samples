#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
  int fd, stdout_copy;

  fd = open("newfile2", O_WRONLY | O_CREAT, 0664);

  stdout_copy = dup(1);
  dup2(fd, 1);
  close(fd);
  write(1, "stdout changeover\n", 18);
  
  dup2(stdout_copy, 1);
  close(stdout_copy);
  write(1, "restoration\n", 12);
}
