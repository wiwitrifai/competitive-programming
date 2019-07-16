#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long powmod(long long b, long long p, long long m) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % m)
    if (p & 1)
      r = r * b % m;
  return r;
}
long long invmod(int b, int m) {
  return powmod(b, m-2, m);
}
int a[N];
map<int, int> mp;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k, m;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; ++i)
      scanf("%d", a+i);
    if (k == 0) {
      long long ans = 1LL * n * (n+1) / 2;
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
        if (a[i] % m)
          ++cnt;
        else
          cnt = 0;
        ans -= cnt;
      }
      printf("%lld\n", ans);
    }
    else {
      long long ans = 0;
      mp.clear();
      mp[1] = 1;
      k = invmod(k, m);
      long long cur = 1;
      for (int i = 0; i < n; ++i) {
        int z = a[i] % m;
        if (z) {
          cur = 1L * z * cur % m;
          long long now = 1LL * cur * k % m;
          auto it = mp.find(now);
          if (it != mp.end())
            ans += it->second;
          ++mp[cur];
        }
        else {
          mp.clear();
          mp[1] = 1;
          cur = 1;
        }
      }
      printf("%lld\n", ans);
    }
  }
  return 0;
}