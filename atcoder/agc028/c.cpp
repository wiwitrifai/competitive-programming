#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N];
bool used[N];

int main() {
  int n;
  scanf("%d", &n);
  long long ans = 0, tmp = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", a+i, b+i);
    ans += a[i];
    tmp += b[i];
    if (a[i] > b[i])
      swap(a[i], b[i]);
  }
  ans = min(ans, tmp);
  vector<pair<int, int> > vp;
  for (int i = 0; i < n; ++i) {
    vp.emplace_back(a[i], i);
    vp.emplace_back(b[i], i);
  }
  sort(vp.begin(), vp.end());
  bool ok = 0;
  tmp = 0;
  for (int i = 0; i < n; ++i) {
    tmp += vp[i].first;
    if (used[vp[i].second])
      ok = 1;
    used[vp[i].second] = 1;
  }
  if (ok)
    ans = min(ans, tmp);
  tmp = 0;
  for (int i = 0; i < n; ++i)
    tmp += a[i];
  int big = 0, small = 0;
  for (int i = 1; i < n; ++i) {
    if (b[i] <= b[small])
      small = i;
    if (a[i] > a[big])
      big = i;
  }
  for (int i = 0; i < n; ++i) {
    if (i != small)
      ans = min(ans, tmp + b[small] - a[i]);
    if (i != big)
      ans = min(ans, tmp + b[i] - a[big]);
  }
  printf("%lld\n", ans);
  return 0;
}