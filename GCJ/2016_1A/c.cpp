/*
  iafir
  GCJ2016 Round 1A Problem C
  -Accepted-
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1024;
int to[N];
int used[N];
bool ok[N];
vector< int > adj[N];

int dfs(int v, int p) {
  used[v] = 2;
  int ret = 0;
  for(auto u : adj[v]) if(u != p) {
    ret = max(ret, dfs(u, v));
  }
  ret++;
  return ret;
}

int main() {
  memset(ok, false, sizeof ok);
  int tt;
  scanf("%d", &tt);
  for(int tc = 1; tc <= tt; tc++) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++)
      adj[i].clear();
    for(int i = 0; i<n; i++) {
      scanf("%d", to+i);
      to[i]--;
      adj[to[i]].push_back(i);
      used[i] = 0;
    }
    int ans = 0;
    for(int i = 0; i<n; i++) if(!used[i] && (to[to[i]] == i)) {
      ans += dfs(to[i], i)+dfs(i, to[i]);
    }
    for(int i = 0; i<n; i++) if(!used[i]) {
      int now = i, cur = 0;
      while(used[now] == 0) {
        cur++;
        used[now] = cur;
        ok[now] = true;
        now = to[now];
      }
      if(ok[now])
        ans = max(ans, cur-used[now]+1);
      now = i;
      while(ok[now]) {
        ok[now] = false;
        now = to[now];
      }
    }
    printf("Case #%d: %d\n", tc, ans);
    cerr << "Case #"<<tc << " Done" << endl;
  }
  return 0;
}