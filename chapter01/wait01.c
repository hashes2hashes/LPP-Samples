#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main() {
  int status;

  if (fork() == 0) {
    printf("子プロセス\n");
    sleep(5); }
  else {
    wait(&status);
    printf("親プロセス\n"); }
}

    
    
