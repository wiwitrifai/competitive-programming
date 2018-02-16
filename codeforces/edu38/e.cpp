#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = b * r % mod;
  return r;
}
long long fac[N], inv[N];
int a[N];
long long C(int n, int k) {
  if (n < k || k < 0) return 0;
  return (fac[n] * inv[k] % mod) * inv[n-k] % mod;
}

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = fac[i-1] * i % mod;
    inv[i] = powmod(fac[i], mod-2);
  }
  int n;
  scanf("%d", &n);
  map<int, int> mp;
  int ma = 0;
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i), mp[a[i]]++, ma = max(ma, a[i]);
  long long ans = 0;
  int cnt = 0;
  for (auto it : mp) {
    if (it.first == ma) continue;
    int sisa = n - cnt;
    long long cur = fac[sisa-1] * fac[cnt] % mod;
    cur = cur * it.second % mod;
    cur = cur * C(n, sisa) % mod;
    ans = (ans + cur * it.first) % mod;
    if (ans < 0) ans += mod;
    cnt += it.second;
  } 
  cout << ans << endl;
  return 0;
}