#include <stdio.h>

int main() {
  FILE *fp;
  char buf[80];

  fp = fopen("oldfile", "r");
  fgets(buf, 21, fp);
  fprintf(stdout, "%s\n", buf);
  fclose(fp);
}
