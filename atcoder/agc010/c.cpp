#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

vector< int > adj[N];
int a[N];
long long dfs(int v = 0, int par = -1) {
  long long sum = (adj[v].size() <= 1) ? a[v] : 0;
  long long ma = sum;
  for (int u : adj[v]) if (u != par) {
    long long cur = dfs(u, v);
    if (cur < 0)
      return -1;
    if (ma < cur)
      ma = cur;
    sum += cur;
  }
  long long up = 2LL * a[v] - sum;
  if (up < (ma - (sum - ma)) || up > sum)
    return -1;
  return up;
}


int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  puts(dfs() == 0 ? "YES" : "NO");
  return 0;
}