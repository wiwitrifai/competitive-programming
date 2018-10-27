#include <bits/stdc++.h>

using namespace std;

const int N = 1024;
const long long inf = 1e18;

int c[N][N];
vector<pair<int, int> > g[N];
int p[N];
long long s[N], t[N];
long long d[N][N];
long long tot[N][N], wait[N][N];
int n, m, k;
long long dp[N];
bool ok[N];

bool can(long long x) {
  for (int i = 0; i < k; ++i) {
    ok[i] = 0;
    dp[i] = inf;
    if (wait[0][i] <= x) {
      dp[i] = t[i] + tot[0][i];
      ok[i] = 1;
    }
    for (int j = 0; j < i; ++j) {
      if (!ok[j]) continue;
      long long cur = dp[j];
      long long w = wait[j+1][i] + max(0LL, cur - t[i]);
      if (w <= x) {
        dp[i] = min(dp[i], max(cur, t[i]) + tot[j+1][i]);
        ok[i] = 1;
      }
    }
    if (ok[i])
      assert(dp[i] < inf);
  }
  return ok[k-1];
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    --u, --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  scanf("%d", &k);
  for (int i = 0; i < k; ++i) {
    scanf("%lld %d %lld", s+i, p+i, t+i);
    --p[i];
  }
  for (int i = 0; i < n; ++i) {
    fill(d[i], d[i]+n, inf);
    priority_queue<pair<long long, int> > pq;
    d[i][i] = 0;
    pq.push(make_pair(-d[i][i], i));
    while (!pq.empty()) {
      auto it = pq.top(); pq.pop();
      int v = it.second;
      if (-it.first != d[i][v]) continue;
      for (auto nxt : g[v]) {
        int u = nxt.first;
        if (d[i][u] > d[i][v] + nxt.second) {
          d[i][u] = d[i][v] + nxt.second;
          pq.push(make_pair(-d[i][u], u));
        }
      }
    }
  }
  for (int i = 0; i < k; ++i) {
    tot[i][i] = d[0][p[i]];
    wait[i][i] = t[i] - s[i] + tot[i][i];
    for (int j = i+1; j < k; ++j) {
      tot[i][j] = tot[i][j-1] + d[p[j-1]][p[j]];
      wait[i][j] = max(wait[i][j-1] + t[j] - t[j-1], tot[i][j] + t[j] - s[j]);
    }
    for (int j = i; j < k; ++j)
      tot[i][j] += d[0][p[j]];
  }
  long long lo = 0, hi = inf;
  while (lo < hi) {
    long long mid = (lo + hi) >> 1;
    if (can(mid))
      hi = mid;
    else
      lo = mid+1;
  }
  printf("%lld\n", lo);
  return 0;
}