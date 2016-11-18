#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000

int n;
int far[MAXN+5], lv[MAXN+5];
int sub[MAXN+5];
long long ans[MAXN+5];
vector<int> edge[MAXN+5];

long long plant(int v, int dep = 0, int p = 0)
{
  //printf("%d %d %d\n", v, dep, p);
  sub[v] = 1;
  lv[v] = dep;
  far[v] = dep;
  long long ret = dep;
  for (int i = 0; i < edge[v].size(); ++i) {
    int u = edge[v][i];
    if (u == p) continue;
    ret += plant(u, dep+1, v);
    far[v] = max(far[u], far[v]);
    sub[v] += sub[u];
  }
  return ret;
}

int count(int v, long long td, int mx, int p = 0)
{
  // printf("%d %d %d %d\n", v, td, mx, p);
  int sz = n-sub[v];
  int subs = sz;

  int f_idx = -1, s_idx = -1;
  for (int i = 0; i < edge[v].size(); ++i) {
    int u = edge[v][i];
    if (u == p) continue;

    if (f_idx == -1 || far[f_idx] <= far[u]) {
      s_idx = f_idx;
      f_idx = u;
    }
    subs += sub[u];
  }
  ans[v] = -1;
  for (int i = 0; i < edge[v].size(); ++i) {
    int u = edge[v][i];
    if (u == p) continue;
    int nx;
    if (f_idx == -1) nx = 0;
    else if (u == f_idx) nx = (s_idx == -1) ? 0 : far[s_idx]-lv[u];
    else nx = far[f_idx]-lv[u];
    // printf("%d %d %d\n", v, u, nx);
    count(u, td-sub[u]+n-sub[u], max(mx, nx+1)+1, v);
    if (subs-sub[u]+1 == sub[u]) {
      int fx = (f_idx == -1) ? 0 : far[f_idx];
      int sx = (s_idx == -1) ? 0 : far[s_idx];
      if (mx >= fx) {
        ans[v] = 2*td-;   
      }
    }
    if (subs-sub[v] <= sub[v]) {
      int f = mx;
      if (!first) f = max(f, far[f_idx]);
      ans[v] = 2*td-f;
    }
  }

}

int main()
{
  freopen("inspection.in", "r", stdin);
  freopen("inspection.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < n-1; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  long long td = plant(1);
  count(1, td, 0);
  for (int i = 1; i <= n; ++i) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}