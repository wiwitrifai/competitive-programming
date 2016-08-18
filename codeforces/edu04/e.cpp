#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int n, p[N], q[N];
bool vis[N];
vector< int > cyc[N];

void merge(int u, int v, int sz) {
  if(v == -1) {
    int off = (sz + 1) >> 1;
    v = u;
    while(off--)
      v = p[v];
    for(int i = 0; i<sz; i++) {
      q[u] = v;
      u = p[u];
      q[v] = u;
      v = p[v];
    }
  }
  else {
    for(int i = 0; i<sz; i++) {
      q[u] = v;
      u = p[u];
      q[v] = u;
      v = p[v];
    }
  }
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i<=n; i++)
    scanf("%d", p+i);
  memset(vis, false, sizeof vis);
  for(int i = 1; i<=n; i++) if(!vis[i]) {
    int now = i, cnt = 0;
    while(!vis[now]) {
      cnt++;
      vis[now] = true;
      now = p[now];
    }
    cyc[cnt].push_back(i);
  }
  for(int i = 1; i<=n; i++) {
    if(i & 1) {
      for(int j = 0; j<cyc[i].size(); j++)
        merge(cyc[i][j], -1, i);
    }
    else {
      if(cyc[i].size() & 1) {
        puts("-1");
        return 0;
      }
      for(int j = 0; j<cyc[i].size(); j+= 2)
        merge(cyc[i][j], cyc[i][j+1], i);
    }
  }
  for(int i = 1; i<=n; i++)
    printf("%d%c", q[i], (i < n) ? ' ' : '\n');
  return 0;
}