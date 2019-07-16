#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m;

int d[N], ori[N], id[N], val[N];
vector<pair<int, int> > edge;


int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    ++d[u];
    ++d[v];
    edge.emplace_back(u, v);
  }
  if (m == n-1) {
    printf("%d\n", 0);
    printf("%d %d\n", n, m);
    for (int i = 0; i < m; ++i) {
      printf("%d %d\n", edge[i].first, edge[i].second);
    }
    return 0;
  }
  for (int i = 0; i < n; ++i) ori[i] = d[i], id[i] = i;
  sort(id, id+n, [&](int l, int r) { return d[l] < d[r]; });
  for (int i = 0; i < n; ++i) val[i] = 1;
  int sisa = 2 * (n-1) - n;
  for (int i = 0; i < n; ++i) {
    int v = id[i];
    int b = min(sisa, d[v] - val[v]);
    val[v] += b;
    sisa -= b;
  }
  if (sisa > 0) {
    val[id[n-1]] += sisa;
  }
  set<int> one;
  set<pair<int, int> > small;
  for (int i = 0; i < n; ++i) {
    if (val[i] == 1)
      one.insert(i);
    else
      small.insert(make_pair(val[i], i));
  }
  vector<pair<int, int> > ans;
  while (small.size() > 0) {
    auto it = small.begin();
    int now = it->second;
    small.erase(it);
    for (int i = 1; i < val[now]; ++i) {
      assert(!one.empty());
      auto nx = one.begin();
      ans.emplace_back(now, *nx);
      one.erase(nx);
    }
    one.insert(now);
  }
  while (one.size() > 1) {
    auto it = one.begin();
    int v = *it;
    one.erase(it);
    it = one.begin();
    int u = *it;
    one.erase(it);
    ans.emplace_back(u, v);
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i)
    cnt += val[i] != ori[i];
  printf("%d\n%d %d\n", cnt, n, ans.size());
  for (auto it : ans) {
    printf("%d %d\n", it.first, it.second);
  }
  return 0;
}
