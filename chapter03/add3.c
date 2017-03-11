#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *myitoa(int value, char *buff, int radix) {
  static const char table[] = "0123456789abcdefghijklmnopqrstuvwxyz";
  char *head = buff;
  char *tail = buff;
  char temp;

  // convert minus to string
  if (value < 0) {
    *tail++ = '-';
    value = -value;
  }
  // convert zero to string
  if (value == 0) {
    *tail++ = '0';
  } else {
    for (head = tail; value != 0; value /= radix) {
      *tail++ = table[value % radix];
    }
  }
  *tail = '\0';
  // swap string
  for (tail--; head < tail; head++, tail--) {
    temp = *head;
    *head = *tail;
    *tail = temp;
  }

  return buff;
}

int myatoi(char *p) {
  int val, minus;
  
  val = 0;
  if (*p == '-') {
    minus = 1;
    p++;
  }
  else
    minus = 0;
  while (*p != '\0') {
    val = val * 10;
    val = val + (*p - '0');
    p++;
  }

  if (minus)
    val = 0 - val;
  return val;
}


int main(int argc, char *argv[]) {
  int i = 0;
  int param1, param2, result;
  char str_result[7];
  
  param1 = myatoi(argv[1]);
  param2 = myatoi(argv[2]);
  printf("param1: %d\n", param1);
  printf("param2: %d\n", param2);
  
  result = param1 + param2;
  myitoa(result, str_result, 16);
  
  printf("result: %d\n", result);
  //printf("str_result: %s\n", str_result);
  printf("str_result: ");
  fflush(stdout);
  while ((str_result[i] != '\0') && (i < 7)) {
    write(1, &str_result[i], 1);
    i++;
  }
  printf("\n");
}
