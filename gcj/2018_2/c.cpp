#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int a[N][N];
int cnt[N+N];

vector<int> g[N];

int match[N], matched[N];
bool mark[N];

// The code below finds a augmenting path:
bool dfs(int v){// v is in X, it reaturns true if and only if there is an augmenting path starting from v
  if(mark[v])
    return false;
  mark[v] = true;
  for(auto &u : g[v])
    if(match[u] == -1 or dfs(match[u])) // match[i] = the vertex i is matched with in the current matching, initially -1
      return matched[v] = u, match[u] = v, true;
  return false;
}

void solve(int tc) {
  printf("Case #%d: ", tc);
  int n;
  scanf("%d", &n);
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", a[i]+j);
      a[i][j] += N;
      ++cnt[a[i][j]];
    }
  }
  int ans = n * n;
  for (int w = 0; w <= N+N; ++w) {
    if (cnt[w] == 0) continue;
    for (int i = 0; i < n; ++i)
      g[i].clear(), matched[i] = match[i] = -1;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (a[i][j] == w)
          g[i].push_back(j);
    while(true){
      memset(mark, false, sizeof mark);
      bool fnd = false;
      for(int i = 0;i < n;i ++) if(matched[i] == -1 && !mark[i]) {
        bool res = dfs(i);
        ans -= res;
        fnd |= res;
      }
      if(!fnd)
        break;
    }
  }
  printf("%d\n", ans);
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    solve(tc);
  }
  return 0;
}