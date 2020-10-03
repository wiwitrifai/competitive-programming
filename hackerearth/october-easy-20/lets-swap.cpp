#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, inf = 1e9 + 7;

int p[N], r[N];
int main() {
  int n;
  scanf("%d", &n);
  long long ans = 0;
  int red = 0;
  int full = inf;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", p+i);
    r[p[i]] = i;
    ans += abs(p[i] - i);
    if (full <= i) {
      red = max(red, min(p[i], i) - full);
    }
    if (r[i]) {
      full = min(full, i);
    }
    if (p[i] <= i) {
      full = min(full, i);
    }
  }
  ans += 2 * red;
  printf("%lld\n", ans);
  return 0;
}
