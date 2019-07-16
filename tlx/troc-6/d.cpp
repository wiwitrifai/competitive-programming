#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

int a[N];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  long long ans = 0, cur = 1;
  for (int l = 0; l < 30; ++l) {
    long long cnt = 0;
    for (int i = 0; i < n; ++i) {
      cnt += (a[i] >> l) & 1; 
    }
    long long tot = n;
    for (int j = 0; j < q; ++j) {
      cnt = 2LL * (tot - cnt) * cnt % mod;
      tot = 1LL * tot * tot % mod;
    }
    ans = (ans + cnt * cur) % mod;
    cur = (cur + cur) % mod;
  }
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
