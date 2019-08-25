#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  long long m;
  scanf("%d %lld", &n, &m);
  int tiga = 0;
  long long ans = 1;
  for (int i = 1; i <= 3 * n; ++i) {
    int now = i;
    while ((now % 3) == 0) {
      ++tiga;
      now /= 3;
    }
    ans = ans * now % m;
  }
  tiga -= n;
  for (int i = 0; i < tiga; ++i) {
    ans = ans * 3 % m;
  }
  if (ans < 0)
    ans += m;
  printf("%lld\n", ans);
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    printf("Case #%d: ", tc);
    solve();
  }
  return 0;
}
