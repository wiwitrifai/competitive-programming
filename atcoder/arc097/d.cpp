#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int p[N], a[N];

int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }
void merge(int u, int v) {
  if ((u = find(u)) == (v = find(v))) return; 
  if (-p[u] > -p[v]) swap(u, v);
  p[v] += p[u];
  p[u] = v;
}
vector<int> e[N];
bool used[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i), --a[i];
  memset(p, -1, sizeof p);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v); --u, --v;
    merge(u, v);
  }
  for (int i = 0; i < n; ++i)
    e[find(i)].push_back(i);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (e[i].empty()) continue;
    for (int x : e[i])
      used[x] = 1;
    for (int x : e[i])
      ans += used[a[x]];
    for (int x : e[i])
      used[x] = 0;
  }
  printf("%d\n", ans);
  return 0;
}