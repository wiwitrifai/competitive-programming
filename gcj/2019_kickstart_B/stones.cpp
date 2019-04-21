#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const long long inf = 1e17 + 7;

long long dp[N][N * N];
int id[N], s[N], e[N], l[N];

void upd(long long & var, long long val) {
  if (var < val)
    var = val;
}

void solve(int tc) {
  int n;
  scanf("%d", &n);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d %d %d", s+i, e+i, l+i);
    id[i] = i;
    sum += s[i];
  }
  sort(id, id+n, [&](int lef, int rig) {
    long long vl = 1LL * s[lef] * l[rig], vr = 1LL * s[rig] * l[lef];
    if (vl != vr)
      return vl < vr;
    return s[lef] < s[rig];
  });
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= sum; ++j) {
      dp[i][j] = -inf;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    int x = id[i];
    for (int j = 0; j <= sum; ++j) {
      long long now = dp[i][j];
      if (now <= -inf) continue;
      upd(dp[i+1][j], now);
      long long cost = max(0LL, e[x] - 1LL * l[x] * j);
      upd(dp[i+1][j+s[x]], now + cost);
    }
  }
  long long ans = 0;
  for (int i = 0; i <= sum; ++i)
    upd(ans, dp[n][i]);
  printf("Case #%d: %lld\n", tc, ans);
}

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    solve(tc);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << " s" << endl;
  }
  return 0;
}
