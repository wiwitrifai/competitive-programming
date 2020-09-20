#include <bits/stdc++.h>

using namespace std;

struct Dsu {
  vector<int> p;
  Dsu(int _n) : p(_n, -1) {}
  int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }
  bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (-p[u] > -p[v])
      swap(u, v);
    p[v] += p[u];
    p[u] = v;
    return true;
  }
};

int main() {
  int n;
  scanf("%d", &n);
  vector<tuple<int, int, int>> vp;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x, --y;
    vp.emplace_back(y, x, i);
  }
  sort(vp.begin(), vp.end());
  Dsu dsu(n);
  stack<pair<int, int>> st;
  for (auto it : vp) {
    int x, y, id;
    tie(y, x, id) = it;
    int lef = x;
    while (!st.empty() && st.top().first <= x) {
      lef = min(lef, st.top().first);
      dsu.merge(id, st.top().second);
      st.pop();
    }
    st.push({lef, id});
  }
  for (int i = 0; i < n; ++i)
    printf("%d\n", -dsu.p[dsu.find(i)]);
  return 0;
}
