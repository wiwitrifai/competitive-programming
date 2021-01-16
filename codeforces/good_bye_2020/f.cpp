#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

struct Dsu {
  vector<int> p;
  vector<bool> flag;
  Dsu(int n_) : p(n_, -1), flag(n_, false) {
  }
  int find(int x) {
    return p[x] < 0 ? x : p[x] = find(p[x]);
  }
  bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return false;
    if (flag[u] && flag[v]) return false;
    if (-p[u] > -p[v])
      swap(u, v);
    flag[v] = flag[v] | flag[u];
    p[v] += p[u];
    p[u] = v;
    return true;
  }
};


int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  Dsu dsu(m);
  int ans = 1;
  vector<int> ids;
  for (int i = 0; i < n; ++i) {
    int k, x, y;
    scanf("%d", &k);
    if (k == 1) {
      scanf("%d", &x);
      --x;
      x = dsu.find(x);
      if (!dsu.flag[x]) {
        dsu.flag[x] = true;
        ans = ans * 2 % mod;
        ids.push_back(i+1);
      }
    } else {
      scanf("%d %d", &x, &y);
      --x, --y;
      if (dsu.merge(x, y)) {
        ans = ans * 2 % mod;
        ids.push_back(i+1);
      }
    }
  }
  printf("%d %d\n", ans, (int)ids.size());
  for (int i = 0; i < (int)ids.size(); ++i) {
    printf("%d%c", ids[i], i+1 == (int)ids.size() ? '\n' : ' ');
  }
  return 0;
}
