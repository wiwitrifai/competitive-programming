#include <bits/stdc++.h>

using namespace std;

int main() {
  int i, n;
  scanf("%d %d", &i, &n);
  int ans = min(abs(n-i) * 2, 4 + abs(n-i));
  printf("%d\n", ans);
  return 0;
}
