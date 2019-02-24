#include <bits/stdc++.h>

using namespace std;

const int N = 3030, mod = 1e9 + 7;

long long dp[N][N];
long long ans[N];

int s[N];
int four[N];
bool can[N];
vector<int> err = {3, 5, 14, 15};
int r[N], pos[N], pt[N];
int pre[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", s+i);
  }
  for (int i = 0; i + 4 <= n; ++i) {
    four[i] = 0;
    for (int j = 0; j < 4; ++j) {
      four[i] = (four[i] << 1) | s[i+j];
    }
    can[i] = 1;
    for (int e : err)
      if (e == four[i])
        can[i] = 0;
  }
  memset(dp, 0, sizeof dp);
  for (int i = 0; i < n; ++i) {
    dp[i+1][i] = 1;
    for (int l = i; l >= 0; --l) {
      dp[l][i] = (dp[l+1][i] + dp[l+2][i] + dp[l+3][i]) % mod;
      if (can[l])
        dp[l][i] = (dp[l][i] + dp[l+4][i]) % mod;
    }
  }
  for (int i = 0; i < n; ++i)
    r[i] = i;
  sort(r, r+n, [&](int x, int y) {
    for (int i = 0; max(x, y) + i < n; ++i)
      if (s[x+i] != s[y+i])
        return s[x+i] < s[y+i];
    return x > y;
  });
  for (int i = 0; i < n; ++i)
    pos[r[i]] = i, pt[i] = i;
  for (int i = 0; i+1 < n; ++i) {
    int til = min(n - r[i], n - r[i+1]);
    while (pre[i] < til && s[r[i]+pre[i]] == s[r[i+1]+pre[i]]) ++pre[i];
  }
  for (int i = 0; i < n; ++i) {
    int cur = pos[i];
    int w = n - i;
    for (int l = cur-1; l >= 0; --l) {
      w = min(pre[l], w);
      int j = r[l];
      if (j < i) continue;
      while (pt[j] < j + w) {
        dp[j][pt[j]++] = 0;
      }
    }
    w = n - i;
    for (int rr = cur+1; rr < n; ++rr) {
      w = min(pre[rr-1], w);
      int j = r[rr];
      if (j < i) continue;
      while (pt[j] < j + w) {
        dp[j][pt[j]++] = 0;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      ans[i] = (ans[i] + dp[j][i]) % mod;
    }
    ans[i+1] = ans[i];
    printf("%lld%c", ans[i], i == n-1 ? '\n' : '\n');
  }
  return 0;
}