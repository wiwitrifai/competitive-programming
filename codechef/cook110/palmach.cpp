#include <bits/stdc++.h>

using namespace std;

const int N = 1024, mod = 1e9 + 7;

char buffer[N];
long long dp[N], tmp[N];

long long powmod(long long b, long long p) {
  long long r= 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

long long fac[N], inv[N], pilih[N];

long long C(int n, int k) {
  if (n < k || k < 0 || n < 0)
    return 0;
  return (fac[n] * inv[k] % mod) * inv[n-k] % mod;
}


void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<pair<string, int>> vs;
  for (int i = 0; i < n; ++i) {
    scanf("%s", buffer);
    string s = buffer;
    string r = s;
    reverse(r.begin(), r.end());
    if (s < r) {
      vs.emplace_back(s, 0);
    }
    else if (s > r) {
      vs.emplace_back(r, 1);
    }
    else {
      vs.emplace_back(s, 2);
    }
  }
  sort(vs.begin(), vs.end());
  vector<tuple<int, int, int>> cnts;
  string last = vs[0].first;
  tuple<int, int, int> cnt = make_tuple(0, 0, 0);
  for (auto it : vs) {
    if (last != it.first) {
      cnts.push_back(cnt);
      cnt = make_tuple(0, 0, 0);
      last = it.first;
    }
    if (it.second == 0)
      get<0>(cnt)++;
    if (it.second == 1)
      get<1>(cnt)++;
    if (it.second == 2)
      get<2>(cnt)++;
  }
  cnts.push_back(cnt);
  fill(dp, dp+m+1, 0);
  dp[0] = 1;
  for (auto it : cnts) {
    int a, b, c;
    tie(a, b, c) = it;
    for (int i = 0; i <= m; ++i)
      tmp[i] = dp[i];
    if (c == 0) {
      int maxi = min(a, b);
      for (int i = 1; i <= maxi; ++i) {
        int cur = 1LL * C(a, i) * C(b, i) % mod;
        cur = 1LL * cur * fac[i] % mod;
        int rem = i * 2;
        for (int j = m; j >= rem; --j) {
          dp[j] = (dp[j] + 1LL * cur * tmp[j-rem]) % mod;
        }
      }
    }
    else {
      for (int i = 2; i <= c; i += 2) {
        int cur = C(c, i) * pilih[i] % mod;
        for (int j = m; j >= i; --j) {
          dp[j] = (dp[j] + 1LL * cur * tmp[j-i]) % mod;
        }
      }
      for (int i = 1; i <= c; i += 2) {
        int cur = C(c, i) * pilih[i] % mod;
        for (int j = m; j >= i; --j) {
          if ((j & 1) == 0) continue;
          dp[j] = (dp[j] + 1LL * cur * tmp[j-i]) % mod;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= m; ++i) {
    int cur = 1LL * powmod(2, i / 2) * fac[i / 2] % mod;

    ans = (ans + 1LL * dp[i] * cur) % mod;
  }
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("%d\n", ans);
}

int main() {
  pilih[0] = 1;
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = 1LL * fac[i-1] * i % mod;
    inv[i] = powmod(fac[i], mod-2);
    pilih[i] = (i & 1) ? 1LL * i * pilih[i-1] % mod : pilih[i-1];
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
