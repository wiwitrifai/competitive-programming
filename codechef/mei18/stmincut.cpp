#include <bits/stdc++.h>

using namespace std;

const int N = 2020;

int a[N][N], b[N][N];

vector<int> el[N];
int p[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

void merge(int u, int v, int w) {
  if ((u = find(u)) == (v = find(v))) return;
  if (-p[u] > -p[v]) swap(u, v);
  for (int x : el[u])
    for (int y : el[v])
      b[x][y] = b[y][x] = w;
  p[v] += p[u];
  p[u] = v;
  for (int x : el[u])
    el[v].push_back(x);
  el[u].clear();
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<tuple<int, int, int> > all;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        scanf("%d", a[i]+j);
        b[i][j] = a[i][j];
        all.emplace_back(a[i][j], i, j);
      }
      p[i] = -1;
      el[i].clear();
      el[i].push_back(i);
    }
    sort(all.begin(), all.end());
    reverse(all.begin(), all.end());
    for (auto it : all) {
      int u, v, w;
      tie(w, u, v) = it;
      merge(u, v, w);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j)
        ans += b[i][j] - a[i][j];
    }
    printf("%lld\n", ans);
  }
  return 0;
}