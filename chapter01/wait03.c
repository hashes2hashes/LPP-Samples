#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int status;
  pid_t pid;
  
  if (fork() == 0) {
    printf("子プロセス\n");
    sleep(5);
    exit(3); }
  else {
    pid = wait(&status);
    printf("親プロセス\n");
    printf("子プロセスのid = %d\n", pid);
    printf("子プロセス終了時の値は = %04x\n", status);
    exit(1); }
}
