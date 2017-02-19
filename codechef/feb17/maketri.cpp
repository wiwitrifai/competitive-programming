#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
long long l, r, a[N];
int n;
int main() {
  scanf("%d %lld %lld", &n, &l, &r);
  for (int i = 0; i <  n; i++)
    scanf("%lld", a+i);
  sort(a, a+n);
  vector< pair< long long, long long > > range;
  for (int i = 1; i < n; i++) {
    range.push_back(make_pair(a[i]-a[i-1]+1, a[i] + a[i-1] - 1));
  }
  sort(range.begin(), range.end());
  long long ans = r-l + 1;
  long long now = l;
  for (int i = 0; i < range.size(); i++) {
    if (range[i].first > now)
      ans -= min(range[i].first-now, r+1-now);
    now = max(range[i].second+1, now);
    if (now > r)
      break;
  }
  if (now <= r)
    ans -= r+1-now;
  printf("%lld\n", ans);
  return 0;
}