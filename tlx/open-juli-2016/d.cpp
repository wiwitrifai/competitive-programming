#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, NL = 20;

int p[N][NL], lv[N];

int lca(int u, int v) {
  if(lv[u] > lv[v])
    swap(u, v);
  int diff = lv[v] - lv[u];
  for(int i = 0; i<NL; i++)
    if(diff & (1<<i))
      v = p[v][i];
  if(u == v)
    return u;
  for(int i = NL-1; i>=0; i--)
    if(p[u][i] != p[v][i])
      u = p[u][i], v = p[v][i];
  return p[u][0];
}

int main() {
  int q;
  int now = 2;
  for(int i = 0; i<NL; i++)
    p[1][i] = 1;
  lv[1] = 0;
  scanf("%d", &q);
  while(q--) {
    int t, x, y, z;
    scanf("%d%d", &t, &x);
    if(t == 1) {
      p[now][0] = x;
      for(int i = 1; i<NL; i++)
        p[now][i] = p[p[now][i-1]][i-1];
      lv[now] = lv[x] + 1;
      now++;
    }
    else {
      scanf("%d%d", &y, &z);
      int xy = lca(x, y), xz = lca(x, z), yz = lca(y, z);
      if(lv[xz] < lv[yz])
        xz = yz;
      int ans;
      if(lv[xz] < lv[xy])
        ans = xy;
      else
        ans = xz;
      printf("%d\n", ans);
    }
  }
  return 0;
}