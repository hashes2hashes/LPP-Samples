// このプログラムはNG例
// alias保存用変数(alias_xxx) を配列でなくポインタ変数とすると、そもそもcmd配列に保存してしまうため、次回入力で上書きされる

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

  char *alias_name = "";
  char *alias_cmd;

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
    argv[0] = strtok(cmdp, " ");

    if (strcmp(argv[0], "exit\0") == 0) {
      printf("exit\n");
      exit(0);
    }
    else if (strcmp(argv[0], "alias\0") == 0) {
      printf("set alias\n");
      cmdp = NULL;
      if ((alias_name = strtok(cmdp, "=")) == NULL) {
        printf("set alias error 1\n");
        exit(1);
      }
      if ((alias_cmd = strtok(cmdp, "'")) == NULL) {
        printf("set alias error 2\n");
        exit(1);
      }
      continue;
    }
    else if (strcmp(argv[0], alias_name) == 0) {
      printf("alias command\n");
      cmdp = alias_cmd;
      argv[0] = strtok(cmdp, " ");
    }
    
    for (argc = 1; ; argc++) {
      cmdp = NULL;
      if ((argv[argc] = strtok(cmdp, " ")) == NULL)
        break;
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
