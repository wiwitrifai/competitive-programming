#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, N = 1e6 + 6;
char s[N];
long long fac[N], inv[N];
long long C(int n, int k) {
  if (k < 0 || k > n) return 0;
  return ((fac[n] * inv[k] % mod) * inv[n-k]) % mod;
}
long long powmod(long long a, long long p) {
  long long ret = 1;
  for (; p; p >>= 1, a = a * a % mod)
    if (p & 1) ret = ret * a % mod;
  return ret;
}

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; i++)
    fac[i] = fac[i-1] * i % mod, inv[i] = powmod(fac[i], mod-2);
  scanf("%s", s);
  int r = 0, l = 0, n = strlen(s);
  long long ans = 0;
  for (int i = 0; i < n; i++)
    r += s[i] == ')';
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      l++;
      ans += C(l+r-1, r-1);
      if (ans >= mod) ans -= mod;
    }
    else
      r--;
  }
  cout << ans << endl;
  return 0;
}