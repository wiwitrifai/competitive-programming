#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353, N = 303;

long long dp[N][N][N];
long long tmp[N][N], tmp2[N][N];

void add(long long & var, long long val) {
  var += val;
  if (var >= mod)
    var -= mod;
}

char s[N];

int main() {
  int k;
  scanf("%s %d", s, &k);
  int n = strlen(s);
  int cnt = 0;
  vector<int> ones;
  int tot = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      ones.push_back(cnt);
      cnt = 0;
    } else {
      ++tot;
      ++cnt;
    }
  }
  ones.push_back(cnt);
  reverse(ones.begin(), ones.end());
  dp[0][0][0] = 1;
  k = min(k, tot);
  for (int i = 0; i < (int)ones.size(); ++i) {
    int cur = ones[i];
    for (int j = 0; j <= k; ++j) {
      for (int z = j; z <= k; ++z) {
        add(dp[i+1][j][z], dp[i][j][z]);

        if (j-cur > 0)
          add(tmp[i][z-j], mod - dp[i][j-cur-1][z-cur-1]);
        add(dp[i+1][j][z], tmp[i][z-j]);

        add(tmp[i][z-j], dp[i][j][z]);
      }
    }
    for (int j = k; j >= 0; --j) {
      for (int z = j; z <= k; ++z) {
        add(dp[i+1][j][z], tmp2[i][z]);

        add(tmp2[i][z], dp[i][j][z]);
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i <= k; ++i) {
    add(ans, dp[(int)ones.size()][0][i]);
  }
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
