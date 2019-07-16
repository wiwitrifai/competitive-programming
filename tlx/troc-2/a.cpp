#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, a, b;
  scanf("%d %d %d %d", &n, &m, &a, &b);
  int ans = max((n/a) * (m/b), (m/a) * (n/b));
  printf("%d\n", ans);
  return 0;
}