#include <bits/stdc++.h>

using namespace std;


int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  double ans = 0;
  for (int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    double now =  (double)a * m / b;
    if (i)
      ans = min(ans, now);
    else
      ans = now;
  }
  printf("%.9lf\n", ans);
  return 0;
}