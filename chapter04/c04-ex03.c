#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main() {
  int argc;
  char cmd[80];
  char *cmdp;
  char *argv[10];
  int status;
  int fd, stdout_copy, redirect;
  
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

    if (strcmp(argv[0], "exit") == 0) {
        printf("exit\n");
        exit(0);
    }
    
    redirect = 0;
    for (int i = 0; i < argc; i++) {
      if (strcmp(argv[i], ">") == 0) {
        argv[i] = (char *)0;
        printf("creat filename: %s\n", argv[i+1]);
        redirect = 1;
        unlink(argv[i+1]);
        fd = creat(argv[i+1], 0664);
        stdout_copy = dup(1);
        dup2(fd, 1);
        close(fd);
      }
      else if (strcmp(argv[i], ">>") == 0) {
        argv[i] = (char *)0;
        printf("open filename: %s\n", argv[i+1]);
        redirect = 1;
        fd = open(argv[i+1], O_WRONLY | O_CREAT, 0664);
        lseek(fd, 0, SEEK_END);
        stdout_copy = dup(1);
        dup2(fd, 1);
        close(fd);
      }
    }

    if (fork() == 0) {
      execvp(argv[0], argv);
      printf("コマンドが見つかりませんでした\n");
      exit(1);
    }
    else {
      wait(&status);
      if (redirect ==1) {
        dup2(stdout_copy, 1);
        close(stdout_copy);
      }
    }
  }
}
