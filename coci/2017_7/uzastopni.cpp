#include <bits/stdc++.h>

using namespace std;

int main() {
  long long x;
  cin >> x;
  for (long long n = 2; n * (n-1) / 2 <= x; n++) {
    long long r = x - n * (n - 1) / 2;
    if (r % n) continue;
    if (r <= 0) continue;
    r /= n;
    cout << r << " " << r + n - 1 << "\n";
  }
  return 0;
}