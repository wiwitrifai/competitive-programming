#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

long long dp[N][N];
long long sum[N];
int b[N], til[N];

void upd(long long & v, long long x) {
  if (v < x)
    v = x;
}

void solve() {
  int n, m, s;
  scanf("%d %d %d", &n, &m, &s);
  vector<tuple<int, int, int> > song(n);
  memset(sum, 0, sizeof sum);
  for (int i = 0; i < n; ++i) {
    int a, p, v;
    scanf("%d %d %d", &a, &p, &v);
    song[i] = make_tuple(a, p, v);
    sum[a] += v;
  }
  sort(song.begin(), song.end());
  memset(til, -1, sizeof til);
  for (int i = n-1; i >= 0;) {
    int now = get<0>(song[i]);
    int last = i+1;
    while (i >= 0 && get<0>(song[i]) == now) {
      --i;
    }
    til[i+1] = last;
  }
  for (int i = 1; i <= m; ++i)
    scanf("%d", b+i);
  memset(dp, -1, sizeof dp);
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    int a, p, v;
    tie(a, p, v) = song[i];
    int to = til[i];
    for (int j = 0; j <= s; ++j) {
      if (dp[i][j] == -1) continue;
      upd(dp[i+1][j], dp[i][j]);
      if (j + p <= s)
        upd(dp[i+1][j+p], dp[i][j] + v);
      if (j + b[a] <= s && to != -1)
        upd(dp[to][j+b[a]], dp[i][j] + sum[a]);
    }
  }
  long long ans = -1;
  for (int i = 0; i <= s; ++i)
    upd(ans, dp[n][i]);
  printf("%lld\n", ans);
}

int main() {
  int tt = 1;
  // scanf("%d", &tt);
  while (tt--) {
    solve();
  }
  return 0;
}
