#include  <bits/stdc++.h>

using namespace std;

const int mod = 10007;

long long dp[2][1 << 9];

int ans[5005];

long long cnt[1<<9];

void dfs(int i, int v) {
  if (i == 9) {
    cnt[v] = (cnt[v] + 1) % mod;
  }
  else {
    // ver
    if ((i % 3) > 0 && (v & (1<<(i-1))) == 0)
      dfs(i+1, v | (3 << (i-1)));
    if ((i >= 3) && (v & (1<<(i-3))) == 0)
      dfs(i+1, v | (1<<(i-3)) | (1<<i));
    dfs(i+1, v);
  }
}
vector< int > nxt[1<<9];

int main() {
  int mask = (1<<9) - 1;
  dp[0][mask] = 1;
  for (int i = 0; i <= mask; i++) {
    for (int j = i; j <= mask; j = (j + 1) | i) {
      int x = j ^ i;
      if ((__builtin_popcount(j ^ i) & 1) == 0)
        nxt[i].push_back(j);
    }
  }
  dfs(0, 0);
  // for (int i = 0; i <= mask; i++)
    // cerr << cnt[0] << endl;
  ans[0] = 1;
  for (int i = 1; i < 5004; i++) {
    int c = i & 1, d = c ^ 1;
    memset(dp[c], 0, sizeof dp[c]);
    for (int a = 0; a <= mask; a++) {
      int x = (~a) & mask;
      for (int b : nxt[a]) {
        dp[c][b] = (dp[c][b] + 1LL * dp[d][x] * cnt[b ^ a]) % mod;
      }
    }
    ans[i] = dp[c][mask];
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", ans[n]);
  }
  

  return 0;
}
