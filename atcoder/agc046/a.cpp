#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }

int main() {
  int x;
  scanf("%d", &x);
  int ans = 360 / gcd(x, 360);
  printf("%d\n", ans);
  return 0;
}
