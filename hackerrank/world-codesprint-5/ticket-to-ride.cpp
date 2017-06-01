#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<pair< int, int > > adj[N];
vector< int > ep[N];
int n, m, a[N], b[N], c[N];
bool used[N];

long long dfs(int u, int par = -1) {
  long long ret = 0, add = 0;
  for(int i : ep[u]) {
    if(used[i])
      add += c[i];
    else
      used[i] = true;
  }
  for(auto p : adj[u]) if(p.first != par) {
    ret = max(ret, dfs(p.first, u)-p.second);
  }
  for(int i : ep[u]) {
    used[i] = false;
  }
  return ret + add;
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i<n; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    u--; v--;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }
  scanf("%d", &m);
  vector< int > all;
  for (int i = 0; i<m; i++) {
    scanf("%d%d%d", a+i, b+i, c+i);
    a[i]--; b[i]--;
    ep[a[i]].push_back(i);
    ep[b[i]].push_back(i);
    all.push_back(a[i]);
    all.push_back(b[i]);
  }
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
  long long ans = 0;
  for (int i : all) {
    ans = max(ans, dfs(i, i));
  }
  printf("%lld\n", ans);
  return 0;
}