#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

vector< int > adj[N];

pair< int, int > dfs(int v, int par = -1, int depth = 0) {
  pair< int, int > ret;
  ret.first = depth;
  ret.second = v;
  for (int u : adj[v]) if (u != par) {
    ret = max(ret, dfs(u, v, depth+1));
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
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  pair< int, int > res = dfs(0);
  res = dfs(res.second);
  int ans = 0;
  int len = res.first;
  while (len > 0) {
    ans++;
    len--;
    len >>= 1;
  }
  printf("%d\n", ans);
  return 0;
}