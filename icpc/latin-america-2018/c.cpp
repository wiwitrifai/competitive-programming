#include <bits/stdc++.h>

using namespace std;

const int K = 1e3 + 5;

int cnt[K];

int main() {
  int k, n;
  scanf("%d %d", &k, &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    ++cnt[x];
  }
  int a = 1, b = 1;
  for (int i = 1; i <= k; ++i) {
    if (cnt[a] > cnt[i]) a = i;
    if (cnt[b] < cnt[i]) b = i;
  }
  if ((n % k) == 0) {
    bool ok = 1;
    int s = n / k;
    for (int i = 1; i <= k; ++i) {
      if (i == a || i == b) continue;
      ok &= cnt[i] == s;
    }
    ok &= cnt[a] == s-1 && cnt[b] == s+1;
    if (ok) {
      printf("-%d +%d\n", b, a);
      return 0;
    }
  }
  if ((n % k) == 1) {
    bool ok = 1;
    int s = (n-1) / k;
    for (int i = 1; i <= k; ++i) {
      if (i == b) continue;
      ok &= cnt[i] == s;
    }
    ok &= cnt[b] == s+1;
    if (ok) {
      printf("-%d\n", b);
      return 0;
    }
  }
  if ((n % k) == k-1) {
    bool ok = 1;
    int s = (n+1) / k;
    for (int i = 1; i <= k; ++i) {
      if (i == a) continue;
      ok &= cnt[i] == s;
    }
    ok &= cnt[a] == s-1;
    if (ok) {
      printf("+%d\n", a);
      return 0;
    }
  }
  puts("*");
  return 0;
}