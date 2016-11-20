#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

vector < pair< int, int > > adj[N];
int sz[N];

void getsz(int v, int p = -1) {
  for (auto u : adj[v]) if (u.first != p) {
    getsz(u.first, v);
    sz[v] += sz[u.first];
  }
}
int m;
long long dfs(int v, int p = -1) {
  long long ret = 0;
  for (auto u : adj[v]) if (u.first != p) {
    if (sz[u.first] == 0)
      continue;
    ret += 1LL * u.second * (sz[u.first]) * (m - sz[u.first]);
    ret += dfs(u.first, v);
  }
  return ret;
}
long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      adj[i].clear();
      sz[i] = 0;
    }
    for (int i = 1; i < n; i++) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      u--; v--;
      adj[u].emplace_back(v, w);
      adj[v].emplace_back(u, w);
    }
    for (int i = 0; i < m; i++) {
      int a;
      scanf("%d", &a);
      sz[--a]++;
    }
    getsz(0);
    long long numer = 2LL * dfs(0);
    long long denom = 1LL * m * m;
    long long d = gcd(numer, denom);
    numer /= d;
    denom /= d;
    printf("%lld %lld\n", numer, denom);
  }

  return 0;
}