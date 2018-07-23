#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, l[N], r[N];

pair<int, int> le[N], ri[N];


int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", l+i, r+i);
    le[i] = {l[i], i};
    ri[i] = {r[i], i};
  }
  l[0] = r[0] = 0;
  le[n] = {0, n};
  ri[n] = {0, n};
  sort(le, le+n+1);
  sort(ri, ri+n+1);
  reverse(le, le+n+1);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    if (le[i].first < ri[i].first)
      break;
    ans += 2 * (le[i].first - ri[i].first);
  }
  printf("%lld\n", ans);
  return 0;
}