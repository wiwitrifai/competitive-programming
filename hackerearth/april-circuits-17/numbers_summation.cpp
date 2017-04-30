#include <bits/stdc++.h>

using namespace std;

vector< pair< long long, long long > > v, r;

const int mod = 1e9 + 7;

int main() {
  long long n;
  scanf("%lld", &n);
  for (long long i = 1; i * i <= n; i++) {
    long long x = n/i % mod;
    v.emplace_back(i, x);
    if (i != x)
      r.emplace_back(x, i);
  }
  long long ans = 0, last = 0;
  long long inv2 = (mod + 1)/2;
  for (auto it : v) {
    long long now = it.first * (it.first + 1) % mod;
    now = (now * inv2) % mod;
    long long cur = (it.second + 1) * it.second % mod;
    cur = (cur * inv2) % mod;
    ans +=  cur * (now - last);
    ans %= mod;
    last = now;
  }
  reverse(r.begin(), r.end());
  for (auto it : r) {
    long long now = it.first * (it.first + 1) % mod;
    now = (now * inv2) % mod;
    long long cur = (it.second + 1) * it.second % mod;
    cur = (cur * inv2) % mod;
    ans +=  cur * (now - last);
    ans %= mod;
    last = now;
  }
  if (ans < 0) ans += mod;
  printf("%lld\n", ans);
  return 0;
}