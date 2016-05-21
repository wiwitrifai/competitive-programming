#include <bits/stdc++.h>

using namespace std;

const int inf = 1e5 + 5;
int main() {
  int x, y, a, b;
  cin >> x >> y >> a >> b;
  if (x + 8 * a >= y)
    puts("0");
  else if (a > b) {
    int num = y - x - 8 * a, den = 12 * (a - b);
    cout << (num + den - 1) / den << endl;
  } else
    puts("-1");
  return 0;
}