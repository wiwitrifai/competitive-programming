#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("anniversary.in", "r", stdin);
  freopen("anniversary.out", "w", stdout);

  int h, w, a, b, c, d;
  scanf("%d %d %d %d %d %d", &h, &w, &a, &b, &c, &d);
  if (a == c)
    printf("%d %d %d %d\n", 0, b, h, d);
  else
    printf("%d %d %d %d\n", a, 0, c, w);
  return 0;
}