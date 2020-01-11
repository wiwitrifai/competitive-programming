#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5, mod = 998244353;

char s[N], t[N];
int cnt[N];

int main() {
  int n;
  scanf("%d %s", &n, s);
  for (int i = 0; i < n; ++i) {
    s[i] -= '0';
  }
  for (int d = 1; d <= n; ++d) {
    if (n % d) continue;
    int x = n / d;
    if ((x & 1) == 0) continue;
    long long cur = 0;
    for (int i = 0; i < d; ++i) {
      cur = (cur * 2 + s[i]) % mod;
    }
    cur = (cur + 1) % mod;
    bool ok = 1;
    for (int i = 0; i < d; ++i)
      t[i] = s[i], t[i+d] = s[i]^1;
    for (int i = 2 * d; i < n; ++i)
      t[i] = t[i-2 * d];
    for (int i = 0; i < n; ++i) {
      if (t[i] != s[i]) {
        ok = t[i] < s[i];
        break;
      }
    }
    if (!ok) {
      cur = (cur + mod - 1) % mod;
    }
    cnt[d] = cur;
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (n % i) continue;
    if (cnt[i] == 0) continue;
    ans = (ans + 1LL * cnt[i] * (2 * i)) % mod;
    for (int j = i+i; j <= n; j += i) {
      cnt[j] = (cnt[j] + mod - cnt[i]) % mod;
    }
  }
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
