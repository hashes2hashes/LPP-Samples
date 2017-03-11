#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  int argc;
  char cmd[80];
  char save[80];
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

    strcpy(save, cmd);
    
    cmd[strlen(cmd) - 1] = '\0';
    cmdp = cmd;
    for (argc = 0; ; argc++) {
      if ((argv[argc] = strtok(cmdp, " ")) == NULL)
        break;
      cmdp = NULL;
    }

    if (strcmp(argv[0], "alias\0") == 0) {
      printf("set alias\n");
      cmdp = save;
      (void *)strtok(cmdp, " ");
      cmdp = NULL;

      if ((alias_name = strtok(cmdp, "=")) == NULL) {
        printf("error 1\n");
        exit(1);
      }
      if ((alias_cmd = strtok(cmdp, "'")) == NULL) {
        printf("error 2\n");
        exit(1);
      }
      continue;
    }
    else if (strcmp(argv[0], alias_name) == 0) {
      printf("alias command\n");
      cmdp = alias_cmd;
      for (argc = 0; ; argc++) {
        if ((argv[argc] = strtok(cmdp, " ")) == NULL)
          break;
        cmdp = NULL;
      }
    }
    else if (strcmp(argv[0], "exit\0") == 0) {
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
