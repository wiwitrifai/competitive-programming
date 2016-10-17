#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    double ans = (double)2 * a / (3 * b);
    printf("%.9lf\n", ans);
  }
  return 0;
}