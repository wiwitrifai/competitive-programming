#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long get(long long a, long long n) {
  a %= mod;
  n %= mod;
  return (a + (n-1)) * n % mod;
}

long long calc(long long x) {
  if (x <= 0)
    return 0;
  if (x == 1)
    return 1;
  long long ans = 0;
  int i = 0;
  long long ganjil = 0, genap = 0;
  while ((1LL << (i+1)) <= x) {
    if (i & 1) {
      ans += get((genap + 1) * 2, 1LL << i);
      genap += 1LL << i;
    }
    else {
      ans += get(ganjil * 2 + 1, 1LL << i);
      ganjil += 1LL << i;
    }
    ++i;
  }
  if (i & 1) {
    ans += get(genap * 2 + 2, x - (1LL << i) + 1);
  }
  else {
    ans += get(ganjil * 2 + 1, x - (1LL << i) + 1);
  }
  ans %= mod;
  if (ans < 0)
    ans += mod;
  return ans;
}

int main() {
  long long l, r;
  cin >> l >> r;
  long long ans = calc(r) - calc(l-1);
  ans %= mod;
  if (ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}
