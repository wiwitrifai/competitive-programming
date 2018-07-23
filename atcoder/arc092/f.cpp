#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

vector<int> g[N];
int vis[N], que[N];

bool can(int s, int t) {
  int cnt = 0, cur = 0;
  que[cnt++] = s;
  vis[s] = 1;
  cerr << s << " " << t << endl;
  while (cur < cnt && !vis[t]) {
    int v = que[cur++];
    cerr << v << " " << cur << " " << cnt << endl;
    for (int u : g[v]) if (!vis[u]) {
      vis[u] = 1;
      cerr << v << " to " << u << endl;
      que[cnt++] = u;
    }
  }
  int ans = vis[t];
  for (int i = 0; i < cnt; ++i)
    vis[que[i]] = 0;
  cerr << ans << endl;
  return ans;
}

const int M = 2e5 + 5;

int a[M], b[M], dir[M][2];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i)
    scanf("%d %d", a+i, b+i), --a[i], --b[i];
  for (int i = m-1; i >= 0; --i) {
    dir[i][0] = can(a[i], b[i]);
    dir[i][1] = can(b[i], a[i]);
    if (!dir[i][0])
      g[a[i]].push_back(b[i]);
  }
  for (int i = 0; i < n; ++i) g[i].clear();
  for (int i = 0; i < m; ++i) {
    int arah = can(a[i], b[i]);
    int rev = can(b[i], a[i]);
    if (!arah)
      g[a[i]].push_back(b[i]);
    arah |= dir[i][0];
    rev |= dir[i][1];
    cerr << arah << " " << rev << endl;
    puts((arah != rev) ? "diff" : "same");
  }
  return 0;
}