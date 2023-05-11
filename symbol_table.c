#include<stdio.h>

int sosanh(int a) {
  int c = 10;
  while (a) {
    int b = a % 10;
    a /= 10;
    if (b > c) return 0;
    c = b;
  }
  return 1;
}

struct hai {
  int m;
  int n;
}d[100001];

void sapxep(struct hai a[], int l) {
  int i, j;
  for (i = 0; i < l - 1; i++)
    for (j = i + 1; j < l; j++)
      if (a[i].n < a[j].n) {
        struct hai c = a[i];
        a[i] = a[j];
        a[j] = c;
      }
}

main() {
  int i, j = 0, l = 0;
  char kitu = ' ';
  while (kitu != '\n') {
    int x;
    scanf("%d", & x);
    int k = sosanh(x);
    for (i = 0; i < j; i++) {
      if (x == d[i].m) {
        l = 1;
        d[i].n++;
      }
    }
    if (l == 1) {
      l = 0;
      goto tiep;
    }
    if (k == 1) {
      d[j].m = x;
      d[j].n = 1;
      j++;
    }
    tiep:
      kitu = getchar();
  }
  sapxep(d, j);
  for (i = 0; i < j; i++) printf("%d %d\n", d[i].m, d[i].n);
}