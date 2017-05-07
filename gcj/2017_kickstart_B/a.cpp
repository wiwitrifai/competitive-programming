#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6, mod = 1e9 + 7;
long long a[N];
int n;
long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>=1, b = b * b % mod)
    if (p & 1) r = r * b % mod;
  return r;
}

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    scanf("%d", &n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      scanf("%lld", a+i);
      ans = (ans + (powmod(2, i) - powmod(2, n-1-i)) * a[i]) % mod;
    }
    ans %= mod;
    if (ans < 0) ans += mod;
    printf("Case #%d: %lld\n", tc, ans);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}