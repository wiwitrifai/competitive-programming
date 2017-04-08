#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 6;
vector< int > g[N];

bool ans = 1;
int gagal = -1;

int dfs(int v, int par = -1) {
  int ret = par == -1 ? g[v].size() > 1 : g[v].size() > 2;
  int cnt = 0;
  for (int u : g[v]) if (u != par) {
    int res = dfs(u, v);
    cnt += res;
    ret |= res;
  }
  if (par == -1) {
    if (cnt > 2) {
      ans = 0;
      gagal = v;
    }
  }
  else {
    if (cnt > 1) {
      ans = 0;
      gagal = v;
    }
  }
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  ans = 1;

  dfs(0);
  if (ans == 0) {
    ans = 1;
    dfs(gagal);
  }
  puts(ans ? "YES" : "NO");
  return 0;
}