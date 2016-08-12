#include <bits/stdc++.h>

using namespace std;



int main() {
  int a, b;
  double ans = 1e9;
  cin >> a >> b;
  int n;
  cin >> n;
  for(int i = 0; i<n; i++) {
    int x, y, v;
    cin >> x >> y >> v;
    x -= a;
    y -= b;
    double res = (double)sqrt(x * x + y * y)/v;
    ans = min(ans, res);
  }
  printf("%.15lf\n", ans);
  
  return 0;
}