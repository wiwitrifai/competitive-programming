#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 6;

int low[N], num[N], par[N];
int a[N], b[N], cntr;
bool vis[N];

vector< int > adj[N];

int ans = 0;
int best = 0;

// Tarjan version again
stack < int > st;
void dfs(int v) {
  low[v]= num[v] = ++cntr;
  st.push(v);
  for(auto i : adj[v]) if (!vis[i]) {
    vis[i] = 1;
    if (b[i] == v) {
      swap(a[i], b[i]);
    }
    int u = b[i];
    if(num[u] == -1) {
      par[u] = v;
      dfs(u);
      low[v] = min(low[v], low[u]);
    }
    else if(u != par[v])
      low[v] = min(low[v],num[u]);
  }
  if (num[v] == low[v]) {
    int cnt = 0;
    while (!st.empty()) {
      int u = st.top();
      st.pop();
      cnt++;
      if (u == v)
        break;
    }
    if (cnt > ans) {
      ans = cnt;
      best = v;
    }
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", a+i, b+i);
    adj[a[i]].push_back(i);
    adj[b[i]].push_back(i);
  }
  cntr = 0;
  memset(num, -1, sizeof num);
  memset(low, 0, sizeof low);
  memset(par, -1, sizeof par);
  memset(vis, 0, sizeof vis);
  ans = 0;
  dfs(1);
  cntr = 0;
  memset(num, -1, sizeof num);
  memset(low, 0, sizeof low);
  memset(par, -1, sizeof par);
  memset(vis, 0, sizeof vis);
  dfs(best);
  printf("%d\n", ans);
  for (int i = 0; i < m; i++)
    printf("%d %d\n", b[i], a[i]);
  return 0;
}