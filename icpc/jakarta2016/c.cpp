#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 4;

long long b[N], k[N];
vector<int> g[N];
int n, m, d[N];
vector<int> topo;
long long dp[N];

long long get(long long x) {
  fill(dp, dp+n, 0);
  long long ans = 0;
  for (int v : topo) {
    dp[v] += k[v] * x + b[v];
    for (int u : g[v])
      dp[u] = max(dp[u], dp[v]);
    ans = max(ans, dp[v]);
  }
  return ans;
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%lld %lld", b+i, k+i);
      g[i].clear();
      g[i].clear();
      d[i] = 0;
    }
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      u--; v--;
      g[u].push_back(v);
      d[v]++;
    }
    stack<int> st;
    for (int i = 0; i < n; i++) if (d[i] == 0)
      st.push(i);
    topo.clear();
    while (!st.empty()) {
      int v = st.top(); st.pop();
      topo.push_back(v);
      for (int u : g[v]) {
        d[u]--;
        if (d[u] == 0)
          st.push(u);
      }
    }
    assert(topo.size() == n);
    long long le = -1e9, ri = -le;
    for (int i = 0; i < n; i++) {
      if (k[i] == 0) continue;
      if (k[i] > 0) {
        le = max(le, - ((b[i]+k[i]-1)/k[i]) + 1);
        ri = min(ri, (50000-b[i])/k[i]);
      }
      else {
        le = max(le, - ((50000-b[i])/abs(k[i])));
        ri = min(ri, (b[i] + abs(k[i]) - 1)/abs(k[i]) -1);
      }
    }
    long long ans = get(0);
    while (ri-le > 2) {
      long long ml = (le + le + ri)/3, mr = (le + ri + ri) / 3;
      long long vl = get(ml), vr = get(mr);
      ans = min(ans, min(vl, vr));
      if (vl >= vr)
        le = ml;
      else
        ri = mr;
    }
    for (long long i = le; i <= ri; i++) {
      ans = min(ans, get(i));
    }
    printf("Case #%d: %lld\n", tc, ans);
  }
  return 0;
}