#include <stdio.h>
#include <unistd.h>

int main() {
  char *argv[4];

  argv[0] = "cal";
  argv[1] = "1";
  argv[2] = "2020";
  argv[3] = (char *)0;

  printf("cal 1 2020 に変身\n");
  execvp("cal", argv);
}
