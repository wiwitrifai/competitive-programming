#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("king.in", "r", stdin);
  freopen("king.out", "w", stdout);
  int d, m, y;
  scanf("%d %d %d", &d, &m, &y);
  int n;
  scanf("%d", &n);
  int ans = -1;
  int dd, mm, yy;
  dd = mm = yy = 0;
  for (int i = 1; i <= n; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int age = y - c - (make_pair(b, a) > make_pair(m, d));
    if (age >= 18) {
      if (make_pair(c, make_pair(b, a)) > make_pair(yy, make_pair(mm, dd))) {
        ans = i;
        dd = a;
        mm = b;
        yy = c;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}