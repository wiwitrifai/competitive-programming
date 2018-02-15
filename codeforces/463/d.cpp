#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5, LG = 21;
const long long inf = 1e17;
int par[LG][N];
long long sum[LG][N];
long long w[N];

int main() {
  int n = 1, q;
  long long last = 0;
  scanf("%d", &q);
  while (q--) {
    int t;
    long long x, y;
    scanf("%d %I64d %I64d", &t, &x, &y);
    x ^= last;
    y ^= last;
    if (t == 1) {
      for (int i = LG-1; i >= 0; --i) if (par[i][x] && w[par[i][x]] < y) {
        x = par[i][x];
      }
      if (w[x] < y)
        x = par[0][x];
      ++n;
      w[n] = y;
      par[0][n] = x;
      sum[0][n] = w[x];
      for (int i = 0; i + 1 < LG; ++i) if (par[i][n]) {
        par[i+1][n] = par[i][par[i][n]];
        sum[i+1][n] = sum[i][n] + sum[i][par[i][n]];
        if (sum[i+1][n] > inf) sum[i+1][n] = inf;
      }
    }
    else {
      if (y < w[x]) {
        last = 0;
      }
      else {
        last = 1;
        y -= w[x];
        for (int i = LG-1; i >= 0; --i) if (par[i][x] && sum[i][x] <= y) {
          last += 1LL << i;
          y -= sum[i][x];
          x = par[i][x];
        }
      }
      printf("%I64d\n", last);
    }
  }

  return 0;
}