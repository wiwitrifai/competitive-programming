#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b;
  cin >> a >> b;
  bool ok = 1;
  while (ok) {
    if (a == 0 || b == 0)
      ok = 0;
    else if (a >= 2 * b) {
      long long k = a / (2 * b);
      a -= k * 2 * b;
      ok = 1;
    }
    else if (b >= 2 * a) {
      long long k = b / (2 * a);
      b -= k * 2 * a;
      ok = 1;
    }
    else ok = 0;
  }
  cout << a << " " << b << endl;
  return 0;
}