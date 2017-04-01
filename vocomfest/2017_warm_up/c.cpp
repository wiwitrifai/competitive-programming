#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++){
    int a, b;
    scanf("%d %d", &a, &b);
    int m = a * 60 + b;
    m -= 45;
    if (m < 0) m += 24 * 60;
    printf("Case #%d: %d %d\n", tt, m / 60, m % 60);
  }
  return 0;
}
