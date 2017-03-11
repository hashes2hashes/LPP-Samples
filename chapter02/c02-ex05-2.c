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

  char alias_name[10][80] = {};
  char alias_cmd[10][80];
  int alias_num = 0;
  
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
      printf("set alias num:%d\n", alias_num);
      cmdp = NULL;
      if ((argv[1] = strtok(cmdp, "=")) == NULL) {
        printf("set alias error 1\n");
        exit(1);
      }
      strcpy(alias_name[alias_num], argv[1]);

      if ((argv[2] = strtok(cmdp, "'")) == NULL) {
        printf("set alias error 2\n");
        exit(1);
      }
      strcpy(alias_cmd[alias_num], argv[2]);
      alias_num = (alias_num + 1) % 10;
      
      continue;
    }

    else {
      for (int i = 0; i < 10; i++) {
        if (strcmp(argv[0], alias_name[i]) == 0) {
          printf("alias command num:%d\n", i);
          strcpy(cmdp, alias_cmd[i]);
          argv[0] = strtok(cmdp, " ");
          break;
        }
      }
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
