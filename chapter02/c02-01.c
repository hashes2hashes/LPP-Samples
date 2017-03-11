#include <stdio.h>
#include <unistd.h>

int main() {
  printf("cal 1 2000 に変身\n");
  execl("/usr/bin/cal", "cal", "1", "2020", (char *)0);
}
