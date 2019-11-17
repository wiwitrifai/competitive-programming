#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

map<int, int> node;
int p[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

bool merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) {
    return false;
  }
  p[u] = v;
  return true;
}

int main() {
  memset(p, -1, sizeof p);
  int n;
  scanf("%d", &n);
  vector<tuple<int, int, int>> ans;
  for (int i = 1; i <= n; ++i) {
    int m;
    scanf("%d", &m);
    for (int j = 0; j < m; ++j) {
      int x;
      scanf("%d", &x);
      if (node[x]) {
        if (merge(node[x], i))
          ans.emplace_back(node[x], i, x);
      }
      else
        node[x] = i;
    }
  }
  if ((int)ans.size() != n-1) {
    puts("impossible");
    return 0;
  }
  for (auto e : ans) {
    int u, v, w;
    tie(u, v, w) = e;
    printf("%d %d %d\n", u, v, w);
  }
  return 0;
}
