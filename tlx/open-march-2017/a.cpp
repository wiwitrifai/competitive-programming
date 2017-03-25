#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, N = 2e5 + 8, inv2 = (mod+1)/2;

map< long long, long long > mp;

long long solve(long long n) {
  if (mp.count(n))
    return mp[n];
  long long ret = 0;
  bool prime = 1;
  for (long long i = 2; 1LL * i * i <= n; i++) if ((n % i) == 0) { 
    prime = 0;
    long long r = n/i;
    if (r != i)
      ret = (ret + solve(i) * solve(r)) % mod; 
    else {
      long long cur = solve(i);
      cur = (cur *(cur+1)) % mod;
      cur = (cur * inv2) % mod;
      ret = (ret + cur) % mod;
    }
  }
  if (prime)
    ret = 1;
  ret %= mod;
  if (ret < 0) ret += mod;
  mp[n] = ret;
  return ret;
}

int main() {
  long long n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}