#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
  if (fork() == 0) {
    printf("こんにちは\n"); }
}
