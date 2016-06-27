#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
int sz[N], p[N], ans[N], bsz[N];
vector< int > ch[N];
void getsz(int v) {
  sz[v] = 1;
  for(int u : ch[v]) {
    getsz(u);
    sz[v] += sz[u];
  }
}

void dfs(int v) {
  int big = -1; bsz[v] = 0;
  for(int u : ch[v]) {
    dfs(u);
    if(bsz[v] < sz[u]) {
      big = u;
      bsz[v] = sz[u];
    }
  }
  if(big != -1) {
    int x = ans[big];
    while(x != v && max(sz[v]-sz[x], bsz[x]) >= max(sz[v]-sz[p[x]], sz[x]))
      x = p[x];
    ans[v] = x; 
  }
  else
    ans[v] = v;
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for(int i = 1; i<n; i++) {
    scanf("%d", p+i);
    p[i]--;
    ch[p[i]].push_back(i);
  }
  getsz(0);
  dfs(0);
    while(q--) {
    int x;
    scanf("%d", &x);
    printf("%d\n", ans[x-1] + 1);
  }

  return 0;
}