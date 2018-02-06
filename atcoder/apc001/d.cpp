#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int p[N], a[N];
int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}
int merge(int u, int v) {
  if ((u = find(u)) == (v = find(v)))
    return -1;
  if (-p[u] > -p[v])
    swap(u, v);
  p[v] += p[u];
  p[u] = v;
  return v;
}

vector<int> val[N];

int main() {
  int n, m;
  memset(p, -1, sizeof p);
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  int tot = n;
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    tot -= merge(u, v) != -1;
  }
  for (int i = 0; i < n; ++i)
    val[find(i)].push_back(a[i]);
  vector<int> all;
  long long ans = 0;
  if (tot <= 1) {
    puts("0");
    return 0;
  }
  for (int i = 0; i < n; ++i) if (find(i) == i) {
    sort(val[i].begin(), val[i].end());
    ans += val[i][0];
    for (int j = 1; j < min((int)val[i].size(), tot - 1); ++j)
      all.push_back(val[i][j]);
  }
  if ((int)all.size() < tot-2) {
    puts("Impossible");
    return 0;
  }
  sort(all.begin(), all.end());
  for (int i = 0; i < tot-2; ++i)
    ans += all[i];
  printf("%lld\n", ans);
  return 0;
}