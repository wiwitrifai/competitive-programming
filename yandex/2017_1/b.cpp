#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, a;
  cin >> n >> a;
  if (abs(a - (n-a)) <= 100000) {
    long long ans = 0;
    for (long long x = a; n-x >= a; x++) {
      long long le = (-x) % 5000, ri = (x-n) % 5000;
      if (le < 0) le += 5000;
      if (ri < 0) ri += 5000;
      ans = max(ans, (le % 500) + (ri % 500));
    }
    cout << ans << endl;
  }
  else {
    n %= 100000;
    n += 100000;
    long long ans = 0;
    for (long long x = 0; x <= n; x++) {
      long long le = (-x) % 5000, ri = (x-n) % 5000;
      if (le < 0) le += 5000;
      if (ri < 0) ri += 5000;
      ans = max(ans, (le % 500) + (ri % 500));
    }
    cout << ans << endl;
  }
  return 0;
}