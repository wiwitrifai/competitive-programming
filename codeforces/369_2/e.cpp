#include <bits/stdc++.h>

using namespace std;

const int mod = 1e6 + 3;

long long powmod(long long b, long long p) {
  long long ret = 1;
  while (p) {
    if (p & 1)
      ret = (ret * b) % mod;
    b = (b * b) % mod;
    p >>= 1;
  }
  return ret;
}

int main() {
  long long n, k;
  cin >> n >> k;
  long long kk = k>>1, pk = 0, add = 1;
  while (kk) {
    kk >>= 1;
    pk++;
  }
  if ((k & (k-1)))
    pk++;
  if (n < pk) {
    puts("1 1");
    return 0;
  }
  long long a = 0;
  if (k < mod) {
    a = 1;
    long long now = powmod(2, n) % mod;
    for (long long i = 0; i < k; i++) {
      a = (a * (now + mod - i)) % mod;
    }
  }
  long long b = n % (mod - 1);
  long long now = k-1;
  while (now > 0) {
    now >>= 1;
    b = (b + now) % (mod - 1);
  }
  if (b < 0)
    b += mod - 1;
  a = (a * powmod(powmod(2, mod - 2), b)) % mod;
  b = ((((n % (mod - 1)) * (k % (mod - 1))) % (mod - 1)) + mod - 1 - b) % (mod-1);
  b = powmod(2, b);
  a = (b + mod - a) % mod;
  cout << a << " " << b << endl;
  return 0;
}