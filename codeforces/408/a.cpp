#include <bits/stdc++.h>

using namespace std;

int a[111], n, m, k;

int main() {
  scanf("%d %d %d", &n, &m, &k);
  int ans = 10000;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a+i);
    if (a[i] > 0 && a[i] <= k)
      ans = min(ans, abs(i-m) * 10);
  }
  printf("%d\n", ans);
  return 0;
}