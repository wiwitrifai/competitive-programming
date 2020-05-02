#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

const int N = 2e6 + 6;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

long long fac[N], inv[N];

long long C(int n, int k) {
  if (n < 0 || k < 0 || n < k) return 0;
  return (fac[n] * inv[k] % mod) * inv[n-k] % mod;
}

long long calc(int n, int m, vector<pair<int, int>> obstacles) {
  sort(obstacles.begin(), obstacles.end());
  obstacles.erase(unique(obstacles.begin(), obstacles.end()), obstacles.end());
  int k = obstacles.size();
  vector<long long> pre(k, 0);
  long long ans = C(n+m-2, n-1);
  for (int i = 0; i < k; ++i) {
    int r = obstacles[i].first, c = obstacles[i].second;
    pre[i] = C(r+c-2, r-1);
    for (int j = 0; j < i; ++j) {
      int dr = r - obstacles[j].first;
      int dc = c - obstacles[j].second;
      if (dr < 0 || dc < 0) continue;
      pre[i] = (pre[i] - C(dr+dc, dr) * pre[j]) % mod;
      if (pre[i] < 0)
        pre[i] += mod;
    }
    ans = (ans - C(n-r+m-c, n-r) * pre[i]) % mod;
    if (ans < 0)
      ans += mod;
  }
  return ans;
}

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = fac[i-1] * i % mod;
    inv[i] = powmod(fac[i], mod-2);
  }
  int n, m, k, w;
  scanf("%d %d %d %d", &n, &m, &k, &w);
  vector<pair<int, int>> obstacles[3];
  vector<int> primes = {100000007, 1000000007};
  for (int i = 0; i < k; ++i) {
    int x, y;
    long long v;
    scanf("%d %d %lld", &x, &y, &v);
    bool exist = false;
    for (int j = 0; j < 2; ++j) {
      if (v % primes[j]) continue;
      obstacles[j].emplace_back(x, y);
      exist = true;
    }
    if (exist)
      obstacles[2].emplace_back(x, y);
  }
  long long ans = calc(n, m, obstacles[0]) + calc(n, m, obstacles[1]) - calc(n, m, obstacles[2]);
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
