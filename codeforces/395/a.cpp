#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int p[N], n, c[N];
pair< int, int > e[N];
vector< pair< int, int > > adj[N];

int find(int x) {
  return (p[x] < 0) ? x : p[x] = find(p[x]);
}
int cnt[N];
bool merge(int u, int v) {
  if ((u = find(u)) == (v = find(v)))
    return 0;
  if (p[u] < p[v])
    swap(u, v);
  p[v] += p[u];
  p[u] = v;
  return 1;
}
int main() {
  scanf("%d", &n);
  memset(p, -1, sizeof p);
  for (int i = 0; i < n-1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    e[i] = make_pair(u, v);
  }
  for (int i = 0; i < n; i++)
    scanf("%d", c+i);
  int g = n;
  for (int i = 0; i < n-1; i++) {
    int u = e[i].first, v = e[i].second;
    if (c[u] == c[v])
      g -= merge(u, v);
  }
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n-1; i++) {
    int u = e[i].first, v = e[i].second;
    if (c[u] != c[v])
      cnt[u]++, cnt[v]++;
  }
  int ans = -1;
  for (int i = 0; i < n; i++)
    if (cnt[i] >= g-1)
      ans = i;
  if (ans != -1)
    printf("YES\n%d\n", ans+1);
  else
    puts("NO");

  return 0;
}