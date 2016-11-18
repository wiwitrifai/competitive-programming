#include <bits/stdc++.h>

using namespace std;

const int N = 3030;

vector< int > adj[N];
bool ok[N];

bitset< N > bs;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int mid = n/3 - 1;
  for (int i = 0; i < n; i++) {
    ok[i] = 0;
    if (adj[i].size() < mid)
      continue;
    int cnt = 0;
    for (int u : adj[v])
      cnt += adj[u].size() >= mid;
    if (cnt < n/3-1)
      ok[i] = true;
  }
  for (int i = 0; i < n; i++) {
    
  }
  return 0;
}