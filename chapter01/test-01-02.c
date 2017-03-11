#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
  fork();
  fork();
  printf("プロセスid = %d\n", getpid());
}
