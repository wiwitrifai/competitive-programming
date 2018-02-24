#include <bits/stdc++.h>

using namespace std;

const int N = 1024, mod = 1e9 + 7, p = 43, q = 37;

int g[N][N];
int adj[N][N];
int numdiv[N];
int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}
pair<long long, long long> ho[N], hi[N];
long long pp[N], qq[N];
int ans[N], used[N];

int main() {
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j <= i; ++j) {
      if (i % j) continue;
      ++numdiv[i];
    }
  }
  pp[0] = qq[0] = 1;
  for (int i = 1; i < N; ++i) {
    pp[i] = 1LL * pp[i-1] * p % mod;
    qq[i] = 1LL * qq[i-1] * q % mod;
  }
  for (int i = 1; i < N; ++i)
    for (int j = 1; j < N; ++j) {
      if (i == j) continue;
      adj[i][j] = numdiv[gcd(i, j)];
    }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        scanf("%d", g[i]+j);
    for (int i = 1; i <= n; ++i) {
      ho[i] = {0, 0};
      hi[i] = {0, 0};
      for (int j = 1; j <= n; ++j) {
        ho[i].first = (ho[i].first + pp[adj[i][j]]) % mod;
        hi[i].first = (hi[i].first + pp[g[i][j]]) % mod;
      }
    }
    memset(ans, 0, sizeof ans);
    memset(used, 0, sizeof used);
    for (int c = 0; c < n; ++c) {
      map<pair<long long, long long>, int> mp;
      for (int i = 1; i <= n; ++i) {
        if (ans[i]) continue;
        mp[hi[i]]++;
      }
      int best = n * 2;
      pair<long long, long long> hs;
      for (auto it : mp) {
        if (it.second < best)
          hs = it.first, best = it.second;
      }
      int u = 0, v = 0;
      for (int i = 1; i <= n; ++i) {
        if (ans[i]) continue;
        if (hi[i] != hs) continue;
        u = i;
        break;
      }
      for (int i = 1; i <= n; ++i) {
        if (used[i]) continue;
        if (ho[i] != hs) continue;
        v = i;
        break;
      }
      ans[u] = v;
      used[v] = u;
      for (int i = 1; i <= n; ++i) {
        if (ans[i] == 0) {
          hi[i].first = (hi[i].first - pp[g[u][i]]) % mod;
          if (hi[i].first < 0) hi[i].first += mod;
          hi[i].second = (hi[i].second + 1LL * qq[c] * g[u][i]) % mod;
        }
        if (used[i] == 0) {
          ho[i].first = (ho[i].first - pp[adj[v][i]]) % mod;
          if (ho[i].first < 0) ho[i].first += mod;
          ho[i].second = (ho[i].second + 1LL * qq[c] * adj[v][i]) % mod;
        }
      }
    }
    for (int i = 1; i <= n; ++i)
      printf("%d\n", ans[i]);
  }
  return 0;
}