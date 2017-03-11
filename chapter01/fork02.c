#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
  pid_t val;

  val = fork();
  printf("forkの戻り値 = %d\n", val);
  printf("プロセスid = %d\n", getpid());
}
