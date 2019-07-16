#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  int ans = 3;
  b -= 1;
  c -= 2;
  ans += 3 * min(a, min(b, c));
  printf("%d\n", ans);
  return 0;
}