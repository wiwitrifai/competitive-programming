#include <bits/stdc++.h>

using namespace std;


const int N = 1e5 + 5, LN = 18;

int n;
int ts[N<<1], nts, pw[N<<1];
int sparse[LN][N<<1], lv[N];
vector< int > adj[N];
int l[N], r[N];
void dfs(int v, int par = -1) {
  if(par != -1)
    lv[v] = lv[par] + 1;
  l[v] = nts;
  ts[nts++] = v;
  for(int u : adj[v]) if(u != par) {
    dfs(u, v);
    ts[nts++] = v;
  }
  r[v] = nts-1;
}

int main() {
  pw[0] = -1;
  pw[1] = 0;
  for(int i = 2; i<N<<1; i++)
    pw[i] = pw[i>>1] + 1;
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    for(int i = 0; i<n; i++)
      adj[i].clear();
    for(int i = 1; i<n; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    nts = 0;
    lv[0] = 0;
    dfs(0);
    memset(sparse, -1, sizeof sparse);
    for(int i = 0; i<nts; i++)
      sparse[0][i] = ts[i];
    for(int i = 0; i<LN-1; i++) {
      int to = nts- ((1<<(i+1)) - 1);
      for(int j = 0; j<to; j++) {
        int tmp1 = sparse[i][j], tmp2 = sparse[i][j + (1<<i)];
        sparse[i+1][j] = (lv[tmp1] <= lv[tmp2]) ? tmp1 : tmp2;
      }
    }
    set< int > range;
    int q;
    scanf("%d", &q);
    while(q--) {
      char sign;
      int v;
      scanf(" %c%d", &sign, &v);
      if(sign == '+') {
        range.insert(l[v]);
        range.insert(r[v]);
      }
      else {
        range.erase(l[v]);
        range.erase(r[v]);
      }
      if(range.empty())
        puts("-1");
      else {
        int lef = *range.begin(), rig = *(--range.end());
        int len = rig-lef+1;
        int tmp1 = sparse[pw[len]][lef], tmp2 = sparse[pw[len]][rig - (1<<pw[len]) + 1];
        printf("%d\n", (lv[tmp1] <= lv[tmp2]) ? tmp1 : tmp2);
      }
    }
  }
  return 0;
}