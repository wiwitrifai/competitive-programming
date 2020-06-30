#include <bits/stdc++.h>

using namespace std;

vector<int> p;

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (-p[y] > -p[x])
    swap(x, y);
  p[x] += p[y];
  p[y] = x;
}

void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i)
    scanf("%d", &b[i]);
  long long x = 0, y = 1;
  for (int i = 0; i < n; ++i) {
    if (x * b[i] < a[i] * y) {
      x = a[i];
      y = b[i];
    }
  }
  vector<bool> can(n, false);
  for (int i = 0; i < n; ++i) {
    if (x * b[i] == a[i] * y) {
      can[i] = true;
    }
  }
  p.assign(n, -1);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    if (!can[u] || !can[v]) continue;
    merge(u, v);
  }
  int selected = -1, cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (find(i) != i) continue;
    if (!can[i]) continue;
    if (-p[i] > cnt) {
      selected = i;
      cnt = -p[i];
    }
  }
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (find(i) == selected)
      ans.push_back(i);
  }
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < (int)ans.size(); ++i) {
    printf("%d%c", ans[i]+1, i+1 == (int)ans.size() ? '\n' : ' ');
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
