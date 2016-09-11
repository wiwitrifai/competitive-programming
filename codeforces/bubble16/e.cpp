#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector< int > adj[N];
int c[N], cnt[N];
int all;

void get(int u = 0, int p = -1) {
  cnt[u] = c[u] < 0;
  for (int v : adj[u]) if (v != p) {
    get(v, u);
    cnt[u] += cnt[v];
  }
}

void dfs(int u = 0, int p = -1) {
  printf("%d ", u+1);
  c[u] = -c[u];
  all -= c[u];
  for (int v : adj[u]) if (v != p) {
    if (cnt[v]) {
      dfs(v, u);
      if (all) {
        printf("%d ", u+1);
        c[u] = -c[u];
        all -= c[u];
      }
    }
  }
  if (c[u] < 0) {
    if (p >= 0) {
      c[p] = -c[p];
      c[u] = -c[u];
      all -= c[p];
      all -= c[u];
      printf("%d %d ", p+1, u+1);
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", c+i);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  get();
  all = cnt[0];
  c[0] = -c[0];
  all -= c[0];
  dfs();
  if (c[0] < 0) {
    printf("%d %d %d", adj[0][0]+1, 1, adj[0][0]+1);
  }
  printf("\n");
  return 0;
}