#include <bits/stdc++.h>

using namespace std;

int main() {
  int x, n;
  scanf("%d %d", &x, &n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += x;
    int a;
    scanf("%d", &a);
    ans -= a;
    if (ans < 0)
      ans = 0;
  }
  ans += x;
  printf("%d\n", ans);

  return 0;
}