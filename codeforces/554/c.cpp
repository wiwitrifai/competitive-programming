#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  if ((a % b) == 0 || (b % a) == 0) {
    puts("0");
    return 0;
  }
  long long d = abs(a - b);
  vector<int> divs;
  for (int x = 1; 1LL * x * x <= d; ++x){
    if (d % x) continue;
    divs.push_back(x);
    long long y = d / x;
    if (y != x)
      divs.push_back(y);
  }
  int ans = -1;
  long long best = 1LL << 62;
  for (int x : divs) {
    int y = (a / x) * x;
    while (y < a) y += x;
    int k = y - a;
    int g = gcd(a + k, b + k);
    long long cur = ((long long) (a + k) / g) * (long long)(b + k);
    if (best > cur) {
      ans = k;
      best = cur;
    }
  }
  assert(ans != -1);
  printf("%d\n", ans);
  return 0;
}
