#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int lp = 0, lf = 0;
    bool ok = 1;
    for (int i = 0; i < n; ++i) {
      int p, f;
      scanf("%d %d", &p, &f);
      if (p < lp || f < lf) {
        ok = 0;
      }
      if (p - lp < f - lf)
        ok = 0;
      lp = p;
      lf = f;
    }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}
