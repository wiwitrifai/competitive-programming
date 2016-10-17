#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long ans = 0;
  long long m = max(max(a, b), c);
  if (a == m && c == m && b == m) {
    ans = 0;
  }
  else {
    int d = (a < m) + (b < m) + (c < m);
    m *= 3;
    m -= d;
    ans = m - a - b - c;
  }
  cout << ans << endl;
  return 0;
}