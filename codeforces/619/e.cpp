#include <bits/stdc++.h>

using namespace std;

const int N = 505, Q = 3e5 + 5;

char s[N][N];

int ans[Q], ra[Q], rb[Q], ca[Q], cb[Q];
vector<tuple<int, int, int>> logos;
int pre[N][N];

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < n; ++i)
    scanf("%s", s[i]);
  for (int i = 0; i+1 < n; ++i) {
    for (int j = 0; j+1 < m; ++j) {
      if (s[i][j] == 'R' && s[i][j+1] == 'G' && s[i+1][j] == 'Y' && s[i+1][j+1] == 'B') {
        int len = 1;
        while (i >= len && j >= len && len+1 <= n-i && len+1 <= m-j) {
          bool ok = 1;
          for (int k = 0; k <= len && ok; ++k) {
            ok &= s[i-len][j-k] == 'R';
            ok &= s[i-k][j-len] == 'R';

            ok &= s[i-len][j+1+k] == 'G';
            ok &= s[i-k][j+1+len] == 'G';

            ok &= s[i+1+len][j-k] == 'Y';
            ok &= s[i+1+k][j-len] == 'Y';

            ok &= s[i+1+len][j+1+k] == 'B';
            ok &= s[i+1+k][j+1+len] == 'B';
          }
          if (!ok)
            break;
          ++len;
        }
        logos.emplace_back(len, i+2, j+2);
      }
    }
  }
  sort(logos.begin(), logos.end());
  reverse(logos.begin(), logos.end());
  for (int i = 0; i < q; ++i) {
    scanf("%d %d %d %d", ra+i, ca+i, rb+i, cb+i);
  }
  vector<int> que(q);
  iota(que.begin(), que.end(), 0);
  for (int len = 1; len * 2 <= min(n, m); ++len) {
    if (que.empty()) break;
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= m; ++j)
        pre[i][j] = 0;
    for (auto it : logos) {
      int x, r, c;
      tie(x, r, c) = it;
      if (x < len) break;
      ++pre[r][c];
    }
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= m; ++j) {
        int now = pre[i][j];
        pre[i+1][j] += now;
        pre[i][j+1] += now;
        pre[i+1][j+1] -= now;
      }
    vector<int> tmp;
    for (int u : que) {
      int a = ra[u], b = rb[u], x = ca[u], y = cb[u];
      if (b <= a || y <= x) continue;
      int res = pre[b][y] - pre[a][y] - pre[b][x] + pre[a][x];
      if (res <= 0) continue;
      ans[u] = len;
      tmp.push_back(u);
      ++ra[u];
      --rb[u];
      ++ca[u];
      --cb[u];
    }
    que.swap(tmp);
  }
  for (int i = 0; i < q; ++i) {
    ans[i] = ans[i] * ans[i] * 4;
    printf("%d\n", ans[i]);
  }
  return 0;
}
