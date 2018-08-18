#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int p[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

void merge(int u, int v) {
  if ((u = find(u)) == (v = find(v)))
    return;
  if (-p[u] < -p[v])
    swap(u, v);
  p[u] += p[v];
  p[v] = u;
}

vector<int> chem[N];

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < q; ++i) {
    int r, c;
    scanf("%d %d", &r, &c);
    --r; --c;
    chem[c].push_back(r);
  }
  memset(p, -1, sizeof p);
  int ans = -1;
  for (int i = 0; i < m; ++i) {
    if (chem[i].empty()) {
      ++ans;
    }
    for (int u : chem[i])
      merge(u, chem[i][0]);
  }
  for (int i = 0; i < n; ++i)
    ans += p[i] < 0;
  printf("%d\n", ans);
  return 0;
}