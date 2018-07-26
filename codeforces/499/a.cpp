#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  bool ok = 1;
  long double z = 1;
  for (int i = 0; i < 2 * n; ++i) {
    int a;
    scanf("%d", &a);
    if (a == 1)
      ok = 0;
    z *= (1.0 - 1.0/(double)a);
  }
  if (!ok) {
    puts("-1");
    return 0;
  }
  double ans = m * (1.0 / z - 1);
  printf("%.10lf\n", ans);
  return 0;
}