#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
  pid_t val;

  val = fork();
  if (val == 0) {
    printf("子プロセス\n"); }
  else {
    printf("親プロセス\n"); }
}
