#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c, n;
  cin >> a >> b >> c >> n;
  int d = n - (a + b - c);
  int ma = max(a, max(b, c));
  int mi = min(a, min(b, c));
  if (ma > n || mi < 0 || d < 1 || d > n || c > a || c > b)
    d = -1;
  printf("%d\n", d);
  return 0;
}