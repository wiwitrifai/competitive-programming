#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int p[N], to[N], ord[N];
set<int> st[N];

int find(int x) {
  return to[x] < 0 ? x : to[x] = find(to[x]);
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return;
  if (st[u].size() > st[v].size())
    swap(u, v);
  for (int x : st[u])
    st[v].insert(x);
  to[u] = v;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", p+i), st[i].insert(p[i]), to[i] = -1;
  iota(ord, ord+n, 0);
  sort(ord, ord+n, [](int l, int r) {
    return p[l] < p[r];
  });
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int now = ord[i];
    if (now > 0 && now < n-1 && p[now-1] <= i && p[now+1] <= i) {
      int u = find(now - 1), v = find(now + 1);
      assert(u != v);
      if (st[u].size() > st[v].size())
        swap(u, v);
      for (int x : st[u])
        ans += st[v].count(p[now] - x);
    }
    if (now + 1 < n && p[now+1] <= i)
      merge(now, now + 1);
    if (now > 0 && p[now-1] <= i)
      merge(now - 1, now);
  }
  printf("%d\n", ans);
  return 0;
}
