#include <bits/stdc++.h>

using namespace std;

const int N = 202;

vector<pair<int, int> > g[N];

int dp[N][N][26];

int solve(int a, int b, int c) {
  int & ret = dp[a][b][c];
  if (ret != -1)
    return ret;
  ret = 0;
  for (auto it : g[a]) if (it.second >= c) {
    if (!solve(b, it.first, it.second)) {
      ret = 1;
      break;
    }
  }
  return ret;
}

int main() {
  memset(dp, -1, sizeof dp);
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    char c;
    scanf("%d %d %c", &u, &v, &c);
    --u, --v;
    c -= 'a';
    g[u].emplace_back(v, c);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%c", solve(i, j, 0) ? 'A' : 'B');
    }
    printf("\n");
  }

  return 0;
}