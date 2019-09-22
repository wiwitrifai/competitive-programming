#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, N = 1e5 + 5;

int cnt[1 << 8][1 << 8];

char s[30];

void add(int & var, int val) {
  var += val;
  if (var >= mod)
    var -= mod;
}

void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  memset(cnt, 0, sizeof cnt);
  int mid = (m + 1) / 2, nmask = 1 << mid;
  for (int i = 0; i < nmask; ++i)
    cnt[0][i] = 1;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    int cur = 0;
    for (int j = 0; j < m; ++j)
      if (s[j] == '1')
        cur |= 1 << j;
    int a = cur >> mid, b = cur & (nmask-1);
    int sum = 0;
    for (int j = 0; j < nmask; ++j) {
      if (a & j) continue;
      add(sum, cnt[j][b]);
    }
    for (int j = 0; j < nmask; ++j) {
      if (b & j) continue;
      add(cnt[a][j], sum);
    }
    add(ans, sum);
  }
  printf("%d\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
