#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int s[N];
vector<int> ok[N];
int cnt[N], a[N];

int main() {
  for (int i = 2; i < N; ++i) {
    if (s[i]) continue;
    for (int j = i; j < N; j += i)
      s[j] += i;
  }
  for (int i = 2; i < N; ++i) {
    for (int j = i+i; j < N; j += i) {
      if (s[j] % s[i]) continue;
      ok[j].push_back(i);
    }
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    long long ans = 0;
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a+i);
      ++cnt[a[i]];
    }
    sort(a, a+n);
    n = unique(a, a+n) - a;
    for (int i = 0; i < n; ++i) {
      for (int v : ok[a[i]]) {
        ans += 1LL * cnt[v] * cnt[a[i]];
      }
      ans += 1LL * cnt[a[i]] * (cnt[a[i]] - 1);
    }
    printf("%lld\n", ans);
  }
  return 0;
}