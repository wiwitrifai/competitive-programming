#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int a[N], b[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    if (u > v) swap(u, v);
    if (u == 1)
      a[v] = 1;
    if (v == n)
      b[u] = 1;
  }
  bool ans = 0;
  for (int i = 1; i <= n; i++)
    if (a[i] && b[i])
      ans = 1;
  puts(ans ? "POSSIBLE" : "IMPOSSIBLE"); 
  return 0;
}