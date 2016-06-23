#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long ret = 1;
  while(p) {
    if(p & 1)
      ret = (ret * b) % mod;
    b = (b * b) % mod;
    p >>= 1;
  }
  return ret;
}

int main() {
  long long n, a, b, x;
  cin >> a >> b >> n >> x;
  long long ax = powmod(a, n);
  long long aa = (a == 1 ? n : (ax - 1) * powmod(a-1, mod-2)) % mod;
  long long ans = (ax * x + aa * b) % mod;
  if(ans < 0)
    ans += mod;
  cout << ans << endl;
  return 0;
}