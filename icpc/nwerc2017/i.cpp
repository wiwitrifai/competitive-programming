#include <bits/stdc++.h>

using namespace std;

const int N = 505, C = 1e4 + 4, inf = 1e9+7;

int dp[N][C];
int s[N], d[N];
int ord[N], n;

int solve(int id, int c) {
  if (id >= n)
    return dp[id][c] = 0;
  if (dp[id][c] != -1)
    return dp[id][c];
  int x = ord[id];
  int & ret = dp[id][c];
  ret = 0;
  if (c >= d[x])
    ret = 1 + solve(id+1, c-s[x]);
  return ret = max(ret, solve(id+1, c));
}

vector<int> ans;
void dfs(int id, int c) {
  if (id >= n)
    return;
  int x = ord[id];
  if (c >= d[x] && dp[id+1][c-s[x]]+1 == dp[id][c]) {
    ans.push_back(x+1);
    dfs(id+1, c-s[x]);
    return;
  }
  assert(id+1 == n || dp[id][c] == dp[id+1][c]);
  dfs(id+1, c);
}

int main() {
  memset(dp, -1, sizeof dp);
  int c;
  scanf("%d %d", &n, &c);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", d+i, s+i);
    d[i] = max(d[i], s[i]);
    ord[i] = i;
  }
  sort(ord, ord+n, [](int l, int r) { return d[l]-s[l] > d[r]-s[r]; });
  printf("%d\n", solve(0, c));
  dfs(0, c);
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d%c", ans[i], i+1 == ans.size() ? '\n' : ' ');
  }
  return 0;
}