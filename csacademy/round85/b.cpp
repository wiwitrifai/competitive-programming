#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, x;
  scanf("%lld %lld", &n, &x);
  int ans = 0;
  while (x >= 0) {
    int butuh = n % 10;
    butuh = (10 - butuh) % 10;
    if (x < butuh)
      break;
    ++ans;
    x -= butuh;
    n += butuh;
    n /= 10;
  }
  printf("%d\n", ans);
  return 0;
}