#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  long long x;
  scanf("%d %lld", &n, &x);
  vector<int> d(n+n);
  vector<long long> cnt(n+n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &d[i]);
    d[i+n] = d[i];
  }
  vector<long long> sum(n+n+1);
  sum[0] = 0;
  for (int i = 0; i < (int)d.size(); ++i) {
    cnt[i] = 1LL * d[i] * (d[i] + 1) / 2;
    sum[i+1] = sum[i] + cnt[i];
  }
  long long cur = 0, ans = 0, cost = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    if (j < i) {
      cur = 0;
      cost = 0;
      j = i;
    }
    while (cur + d[j] <= x) {
      cost += cnt[j];
      cur += d[j];
      ++j;
    }
    long long sisa = x - cur;
    ans = max(ans, cost + sisa * (sisa + 1) / 2);
    if (i < j) {
      cost -= cnt[i];
      cur -= d[i];
    }
  }
  cur = cost = 0;
  for (int i = n+n-1, j = i; i >= n; --i) {
    if (j >= i) {
      cur = cost = 0;
      j = i;
    }
    while (cur + d[j] <= x) {
      cost += cnt[j];
      cur += d[j];
      --j;
    }
    long long sisa = x - cur;
    ans = max(ans, cost + sisa * (d[j] + d[j] - sisa + 1) / 2);
    if (i > j) {
      cost -= cnt[i];
      cur -= d[i];
    }
  }
  printf("%lld\n", ans);
  return 0;
}
