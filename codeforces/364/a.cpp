#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, l, v1, v2, k;
  cin >> n >> l >> v1 >> v2 >> k;
  n = (n+k-1)/k;
  double ans = (double)l/v1;
  if(v1 < v2) {
    double x = (double)l / v1;
    double y = (double)(n + (double)(v2-v1) * (n-1)/(v1+v2) - 1 + (double)v2/v1);
    x = x/y;
    ans = min(x + (double)(l-x * v2)/v1, (double)l/v1);
  }
  cout << fixed << setprecision(15) << ans << endl;
  return 0;
}