#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 +5;
vector< int > adj[N];

int n, a[N], val[N][2], st[N], fs[N], lv[N], tmp = 0;

void dfs(int v, int p = -1) {
  if(p + 1) {
    lv[v] = lv[p]+1;
  }
  else {
    lv[v] = 0;
    tmp = 0;
  }
  st[v] = tmp++;
  val[v][0] = 0;
  val[v][1] = a[v];
  for(auto u : adj[v]) if(u != p) {
    dfs(u, v);
    val[v][0] ^= val[u][1];
    val[v][1] ^= val[u][0];
  }
  fs[v] = tmp++;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i<n; i++)
    scanf("%d", a+i);
  for(int i = 1; i<n; i++) {
    int u, v;
    scanf("%d%d", &u, &v); u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0);
  int q;
  scanf("%d", &q);
  while(q--) {
    int u, v;
    scanf("%d%d", &u, &v); u--; v--;
    if(st[u] <= st[v] && fs[v] <= fs[u]) {
      puts("INVALID");
      continue;
    }
    int ans =  val[0][0] ^ val[u][lv[u] & 1] ^ val[u][(lv[v]+1) & 1];
    puts(ans ? "YES" : "NO");
  }
  return 0;
}