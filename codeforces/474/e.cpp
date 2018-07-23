#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 65, mod = 1e9 + 7;

vector<int> g[N];

int w[N];
int col[N], pr[N];
int sz[N][2];

long long ans = 0;

void dfs(int v, int par = -1, int c = 0) {
  pr[v] = par; 
  ++sz[v][c];
  col[v] = c;
  for (int u : g[v]) if (u != par) {
    dfs(u, v, c^1);
    sz[v][0] += sz[u][0];
    sz[v][1] += sz[u][1];
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", w+i);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  ans = 0;
  dfs(0);
  for (int v = 0; v < n; ++v) {
    vector<pair<int, int> > vs;
    for (int u : g[v]) if (u != pr[v])
      vs.emplace_back(sz[u][0], sz[u][1]);
    if (pr[v] != -1)
      vs.emplace_back(sz[0][0] - sz[v][0], sz[0][1] - sz[v][1]);
    long long cnt = n;
    if (col[v]) {
      for (pair<int, int> e : vs) {
        cnt = (cnt + 1LL * e.second * (n - e.first - e.second)) % mod;
        cnt = (cnt - 1LL * e.first * (n - e.first - e.second)) % mod; 
      }
    }
    else {
      for (pair<int, int> e : vs) {
        cnt = (cnt - 1LL * e.second * (n - e.first - e.second)) % mod;
        cnt = (cnt + 1LL * e.first * (n - e.first - e.second)) % mod; 
      }
    }
    cnt %= mod;
    if (cnt < 0) cnt += mod;
    ans = (ans + cnt * w[v]) % mod;
  }
  ans %= mod;
  if (ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}