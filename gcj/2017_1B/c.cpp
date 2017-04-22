#include <bits/stdc++.h>

using namespace std;

const int N = 205;
long long d[N][N], e[N], s[N];
double h[N][N];
bool ok[N][N];

int main() {
    time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
      scanf("%lld %lld", e+i, s+i);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%lld", d[i]+j);
      }
    }
    for (int i = 0; i < n; i++)
      d[i][i] = 0;
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (d[i][k] < 0 || d[k][j] < 0) continue;
          long long val = d[i][k] + d[k][j];
          if (d[i][j] == -1 || d[i][j] > val)
            d[i][j] = val;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (d[i][j] < 0 || d[i][j] > e[i]) {
          ok[i][j] = 0;
          h[i][j] = 0;
        }
        else {
          ok[i][j] = 1;
          h[i][j] = (double)d[i][j]/s[i];
        }
      }
    }
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (!ok[i][k] || !ok[k][j]) continue;
          double val = h[i][k] + h[k][j];
          if (!ok[i][j] || h[i][j] > val) {
            ok[i][j] = 1;
            h[i][j] = val;
          }
        }
      }
    }
    printf("Case #%d:", tc);
    for (int i = 0; i < q; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      u--; v--;
      printf(" %.9lf", h[u][v]);
    }
    printf("\n");
    cerr << "Case #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}