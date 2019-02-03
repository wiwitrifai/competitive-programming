#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 4;

vector<int> g[N];
int cnt[2];
int col[N];

void dfs(int v, int par = -1) {
  ++cnt[col[v]];
  for (int u : g[v]) if (u != par) {
    col[u] = col[v] ^ 1;
    dfs(u, v);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      g[i].clear();
    for (int i = 0; i < n-1; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    col[0] = 0;
    memset(cnt, 0, sizeof cnt);
    dfs(0);
    if (cnt[0] == cnt[1]) {
      puts("1");
    }
    else {
      puts("2");
      int rem = cnt[0] > cnt[1] ? 0 : 1;
      int need = cnt[rem] - n/2;
      for (int i = 0; i < n; ++i) {
        if (g[i].size() > 1) continue;
        if (col[i] != rem) continue;
        col[i] = rem ^ 1;
        --need;
        if (need == 0)
          break;
      }
      assert(need == 0);
    }
    for (int i = 0, cur = 0; i < n; ++i) {
      if (col[i] == 0) continue;
      ++cur;
      printf("%d%c", i+1, 2 * cur == n ? '\n' : ' ');
    }
    for (int i = 0, cur = 0; i < n; ++i) {
      if (col[i] == 1) continue;
      ++cur;
      printf("%d%c", i+1, 2 * cur == n ? '\n' : ' ');
    }
  }
  return 0;
}