#include <bits/stdc++.h>

using namespace std;

const int N = 3030;

vector< int > adj[N];
int a[N];

bool dfs(int v) {
  for (int u : adj[v]) {
    if (a[u] >= a[v])
      continue;
    if (!dfs(u))
      return true;
  }
  return false;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i); 
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector< int > ans;
  for (int i = 0; i < n; i++)
    if (dfs(i))
      ans.push_back(i+1);
  for (int j = 0; j < ans.size(); j++)
    printf("%d ", ans[j]);
  printf("\n");
  return 0;
}