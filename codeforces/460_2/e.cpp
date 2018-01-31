#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int aa[N], ap[N];
long long powmod(long long b, long long p, long long mod) {
  long long r =1 ;
  for (; p; p >>=1, b = b * b % mod)
    if (p & 1) r = r * b % mod;
  return r;
}
long long largemul(long long a, long long b, long long mod) {
  a %= mod;
  if (a < 0) a += mod;
  b %= mod;
  if (b < 0) b += mod;
  long long r = 0;
  for (; b; b >>= 1) {
    if (b & 1) {
      r += a;
      if (r >= mod) r -= mod;
    }
    a += a;
    if (a >= mod) a -= mod;
  }
  return r;
}

int main() {
  memset(ap, -1, sizeof ap);
  long long a, b, p, x;
  cin >> a >> b >> p >> x;
  aa[0] = 1;
  ap[1] = 0;
  int s = 1;
  long long now = a;
  while (now != 1) {
    aa[s] = now;
    ap[now] = s;
    ++s;
    now = now * a % p;
  }
  long long ip = 0, is = powmod(s, p-2, p);
  for (int i = 1; i < s; ++s) {
    if (((p * i) % s) == 1) {
      ip = i;
      break;
    } 
  }
  long long ps = p * s;
  long long pp = p * ip % ps, ss = s * is % ps;
  long long ans = 0;
  for (long long q = 1; q < p; ++q) {
    long long bb = b * powmod(q, p-2, p) % p;
    if (ap[bb] == -1) continue;
    long long c = ap[bb];
    long long r = largemul(pp, c, ps) + largemul(ss, q, ps);
    r %= ps;
    if (r < 0) r += ps;
    if (x >= r) {
      ans += (x - r) / ps + 1;
      if (r == 0)
        --ans;
    }
  }
  cout << ans << endl;
  return 0;
}