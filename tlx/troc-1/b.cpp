#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, r, v;
  scanf("%d %d %d", &n, &r, &v);
  bool ok = 1;
  double ans = 0;
  for (int i = 0; i < n; ++i) {
    int w;
    scanf("%d", &w);
    if (w == v) {
      ok = 0;
    }
    else {
      ans = max(ans, (double)r / abs(v - w));
    }
  }
  if (!ok)
    puts("-1");
  else
    printf("%.9lf\n", ans);
  return 0;
}