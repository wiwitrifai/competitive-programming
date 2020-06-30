#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  int ans = min(min(a, b) + c, min(d, e));
  printf("%d\n", ans);
  return 0;
}
