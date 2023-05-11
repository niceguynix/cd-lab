#include<stdio.h>

void main() {
  char all_var[20];
  int dup[20]={0};
  int ptr = 0, i, j, c, a = 0;
  FILE * file;
  file = fopen("test.txt", "r");
  if (file) {
    while ((c = getc(file)) != EOF) {
      putchar(c);
      if (c == ';' || c == ' ' || (c >= '0' && c <= '9') || c == '=' || c == '\n' || c == '+')
        continue;
      else {
        all_var[ptr] = c;
        ptr++;
      }
    }
    printf("\n\nThe unused variables are: \n");
    for (i = 0; i < ptr; i++) {
      for (j = i + 1; j < ptr; j++){
      if (all_var[i] == all_var[j]) {
        dup[i] = 1;
        dup[j] = 1;
    }}}

    for(int i=0;i<ptr;i++){
      if (dup[i] == 0) {
        printf("%c\n", all_var[i]);
      }
    }
    fclose(file);
  }
}