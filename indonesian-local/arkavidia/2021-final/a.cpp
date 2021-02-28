#include <bits/stdc++.h>

using namespace std;

bool check(long long x) {
  for (int i = 0; i < 25 && x > 0; ++i) {
    int d = x % 10;
    x /= 10;
    if (1 < d && d < 8)
      return false;
  }
  return x == 0;
}

int main() {
  long long n;
  cin >> n;
  long long ans = n;
  while (!check(ans)) {
    ans += n;
  }
  cout << ans << endl;
  return 0;
}
