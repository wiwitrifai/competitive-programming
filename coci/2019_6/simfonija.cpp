#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N];
long long sum[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int len = n - k;
  if (len <= 1) {
    puts("0");
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  vector<pair<int, int> > s;
  for (int i = 0; i < n; ++i) {
    scanf("%d", b+i);
    s.emplace_back(b[i] - a[i], i);
  }
  sort(s.begin(), s.end());
  sum[0] = 0;
  for (int i = 0; i < n; ++i) {
    sum[i+1] = sum[i] + s[i].first;
  }
  long long ans = 1e18;
  for (int i = 0, l = 0; i < n; ++i) {
    int x = s[i].first;
    l = max(l, i - len + 1);
    while (l < i && l + len < n && x - s[l].first > s[l+len].first - x) ++l;
    ans = min(ans, abs(sum[i] - sum[l] - 1LL * x * (i - l)) +
      abs(sum[l+len] - sum[i] - 1LL * x * (l + len - i)));
  }
  printf("%lld\n", ans);
  return 0;
}