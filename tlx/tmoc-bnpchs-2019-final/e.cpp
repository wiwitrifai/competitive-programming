#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];

void solve() {
  int n;
  scanf("%d", &n);
  int ans = 1;
  long long sum = 0;
  while ((sum = 1LL * ans * (ans + 1) / 2) < n || ((sum & 1) != (n&1)))
    ++ans;
  for (int i = 0; i < ans; ++i)
    s[i] = '+';
  s[ans] = 0;
  long long sisa = 1LL * ans * (ans + 1) / 2 - n;
  assert((sisa & 1) == 0);
  sisa /= 2;
  for (int i = ans; i > 0; --i) {
    if (sisa >= i) {
      sisa -= i;
      s[ans - i] = '-';
    }
  }
  printf("%d %s\n", ans, s);
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
