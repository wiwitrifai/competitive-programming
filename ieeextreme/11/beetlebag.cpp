#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int d[2][N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, c;
    scanf("%d %d", &c, &n);
    int a = 0, b = 1;
    memset(d, 0, sizeof d);
    for (int i = 0; i< n; i++) {
      swap(a, b);
      int w, f;
      scanf("%d %d", &w, &f);
      for (int j = 0; j <= c; j++)
        d[a][j] = d[b][j];
      for (int j = w; j <= c; j++) {
        d[a][j] = max(d[a][j], d[b][j-w] + f);
      }
    }
    int ans = 0;
    for (int i= 0; i <= c; i++)
      ans = max(d[a][i], ans);
    printf("%d\n", ans);
  }
  return 0;
}