#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int c, m, x;
    scanf("%d %d %d", &c, &m, &x);
    int ans = min(min(c, m), (c + m + x) / 3);
    printf("%d\n", ans);
  }
  return 0;
}
