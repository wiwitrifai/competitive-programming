#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 4, inf = 1e8 + 5;

int ma[2][N], mi[2][N];

int main() {
  int n, k;
  scanf("%d %d", &k, &n);
  int c = 0, b = 1;
  for (int i = 0; i <= k; ++i)
    ma[c][i] = -1;
  for (int i = 0; i <= k; ++i)
    mi[c][i] = inf;
  ma[c][0] = mi[c][0] = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    swap(c, b);
    for (int j = 0; j <= k; ++j) {
      ma[c][j] = ma[b][j];
      mi[c][j] = mi[b][j];
      if (j >= x) {
        if (ma[c][j-x] >= 0)
          ma[c][j] = max(ma[c][j], ma[c][j-x]+1);
        if (mi[c][j-x] < inf)
          mi[c][j] = min(mi[c][j], mi[c][j-x]+1);
      }
    }
  }
  if (ma[c][k] == -1) {
    puts("-1 -1");
    return 0;
  }
  printf("%d %d\n", mi[c][k], ma[c][k]);
  return 0;
}