#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1);

int main() {
  int t;
  cin >> t;
  cout << fixed << setprecision(4);
  while (t--) {
    double n, s, r;
    cin >> n >> s >> r;
    double ans = (double)1 - (double)2.0 * r * tan(pi/n) / s;
    if (ans < 0)
      ans = 0;
    ans = (double)1 - ans * ans;
    cout << ans << endl;
  }
  return 0;
}