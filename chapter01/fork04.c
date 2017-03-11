#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
  if (fork() == 0) {
    printf("子プロセス\n"); }
  else {
    printf("親プロセス\n"); }
}
