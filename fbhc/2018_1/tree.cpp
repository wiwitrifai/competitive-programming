#include <bits/stdc++.h>

using namespace std;

const int N = 2048;

int a[N], b[N];

int pre[N], post[N];
int col[N];
int cntr;

void dfs_pre(int v) {
  if (!v) return;
  pre[cntr++] = v;
  dfs_pre(a[v]);
  dfs_pre(b[v]);
}

void dfs_post(int v) {
  if (!v) return;
  dfs_post(a[v]);
  dfs_post(b[v]);
  post[cntr++] = v;
}

int p[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

void merge(int u, int v) {
  if ((u = find(u)) == (v = find(v)))
    return;
  if (-p[v] < -p[u])
    swap(u, v);
  p[v] += p[u];
  p[u] = v;
}

int main() {
  clock_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i)
      scanf("%d %d", a+i, b+i);
    memset(p, -1, sizeof p);
    cntr = 0;
    dfs_pre(1);
    assert(cntr == n);
    cntr = 0;
    dfs_post(1);
    assert(cntr == n);
    for (int i = 0; i < n; ++i)
      merge(pre[i], post[i]);
    memset(col, -1, sizeof col);
    int now = 1;
    for (int i = 1; i <= n; ++i) {
      int v = find(i);
      if (col[v] != -1) continue;
      col[v] = min(now, k);
      ++now;
    }
    if (now <= k)
      printf("Case #%d: Impossible\n", tc);
    else {
      printf("Case #%d:", tc);
      for (int i = 1; i <= n; ++i) {
        int v = find(i);
        printf(" %d", col[v]);
      }
      printf("\n");
    }
    cerr << " TC# " << tc << " done ! time : " << (double)(clock() - startt) * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
  }
  return 0;
}