#include <unistd.h>

int main() {
  int fd;

  fd = dup(1);
  write(fd, "test message\n", 13);
}
