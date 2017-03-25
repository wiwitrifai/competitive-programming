#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector< int > g[N];
int r, c, x[404][404], cnt[N];
set< pair< int, int > > st;

int com[N], ncom, num[N], low[N], vis[N], cntr;
long long dp[N];
vector< int > S;

void tarjanSCC(int v) {
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  for(auto u : g[v]) {
    if(num[u] == -1)
      tarjanSCC(u);
    if(vis[u])
      low[v] = min(low[v], low[u]);
  }
  if(low[v] == num[v]) {
    dp[ncom] = 0;
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      com[u] = ncom;
      dp[ncom] += 1LL * cnt[u] * u;
      if(u == v)
        break;
    }
    ncom++;
  }
}
vector< int > adj[N];
int to[N];

int main() {
  scanf("%d %d", &r, &c);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      scanf("%d", x[i]+j);
      cnt[x[i][j]]++;
      if (j == 0) continue;
      int k = j-1;
      pair< int, int > now = {x[i][k], x[i][j]};
      if (!st.count(now)) {
        st.insert(now);
        g[x[i][k]].push_back(x[i][j]);
      }
    }
  }
  cntr = 0;
  memset(vis, 0, sizeof vis);
  memset(num, -1, sizeof num);
  for (int i = 0; i < N; i++) if (num[i] == -1) {
    S.clear();
    tarjanSCC(i);
  }
  for (int i = 0; i < N; i++) {
    for (int v : g[i]) if (com[v] != com[i]) {
      adj[com[i]].push_back(com[v]);
      to[com[v]]++;
    }
  }
  vector< int > vs;
  stack< int > stak;
  for (int i = 0; i < ncom; i++) {
    if (to[i] == 0)
      stak.push(i);
  }
  while (!stak.empty()) {
    int now = stak.top(); stak.pop();
    vs.push_back(now);
    for (int v : adj[now]) {
      to[v]--;
      if (to[v] == 0)
        stak.push(v);
    }
  }
  for (int i = (int)vs.size()-1; i >= 0; i--) {
    int now = vs[i];
    long long cur = dp[now];
    for (int v : adj[now]) {
      dp[now] = max(dp[now], cur + dp[v]);
    }
  }
  long long ans = 0;
  for (int i = 0; i < r; i++) {
    ans = max(ans, dp[com[x[i][0]]]);
  }
  cout << ans << endl;
  return 0;
}