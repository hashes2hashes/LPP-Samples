#include <stdio.h>
#include <unistd.h>

int main() {
  printf("before fork : ");
  fflush(stdout);
  if (fork() == 0)
    printf("child process\n");
  else
    printf("parent process\n");
}
