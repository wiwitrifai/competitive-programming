#include <bits/stdc++.h>

using namespace std;

struct Dsu {
  vector<int> p;
  Dsu(int _n) : p(_n, -1) {}

  int find(int x) { 
    return p[x] < 0 ? x : p[x] = find(p[x]);
  }

  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (u > v)
      swap(u, v);
    p[u] = v;
  }

};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int k;
  scanf("%d", &k);
  vector<vector<int>> a(n, vector<int>(m));
  vector<Dsu> dsu(m, Dsu(n+1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i][j]);
      if (a[i][j] == 2) {
        dsu[j].merge(i, i+1);
      }
    }
  }
  for (int i = 0; i < k; ++i) {
    int r = 0, c;
    scanf("%d", &c);
    --c;
    while (r < n) {
      r = dsu[c].find(r);
      if (r >= n) break;
      if (a[r][c] == 3) {
        a[r][c] = 2;
        dsu[c].merge(r, r+1);
        --c;
      } else if (a[r][c] == 1) {
        a[r][c] = 2;
        dsu[c].merge(r, r+1);
        ++c;
      } else {
        ++r;
      }
    }
    printf("%d%c", c+1, i+1 == k ? '\n' : ' ');
  }
  return 0;
}
