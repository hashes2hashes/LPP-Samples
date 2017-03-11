#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
  int fd;

  fd = open("newfile", O_WRONLY | O_CREAT, 0664);
  close(1);
  dup(fd);

  execlp("cat", "cat", (char *)0);
}

    
