#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  long long now = 5, ans = 0;
  while (n--) {
    now /= 2;
    ans += now;
    now *= 3;
  }
  printf("%lld\n", ans);
  return 0;
}