#include <bits/stdc++.h>

using namespace std;

void solve() {
  int l, r;
  long long m;
  scanf("%d %d %lld", &l, &r, &m);
  for (int a = l; a <= r; ++a) {
    long long n1 = m  / a, n2 = n1 + 1;
    long long d1 = m - n1 * a, d2 = m - n2 * a;
    long long d = d2;
    if (abs(d1) < abs(d2) && n1 > 0)
      d = d1;
    if (abs(d) <= r-l) {
      int b, c;
      if (d < 0)
        c = r, b = c + d;
      else
        c = l, b = c + d;
      printf("%d %d %d\n", a, b, c);
      return;
    }
  }
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
