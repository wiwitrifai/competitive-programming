#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 7;

int pr[N], mob[N];

int main() {
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  int n = min(b, d);
  for (int i = 2; i <= n; ++i) {
    if (pr[i]) continue;
    for (int j = i; j <= n; j += i)
      if (pr[j] == 0)
        pr[j] = i;
  }
  mob[1] = 1;
  for (int i = 2; i <= n; ++i) {
    int p = pr[i];
    int x = i/p;
    if (x % p == 0) {
      mob[i] = 0;
      continue;
    }
    mob[i] = -mob[x];
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (mob[i] == 0)
      continue;
    long long cnt = 1LL * (b/i - (a-1)/i) * (d/i - (c-1)/i);
    ans += cnt * mob[i];
  }
  printf("%lld\n", ans);
  return 0;
}
