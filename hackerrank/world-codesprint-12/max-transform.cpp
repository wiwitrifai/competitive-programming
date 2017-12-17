#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, LG = 19, mod = 1e9 + 7;
long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

const long long inv2 = (mod + 1) >> 1, inv6 = powmod(6LL, mod-2);
long long sum1(long long n) {
  long long r = 1LL * n * (n + 1) % mod;
  r = (r * inv2) % mod;
  return r;
}

long long sum2(long long n) {
  long long r = n * (n + 1) % mod;
  r = (r * (2 * n + 1)) % mod;
  r = (r * inv6) % mod;
  return r;
}

long long mul(long long a, long long b) {
  return a * b % mod;
}

int n, ar[N];
int sp[LG][N];
int get(int l, int r) {
  if (l > r) swap(l, r);
  int len = r-l+1;
  int lg = 31 - __builtin_clz(len);
  return max(sp[lg][l], sp[lg][r-(1 << lg)+1]);
}

int left(int l, int r, int ma) {
  int le = l, ri = r+1;
  while (le < ri) {
    int mid = (le + ri) >> 1;
    int val = get(mid, r);
    if (val < ma)
      ri = mid;
    else
      le = mid + 1;
  }
  return ri;
}

int right(int l, int r, int ma) {
  int le = l-1, ri = r;
  while (le < ri) {
    int mid = (le + ri + 1) >> 1;
    int val = get(l, mid);
    if (val <= ma)
      le = mid;
    else
      ri = mid - 1;
  }
  return le;
}


int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", ar+i);
  for (int i = 0; i < n; ++i)
    sp[0][i] = ar[i];
  for (int i = 0; i + 1 < LG; ++i) {
    for (int j = 0; j + (1 << (i+1)) <= n; ++j)
      sp[i+1][j] = max(sp[i][j], sp[i][j+(1<<i)]);
  }
  int ma = get(0, n-1);
  long long ans = 0;
  long long tot = sum1(n);
  tot = sum1(tot);
  tot %= mod;
  if (tot < 0) tot += mod;
  for (int i = 0; i < n; ++i) {
    if (ar[i] == ma) continue;
    int le = left(0, i-1, ar[i]), ri = right(i+1, n-1, ar[i]);
    long long a = i - le + 1, b = ri - i + 1;
    long long cnt = (sum1(a) * b + sum1(b-1) * a) % mod;
    tot -= cnt;
    tot %= mod;
    if (tot < 0) tot += mod;
    ans = (ans + cnt * ar[i]) % mod;
  }
  for (int i = 0; i < n; ++i) {
    if (ar[i] == ma) continue;
    int cur = get(i, n-1);
    if (cur > ar[i]) continue;
    int le = left(0, i-1, ar[i]);
    int ri = right(0, n-1, ar[i]);
    if (ri <= 0) continue;
    long long a = i-le, b = n-i, c = ri;
    long long sum = 0;
    int til = min(b, c);
    sum += mul(a+1, mul(c+1, til)) - mul(a+1, sum1(til));
    sum %= mod;
    a += b;
    long long til2 = min(a, c);
    if (til < til2) {
      int cnt = til2 - til;
      sum += mul(a+1, mul(c+1, cnt)) - mul(a+1+c+1, sum1(til2) - sum1(til)) + sum2(til2) - sum2(til);
      sum %= mod;
    }
    tot = (tot - sum) % mod;
    ans = (ans + sum * ar[i]) % mod;
  }

  for (int i = 0; i < n; ++i) {
    if (ar[i] == ma) continue;
    int cur = i == 0 ? ar[i]-1 : get(0, i-1);
    if (cur >= ar[i]) continue;
    int le = left(0, n-1, ar[i]), ri = right(i+1, n-1, ar[i]);
    if (le >= n) continue;
    long long a = ri-i, b = i, c = n-le;
    long long sum = 0;
    long long til = min(b, c);
    sum += mul(a+1, mul(c+1, til)) - mul(a+1, sum1(til));
    sum %= mod;
    a += b;
    long long til2 = min(a, c);
    if (til < til2) {
      int cnt = til2 - til;
      sum += mul(a+1, mul(c+1, cnt)) - mul(a+1+c+1, sum1(til2) - sum1(til)) + sum2(til2) - sum2(til);
      sum %= mod; 
    }
    tot = (tot - sum) % mod;
    ans = (ans + sum * ar[i]) % mod;
  }
  ans %= mod;
  ans = (ans + tot * ma) % mod;
  ans %= mod;
  if (ans < 0) ans += mod;
  printf("%lld\n", ans);
  return 0;
}