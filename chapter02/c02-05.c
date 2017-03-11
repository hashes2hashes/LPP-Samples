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

  argc = 0;
  if ((argv[argc++] = strtok(cmdp, " ")) == NULL)
    exit(1);
  cmdp = NULL;
  if ((argv[argc++] = strtok(cmdp, "=")) == NULL)
    exit(1);
  if ((argv[argc++] = strtok(cmdp, "'")) == NULL)
    exit(1);
  argv[argc] = '\0';

  for (argc = 0; ; argc++) {
    if (argv[argc] == '\0')
      break;
    printf("argv[%d]: %s\n", argc, argv[argc]);
  }

  /*
  argc = 0;
  while (argv[argc] != '\0') {
    printf("argv[%d]: %s\n", argc, argv[argc]);
    argc++;
  }
  */
}
