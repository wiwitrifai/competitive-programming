// O(N * Q)

#include <bits/stdc++.h>

using namespace std;

const int N = 1024;
vector< int > adj[N];
int c[N], par[N];

int get(int v, int val ) {
  int ret = c[v] == val;
  for (int u : adj[v]) if (u != par[v])
    ret += get(u, val);
  return ret;
}
void dfs(int v) {
  for (int u : adj[v]) if (u != par[v])
    par[u] = v, dfs(u);
} 

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", c+i);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0);
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int x, v;
    scanf("%d %d", &x, &v);
    x--;
    printf("%d\n", get(x, v));
  } 
  return 0;
}