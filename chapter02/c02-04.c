#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int argc;
  char cmd[80];
  char *cmdp;
  char *argv[10];

  printf("コマンドを入力してください？ ");
  if (fgets(cmd, 80, stdin) == NULL)
    exit(0);
  if (strlen(cmd) == 1) {
    printf("終了\n");
    exit(0);
  }
  cmd[strlen(cmd) - 1] = '\0';
  cmdp = cmd;
  for (argc = 0; ; argc++) {
    if ((argv[argc] = strtok(cmdp, " ")) == NULL)
      break;
    cmdp = NULL;
  }

  printf("%s に変身します\n", cmd);
  execvp(argv[0], argv);
}
