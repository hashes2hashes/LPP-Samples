#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
  int fd;
  char ch;

  fd = open("oldfile", O_RDONLY);
  if (fd == -1)
    exit(1);
  while(read(fd, &ch, 1) != 0)
    write(1, &ch, 1);
  close(fd);
}

