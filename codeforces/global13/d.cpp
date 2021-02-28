#include <bits/stdc++.h>

using namespace std;

void solve() {
  long long u, v;
  scanf("%lld %lld", &u, &v);
  if (__builtin_popcountll(u) < __builtin_popcountll(v)) {
    puts("NO");
    return;
  }
  int cur = 30;
  while (cur >= 0 && (u >> cur) == (v >> cur)) {
    --cur;
  }
  long long mask = (1LL << (cur + 1)) - 1;
  u &= mask;
  v &= mask;
  if (u > v) {
    puts("NO");
    return;
  }
  for (int i = 0, j = 0; i <= cur; ++i) {
    if ((v & (1LL << i)) == 0) continue;
    while (j <= i && ((u & (1LL << j))) == 0) ++j;
    if (j > i) {
      puts("NO");
      return;
    }
    ++j;
  }
  puts("YES");
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
