#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

struct Dsu {
  vector<int> p, cost;
  Dsu(int _n) : p(_n, -1) {}

  int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  Dsu dsu(m);
  vector<int> cnt(m, 0);
  for (int i = 0; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    u = dsu.find(u);
    v = dsu.find(v);
    if (u != v) {
      dsu.p[v] += dsu.p[u];
      dsu.p[u] = v;
      cnt[v] += cnt[u];
    }
    ++cnt[v];
  }
  long long ans = 1;
  for (int i = 0; i < m; ++i) {
    if (dsu.find(i) == i) {
      if (cnt[i] == -dsu.p[i]) {
        ans = ans * 2 % mod;
      } else if (cnt[i]+1 == -dsu.p[i]) {
        ans = ans * (cnt[i] + 1LL) % mod;
      } else {
        ans = 0;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
