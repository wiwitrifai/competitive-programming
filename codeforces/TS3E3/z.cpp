#include <bits/stdc++.h>

using namespace std;

int main() {
  long long d, k, n;
  cin >> d >> k >> n;
  long long r = (k+d-1) % d, l = k+1;
  if (k & 1) {
    l = (l + 2 * n) % d;
    r = (r + 2 * n) % d;
  }
  else {
    l = (l + (d - 2) * n) % d;
    r = (r + (d - 2) * n) % d;
  }
  if (l == 0)
    l = d;
  if (r == 0)
    r = d;
  cout << l << " " << r << endl;
  return 0;
}