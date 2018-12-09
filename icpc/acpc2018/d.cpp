#include <bits/stdc++.h>

using namespace std;

void open_file(string filename) {
#ifndef LOCAL
  freopen(filename.c_str(), "r", stdin);
#endif
}

void close_file() {
#ifndef LOCAL
  fclose(stdin);
#endif
}

const int N = 2048;

int pre[N][N];
int x[N], y[N];

int main() {
  open_file("dull.in");
  int t;
  scanf("%d", &t);
  while (t--) {
    vector<int> vx, vy;
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vx.push_back(1);
    vy.push_back(1);
    vx.push_back(n+1);
    vy.push_back(m+1);
    for (int i = 0; i < k; ++i) {
      scanf("%d %d", x+i, y+i);
      vx.push_back(x[i]);
      vy.push_back(y[i]);
    }
    sort(vx.begin(), vx.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    sort(vy.begin(), vy.end());
    vy.erase(unique(vy.begin(), vy.end()), vy.end());
    for (int i = 0; i <= vx.size(); ++i)
      for (int j = 0; j <= vy.size(); ++j)
        pre[i][j] = 0;
    for (int i = 0; i < k; ++i) {
      x[i] = lower_bound(vx.begin(), vx.end(), x[i]) - vx.begin();
      y[i] = lower_bound(vy.begin(), vy.end(), y[i]) - vy.begin();
      ++pre[x[i]+1][y[i]+1];
    }
    for (int i = 0; i <= vx.size(); ++i)
      for (int j = 0; j <= vy.size(); ++j) {
        pre[i+1][j+1] -= pre[i][j];
        pre[i+1][j] += pre[i][j];
        pre[i][j+1] += pre[i][j];
      }
    long long ans = 0;
    for (int i = 0; i + 1 < vx.size(); ++i) {
      for (int j = 0; j + 1 < vy.size(); ++j) {
        if (pre[i+1][j+1] & 1) {
          ans += (vx[i+1] - vx[i]) * 1LL * (vy[j+1] - vy[j]);
        }
      }
    }
    printf("%lld %lld\n", ans, 1LL * n * m - ans);
  }
  close_file();
  return 0;
}