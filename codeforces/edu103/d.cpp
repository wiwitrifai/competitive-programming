#include <bits/stdc++.h>

using namespace std;

struct Dsu {
  vector<int> p;
  Dsu(int _n) : p(_n, -1) {}

  int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }
  int cnt(int x) { return -p[find(x)]; }
  bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return false;
    if (-p[u] > -p[v])
      swap(u, v);
    p[v] += p[u];
    p[u] = v;
    return true;
  }
};

void solve() {
  int n;
  string s;
  cin >> n >> s;
  vector<Dsu> dsu(2, Dsu(n+1));
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'L') {
      int g = (i+1) & 1;
      dsu[g].merge(i, i+1);
    } else {
      int g = i & 1;
      dsu[g].merge(i, i+1);
    }
  }
  for (int i = 0; i <= n; ++i) {
    printf("%d%c", dsu[i & 1].cnt(i), i == n ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
