#include <bits/stdc++.h>

using namespace std;

const int N = 1024, mod = 1e9 + 7;

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

int a[N][N];
int dp[2][N][18];
int mul[20][20];

vector<pair<long long, int>> fprimes = {{107,2}, {1361, 2}, {10000019, 1}};
const long long X = 212072634227239451LL;

int main() {
  map<long long, int> mp;
  vector<long long> factors;
  long long val = 1;
  for (int i = 0; i <= fprimes[0].second; ++i) {
    long long vali = val;
    for (int j = 0; j <= fprimes[1].second; ++j) {
      long long valj = vali;
      for (int k = 0; k <= fprimes[2].second; ++k) {
        factors.emplace_back(valj);
        valj *= fprimes[2].first;;
      }
      vali *= fprimes[1].first;;
    }
    val *= fprimes[0].first;;
  }
  sort(factors.begin(), factors.end());
  for (int i = 0; i < (int)factors.size(); ++i) {
    mp[factors[i]] = i;
  }
  for (int i = 0; i < (int)factors.size(); ++i) {
    for (int j = 0; j < (int)factors.size(); ++j) {
      long long ans = 1;
      for (auto it : fprimes) {
        int cnt = 0;
        long long v = factors[i];
        while ((v % it.first) == 0) {
          ++cnt;
          v /= it.first;
        }
        v = factors[j];
        while ((v % it.first) == 0) {
          ++cnt;
          v /= it.first;
        }
        cnt = min(cnt, it.second);
        for (int k = 0; k < cnt; ++k)
          ans *= it.first;
      }
      mul[i][j] = mp[ans];
    }
  }
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      long long v;
      scanf("%lld", &v);
      a[i][j] = mp[gcd(X, v)];
    }
  }
  memset(dp, 0, sizeof dp);
  dp[0][0][a[0][0]] = 1;
  int c = 0, b = 1;
  for (int j = 1; j < m; ++j) {
    for (int k = 0; k < (int)factors.size(); ++k) {
      int & now = dp[0][j][mul[a[0][j]][k]];
      now += dp[0][j-1][k];
      if (now >= mod)
        now -= mod;
    }
  }
  for (int i = 1; i < n; ++i) {
    swap(c, b);
    memset(dp[c], 0, sizeof dp[c]);
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < (int)factors.size(); ++k) {
        int & now = dp[c][j][mul[a[i][j]][k]];
        now += dp[b][j][k];
        if (now >= mod)
          now -= mod;
        if (j) {
          now += dp[c][j-1][k];
          if (now >= mod)
            now -= mod;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i+1 < (int)factors.size(); ++i) {
    ans += dp[c][m-1][i];
    if (ans >= mod)
      ans -= mod;
  }
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("%d\n", ans);

  return 0;
}
