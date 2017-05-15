#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

vector < int > g[N];
int val[N];
int cnt[20];

void dfs(int v, int par = -1) {
  for (int u : g[v]) if (u != par)
    dfs(u, v);
  memset(cnt, 0, sizeof cnt);
  int bg = 0;
  for (int u : g[v]) if (u != par) {
    int now = val[u], cur = 0;
    while (now) {
      if (now & 1)
        cnt[cur]++;
      cur++;
      now >>= 1;
    }
    bg = max(bg, cur);
  }
  if (bg == 0)
    val[v] = 1;
  else {
    val[v] = 0;
    while (bg > 0) {
      bg--;
      if (cnt[bg])
        val[v] += 1 << bg;
      if (cnt[bg] > 1)
        break;
    }
    val[v] += 1<<bg;
  }
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
  dfs(0);
  printf("%d\n", 32-__builtin_clz(val[0]));
  return 0;
}