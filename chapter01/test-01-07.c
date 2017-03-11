#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  pid_t s_pid1, s_pid2;
  pid_t e_pid1, e_pid2;
  int status1, status2;

  if ((s_pid1 = fork()) == 0) {
    printf("子プロセス:start\n");
    sleep(2);
    if ((s_pid2 = fork()) == 0) {
        printf("孫プロセス:start\n");
        sleep(3);
        exit(2);
    }
    else {
      printf("孫プロセス:%d\n", s_pid2);
      e_pid2 = wait(&status2);
      printf("孫プロセス%d終了:%04x\n", e_pid2, status2);
      exit(1);
    }
  }
  else {
      printf("子プロセス:%d\n", s_pid1);
      e_pid1 = wait(&status1);
      printf("子プロセス%d終了:%04x\n", e_pid1, status1);
  }
}
