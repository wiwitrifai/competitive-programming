#include <bits/stdc++.h>

using namespace std;

void solve() {
  long long p, f, cs, cw, s, w;
  scanf("%lld %lld %lld %lld %lld %lld", &p, &f, &cs, &cw, &s, &w);
  if (s > w) {
    swap(s, w);
    swap(cs, cw);
  }
  long long ans = 0;
  for (int i = 0; i <= cs; ++i) {
    long long now = i * s;
    if (now > p) break;
    long long sa = i, wa = min(cw, (p - now) / w);
    long long sb = min(cs - i, f / s);
    long long sisa = f - sb * s;
    long long wb = min(cw - wa, sisa / w);
    ans = max(ans, sa + sb + wa + wb);
  }
  printf("%lld\n", ans);
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
