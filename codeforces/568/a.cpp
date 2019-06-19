#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a[3], d;
  cin >> a[0] >> a[1] >> a[2] >> d;
  sort(a, a+3);
  long long ans = 0;
  ans += d - min(d, abs(a[1]-a[0]));
  ans += d - min(d, abs(a[1]-a[2]));
  cout << ans << endl;
  return 0;
}
