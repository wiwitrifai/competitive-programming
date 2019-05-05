#include <bits/stdc++.h>

using namespace std;

const int N = 2024, mod = 998244353;

char s[N];
int dp[N][2];
vector<pair<int, int> > g[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  if (n == 1) {
    puts("0");
    return 0;
  }
  if (s[n-1] == '1') {
    puts("0");
    return 0;
  }
  s[n-1] = '0';
  int tot = 0;
  for (int off = 1; off < n; ++off) {
    int m = n - off;
    for (int i = 0; i < n + m; ++i)
      g[i].clear();
    for (int i = 0; i < n; ++i) {
      if (i == n-1-i) continue;
      g[i].emplace_back(n-1-i, 0);
    }
    for (int i = 0; i < m; ++i) {
      if (i == m-1-i) continue;
      g[n + i].emplace_back(n + m-1-i, 0);
    }
    for (int i = off; i < n; ++i) {
      int w = s[i] == '?' ? -1 : (s[i] == '1' ? 1 : 0);
      g[i].emplace_back(i-off+n, w);
      g[i-off+n].emplace_back(i, w);
    }
    memset(dp, -1, sizeof dp);
    int ans = 1;
    for (int i = 0; i < off; ++i) {
      if (dp[i][0] != -1) continue;
      dp[i][0] = (s[i] != '1');
      dp[i][1] = (s[i] != '0');
      int now = i;
      while (1) {
        int nex = -1, w;
        for (auto it : g[now]) {
          if (dp[it.first][0] == -1) {
            nex = it.first;
            w = it.second;
            break;
          }
        }
        if (nex == -1)
          break;
        if (w == -1) {
          dp[nex][0] = dp[nex][1] = (dp[now][0] + dp[now][1]) % mod;
        }
        else {
          dp[nex][w] = dp[now][0];
          dp[nex][w^1] = dp[now][1];
        }
        now = nex;
      }
      if (now < off) {
        int cur = 0;
        if (s[now] != '1')
          cur = (cur + dp[now][0]) % mod;
        if (s[now] != '0')
          cur = (cur + dp[now][1]) % mod;
        ans = (1LL * ans * cur) % mod;
      }
      else {
        int cur = (dp[now][0] + dp[now][1]) % mod;
        ans = (1LL * ans * cur) % mod;
      }
    }
    tot = (tot + ans) % mod;
  }
  tot %= mod;
  if (tot < 0)
    tot += mod;
  printf("%d\n", tot);
  return 0;
}
