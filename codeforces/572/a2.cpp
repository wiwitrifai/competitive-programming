// AC
#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

vector<int> g[N], adj[N];

int a[N], b[N], val[N];

vector<tuple<int, int, int>> ans;

int get_leaf(int v, int i) {
  if (g[v].size() == 1)
    return v;
  for (int j : g[v]) {
    if (i == j) continue;
    return get_leaf(a[j]^b[j]^v, j);
  }
  assert(false);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n-1; ++i) {
    scanf("%d %d %d", a+i, b+i, val+i);
    g[a[i]].push_back(i);
    g[b[i]].push_back(i);
  }
  if (n == 2) {
    printf("YES\n1\n%d %d %d\n", a[0], b[0], val[0]);
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    if ((int)g[i].size() == 2) {
      puts("NO");
      return 0;
    }
  }
  for (int i = 0; i < n-1; ++i) {
    int u = a[i], v = b[i];
    if (g[u].size() > g[v].size())
      swap(u, v);
    if (g[u].size() == 1) {
      int c = -1, d = -1;
      for (int x : g[v]) {
        if (x == i) continue;
        if (c == -1)
          c = x;
        else {
          d = x;
          break;
        }
      }
      c = get_leaf(a[c]^b[c]^v, c);
      d = get_leaf(a[d]^b[d]^v, d);
      int w = val[i]/2;
      ans.emplace_back(u, c, w);
      ans.emplace_back(u, d, w);
      ans.emplace_back(c, d, -w);
    }
    else {
      int c = -1, d = -1;
      for (int x : g[v]) {
        if (x == i) continue;
        if (c == -1)
          c = x;
        else {
          d = x;
          break;
        }
      }
      c = get_leaf(a[c]^b[c]^v, c);
      d = get_leaf(a[d]^b[d]^v, d);
      int p = -1, q = -1;
      for (int x : g[u]) {
        if (x == i) continue;
        if (p == -1)
          p = x;
        else {
          q = x;
          break;
        }
      }
      p = get_leaf(a[p]^b[p]^u, p);
      q = get_leaf(a[q]^b[q]^u, q);
      int w = val[i]/2;
      ans.emplace_back(p, c, w);
      ans.emplace_back(q, d, w);
      ans.emplace_back(c, d, -w);
      ans.emplace_back(p, q, -w);
    }
  }
  puts("YES");
  printf("%d\n", (int)ans.size());
  for (auto it : ans) {
    int u, v, w;
    tie(u, v, w) = it;
    printf("%d %d %d\n", u, v, w);
  }
  return 0;
}
