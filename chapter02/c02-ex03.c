#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  int argc;
  char cmd[80];
  char *cmdp;
  char *argv[10];
  int status;

  for(;;) {
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

    if (strcmp(argv[0], "exit\0") == 0) {
        printf("exit\n");
        exit(0);
    }
    
    if (fork() == 0) {
      execvp(argv[0], argv);
      printf("コマンドが見つかりませんでした\n");
      exit(1);
    }
    else {
      wait(&status);
    }
  }
}
