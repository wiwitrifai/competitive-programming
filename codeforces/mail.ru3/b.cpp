#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int cnt[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    if (i > n) break;
    cnt[i] = (n-i) / m + 1;
  }
  if (cnt[0])
    --cnt[0];
  long long ans = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      long long res = 1LL * i * i + 1LL * j * j;
      res %= m;
      if (res == 0) {
        ans += 1LL * cnt[i] * cnt[j];
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}