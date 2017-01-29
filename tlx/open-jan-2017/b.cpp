#include <bits/stdc++.h>

using namespace std;

int r, c;
int x[50][50];

int main() {
  scanf("%d %d", &r, &c);
  int n = r * c;
  while (n--) {
    int a;
    scanf("%d", &a);
    int u, v;
    u = v = 0;
    if (a == 2) {
      for (int i = 1; i <= r && !u; i++)
        for (int j = 1; j <= c && !u; j++)
          if (x[i][j] == 0) {
            x[i][j] = a;
            u = i;
            v = j;
          }
    }
    else {
      for (int i = r; i > 0 && !u; i--)
        for (int j = c; j > 0 && !u; j--)
          if (x[i][j] == 0) {
            x[i][j] = a;
            u = i;
            v = j;
          }
    }
    printf("%d %d\n", u, v);
    fflush(stdout);
  }

  return 0;
}