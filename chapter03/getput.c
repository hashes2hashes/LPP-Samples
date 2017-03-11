#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  FILE *rfp, *wfp;
  char c;

  if ((rfp = fopen("oldfile", "r")) == NULL)
    exit(1);

  c = getc(rfp);
  ungetc(c, rfp);
  
  if (fork() == 0) {
    if ((wfp = fopen("newfile3", "w")) == NULL)
      exit(1);
    while((c = getc(rfp)) != EOF)
      putc(c, wfp);
    fclose(rfp);
    fclose(wfp);
  }
  else {
    if ((wfp = fopen("newfile4", "w")) == NULL)
      exit(1);
    while((c = getc(rfp)) != EOF)
      putc(c, wfp);
    fclose(rfp);
    fclose(wfp);
  }
}
