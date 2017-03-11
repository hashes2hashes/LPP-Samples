#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  pid_t s_pid1, s_pid2;
  pid_t e_pid1, e_pid2, e_pid3;
  int status1, status2, status3;

  if ((s_pid1 = fork()) == 0) {
    printf("子プロセス1:start\n");
    sleep(3);
    exit(1);
  }
  else if ((s_pid2 = fork()) == 0) {
    printf("子プロセス2:start\n");
    sleep(2);
    exit(2);
  }
  else {
    printf("子プロセス1: %d\n", s_pid1);
    printf("子プロセス2: %d\n", s_pid2);

    e_pid1 = wait(&status1);
    printf("子プロセス%d 終了: %04x\n", e_pid1, status1);
    e_pid2 = wait(&status2);
    printf("子プロセス%d 終了: %04x\n", e_pid2, status2);
    e_pid3 = wait(&status3);
    printf("子プロセス%d 終了: %04x\n", e_pid3, status3);
  }
}
