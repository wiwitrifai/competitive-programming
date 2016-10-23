/**
  IEEExtreme Programming Contest 10
  Problem : Inti Sets
  Solver  : Wiwit Rifa'i
*/

#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;
const int N = 1e6 + 7;

map< pair<long long, int >, long long > mp;
long long p[N];

long long solve(long long m, int n) {
  if (m == 0)
    return 0;
  if (n <= 0) {
    long long ans = ((m % mod) * ((m+1) % mod)) % mod;
    ans %= mod;
    ans *= (mod+1)/2;
    ans %= mod;
    return ans;
  }
  if (mp.count({m, n}))
    return mp[{m, n}];
  long long res = (solve(m, n-1) - ((solve(m/p[n], n-1) * (p[n] % mod)) % mod)) % mod;
  res %= mod;
  if (res < 0)
    res += mod;
  mp[{m, n}] = res;
  return res;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long a, b, n;
    scanf("%lld %lld %lld", &n, &a, &b);
    assert(a <= b);
    int m = 0;
    for (long long i = 2; i <= N; i++) if ((n % i) == 0) {
      p[++m] = i;
      while ((n % i) == 0)
        n /= i;
    }
    if (n > 1)
      p[++m] = n;
    mp.clear();
    assert(m < N);
    long long ans = solve(b, m);
    mp.clear();
    if (a > 1)
      ans -= solve(a-1, m);
    ans %= mod;
    if (ans < 0)
      ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}