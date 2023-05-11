#include <stdio.h>
#include <string.h>

struct symTable {
  int type;
  char var[10];
}sT[50];

int c = 0;

void sep(char a[]) {
  int len = strlen(a);
  int i, j = 0;
  char temp[50], tp[50];
  for (i = 0; i < len; ++i) {
    if (a[i] != 32)
      tp[i] = a[i];
    else
      break;
  }
  tp[i] = '\0';
  temp[0] = '\0';
  ++i;
  for (; i < len; ++i) {
    if (a[i] != ',' && a[i] != 32 && a[i] != ';')
      temp[j++] = a[i];
    else {
      temp[j] = '\0';
      if (strcmp(tp, "int") == 0)
        sT[c].type = 1;
      else if (strcmp(tp, "float") == 0)
        sT[c].type = 2;
      strcpy(sT[c++].var, temp);
      temp[0] = '\0';
      j = 0;
    }
  }

}

int check(char a[]) {
  int len = strlen(a);
  int i, j = 0, key = 0, k;
  char temp[50];
  for (i = 0; i < len; ++i) {
    if (a[i] != 32 && a[i] != '+' && a[i] != '=' && a[i] != ';')
      temp[j++] = a[i];
    else {
      temp[j] = '\0';
      for (k = 0; k < c; ++k) {
        if (strcmp(sT[k].var, temp) == 0) {
          if (key == 0)
            key = sT[k].type;
          else if (sT[k].type != key)
            return 0;
        }
      }
      j = 0;
    }
  }
  return 1;
}

void main() {
  int N, ans, i;
  char s[50];
  printf("Enter the total lines of declaration: ");
  scanf("%d", &N);
  while (N--) {
    scanf(" %[^\n]", s);
    sep(s);
  }
  printf("\nEnter the expression: ");
  scanf(" %[^\n]", s);

  if (check(s))
    printf("Correct\n");
  else
    printf("Semantic error\n");
}

