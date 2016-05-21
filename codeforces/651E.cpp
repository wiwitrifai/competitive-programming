#include <bits/stdc++.h>

using namespace std;

#define val first
#define x second.first
#define y second.second

const int N = 1e6 + 6;

int n, m, r[N], c[N], comp[N];
pair<int, pair<int, int> > cel[N];
bool visit[N];
vector<int> adj[N];

int getVal(int v) {
  visit[v] = true;
  int ret = max(c[cel[v].y], r[cel[v].x]) + 1;
  for(auto u : adj[v]) if(!visit[u])
    ret = max(ret, getVal(u));
  return ret;
}
int setVal(int v, int val) {
  comp[v] = val;
  c[cel[v].y] = val;
  r[cel[v].x] = val;
  for(auto u : adj[v]) if(comp[u] != val)
    setVal(u, val);
}

int main() {
  scanf("%d%d", &n, &m);
  int nm = 0;
  for(int i = 0; i<n; i++) {
    for(int j = 0; j<m; j++) {
      int xx;
      scanf("%d", &xx);
      cel[nm++] = {xx, {i, j}};
    }
  }
  sort(cel, cel+nm);
  for(int i = 0; i<n; i++) r[i] = -1;
  for(int j = 0; j<m; j++) c[j] = -1;
  for(int i = 0; i<nm; i++) {
    int nr = cel[i].x, nc = cel[i].y;
    if(r[nr] != -1 && cel[r[nr]].val == cel[i].val) {
      adj[i].push_back(r[nr]);
      adj[r[nr]].push_back(i);
    }
    if(c[nc] != -1 && cel[c[nc]].val == cel[i].val) {
      adj[i].push_back(c[nc]);
      adj[c[nc]].push_back(i);
    }
    r[nr] = i;
    c[nc] = i;
  }
  int cnt = 0;
  memset(r, 0, sizeof r);
  memset(c, 0, sizeof c);
  for(int i = 0; i<nm; i++) if(comp[i] == 0) {
    int val = getVal(i);
    setVal(i, val);
  }
  vector< vector<int> > ans;
  ans.assign(n, vector<int>(m));
  for(int i = 0; i<nm; i++) {
    ans[cel[i].x][cel[i].y] = comp[i];
  }
  for(int i = 0; i<n; i++) {
    for(int j = 0; j<m; j++)
      printf("%d ", ans[i][j]);
    printf("\n");
  }
  return 0;
}