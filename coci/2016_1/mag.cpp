#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, inf = 1e9+7;

vector< int > adj[N];
int x[N];

int ans1, ans2;
pair<int, int> dfs(int v = 0, int p = 0) {
  int res1[2], res2[2];
  for (int i = 0; i < 2; i++) {
    res1[i] = 0;
    res2[i] = 0;
  }
  for (int u : adj[v]) if (u != p) {
    auto res = dfs(u, v);
    if (res.first > res1[0]) {
      res1[1] = res1[0];
      res1[0] = res.first;
    }
    else if (res1[1] < res.first)
      res1[1] = res.first;
    if (res.second > res2[0]) {
      res2[1] = res2[0];
      res2[0] = res.second;
    }
    else if (res2[1] < res.second)
      res2[1] = res.second;
  }
  if (x[v] == 1) {
    ans1 = max(ans1, res1[0] + res1[1] + 1);
    ans2 = max(ans2, res2[0] + res2[1] + 1);
    return {res1[0]+1, res2[0]+1};
  }
  else if (x[v] == 2) {
    ans2 = max(ans2, res1[0] + res1[1] + 1);
    return {0, res1[0]+1};
  }
  else
    return {0, 0};
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int ans = inf;
  for (int i = 0; i < n; i++)
    scanf("%d", x+i), ans = min(ans, x[i]);
  ans1 = ans2 = 0;
  dfs(0);
  if (ans1 < inf) {
    if (ans1 * 2 >= ans2)
      printf("1/%d\n", ans1);
    else
      if (ans2 & 1)
        printf("2/%d\n", ans2);
      else
        printf("1/%d\n",ans2/2);
  }
  else
    printf("%d/1\n", ans);
  return 0;
}