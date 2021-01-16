#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> cnt(n, 0);
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    ++cnt[a];
  }
  int now = k;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int d = now - min(now, cnt[i]);
    ans += 1LL * i * d;
    now = min(now, cnt[i]);
  }
  printf("%lld\n", ans);
  return 0;
}
