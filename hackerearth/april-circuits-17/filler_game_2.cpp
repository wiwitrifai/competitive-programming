#include <bits/stdc++.h>

using namespace std;

const int N = 20;
int dp[1 << N], n, m;
int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
int solve(int mask) {
  int & ret = dp[mask];
  if (ret != -1) return ret;
  set< int > st;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int now = i * m + j;
      if (mask & (1<<now)) continue;
      bool ok = 0;
      for (int k = 0; k < 4; k++) {
        int x = i + dx[k], y = j + dy[k];
        if (x < 0 || x >= n || y < 0 || y >= m) continue;
        int neg = x * m + y;
        if (mask & (1 << neg)) continue;
        ok = 1;
        break;
      }
      if (ok)
        st.insert(solve(mask | (1 << now)));
    }
  }
  ret = 0;
  for (int v : st)
    ret += v == ret;
  return ret;
}

char s[22];

int main() {
  memset(dp, -1, sizeof dp);
  int q;
  scanf("%d %d %d", &n, &m, &q);
  while (q--) {
    int mask = 0;
    for (int i = 0; i < n; i++) {
      scanf("%s", s);
      for (int j = 0; j < m; j++) if (s[j] == '1') {
        int id = i * m + j;
        mask |= 1<<id;
      }
    }
    printf("%d\n", !solve(mask));
  }
  return 0;
}