#include <bits/stdc++.h>

using namespace std;

const int N = 11;

int to[N][2];

int main() {
  for (int i = 0; i < 10; i++)
    to[i][0]= 0, to[i][1] = 1;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    char c;
    int x;
    scanf(" %c %d", &c, &x);
    for (int j = 0; j < 10; j++) {
      int z = x & 1;
      x >>= 1;
      for (int k = 0; k < 2; k++) {
        if (c == '&')
          to[j][k] &= z;
        else if (c == '|')
          to[j][k] |= z;
        else
          to[j][k] ^= z;
      }
    }
  }
  int o = 0, d = 1023, x = 0;
  for (int i = 0; i < 10; i++) {
    if (to[i][0] == 0 && to[i][1] == 0)
      d ^= 1 << i;
    else if (to[i][0] == 1 && to[i][1] == 1)
      o ^= 1 << i;
    else if (to[i][0] == 1 && to[i][1] == 0)
      x ^= 1 << i;
  }
  printf("%d\n", 3);
  printf("& %d\n", d);
  printf("| %d\n", o);
  printf("^ %d\n", x);
  return 0;
}