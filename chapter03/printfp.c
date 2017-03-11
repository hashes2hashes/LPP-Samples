#include <stdio.h>

int main() {
  FILE *fp;
  int k;

  k = 15;
  fp = fopen("newfile", "w");
  fprintf(fp, "%d\n", k);
  fclose(fp);
}
