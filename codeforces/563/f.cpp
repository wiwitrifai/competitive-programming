#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, LG = 19;

void answer(int v) {
  printf("! %d\n", v);
  fflush(stdout);
  exit(0);
}

int dst[N];
int dist(int v) {
  if (dst[v] != -1)
    return dst[v];
  printf("d %d\n", v);
  fflush(stdout);
  int d;
  scanf("%d", &d);
  dst[v] = d;
  if (d == 0)
    answer(v);
  return d;
}

int go(int v) {
  printf("s %d\n", v);
  fflush(stdout);
  int d;
  scanf("%d", &d);
  return d;
}

vector<int> g[N];
int par[LG][N];
int lv[N], cnt[N], best[N];
int pos;

void dfs(int v, int p) {
  par[0][v] = p;
  for (int i = 0; i+1 < LG; ++i) {
    par[i+1][v] = par[i][par[i][v]];
  }
  cnt[v] = 0;
  best[v] = -1;
  if (lv[v] == pos) {
    best[v] = v;
    cnt[v] = 1;
  }
  int pilih = -1;
  for (int u : g[v]) {
    if (u == p) continue;
    lv[u] = lv[v]+1;
    dfs(u, v);
    if (lv[v] < pos) {
      if (pilih == -1 || cnt[u] > cnt[pilih])
        pilih = u;
    }
    cnt[v] += cnt[u];
  }
  if (pilih != -1)
    best[v] = best[pilih];
}

int ancestor(int v, int d) {
  for (int i = 0; i < LG; ++i)
    if (d & (1 << i))
      v = par[i][v];
  return v;
}

int main() {
  memset(dst, -1, sizeof dst);
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  pos = dist(1);
  lv[1] = 0;
  dfs(1, 1);
  int v = 1;
  while (lv[v] != pos) {
    int u = best[v];
    assert(u != -1);
    int d = dist(u);
    assert((d & 1) == 0);
    d /= 2;
    if (pos - d > lv[v]) {
      v = ancestor(u, d);
    }
    else
      v = go(v);
  }
  answer(v);
  return 0;
}
