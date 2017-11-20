#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
const long long inf = 1e18;
int n, m, a, b;
int v[N];
long long dp[N];

vector<int> g[N];
char s[55];

int main() {
  scanf("%d %d %*d %d %d", &n, &m, &a, &b);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%s %d", s, v+i);
    if (s[0] == 'P')
      scanf("%*d"), v[i] = 0;
    else if (s[0] == 'T')
      v[i] = -v[i];
  }
  for (int i = n; i > 0; i--) {
    dp[i] = -inf;
    for (int u : g[i])
      dp[i] = max(dp[i], dp[u] + v[u]);
    if (dp[i] == -inf)
      dp[i] = 0;
  }
  printf("%lld %lld\n", dp[a], dp[b]);
  return 0;
}