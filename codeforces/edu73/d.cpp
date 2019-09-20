#include <bits/stdc++.h>

using namespace std;

const int K = 8;

pair<long long, long long> x[K], nx[K];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < K; ++i)
      x[i] = {0, -1};
    for (int i = 0; i < n; ++i) {
      int a, b;
      scanf("%d %d", &a, &b);
      sort(x, x+K);
      for (int j = 0; j < K; ++j)
        nx[j] = {((a + j == x[0].second) ? x[1].first : x[0].first) + 1LL * j * b, a + j};
      for (int j = 0; j < K; ++j)
        x[j] = nx[j];
    }
    long long ans = x[0].first;
    for (int i = 1; i < K; ++i)
      ans = min(ans, x[i].first);
    printf("%lld\n", ans);
  }
  return 0;
}
