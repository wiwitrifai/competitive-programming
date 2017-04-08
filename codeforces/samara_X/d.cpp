#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  int now = 0;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    now = gcd(now, a);
  }
  x = abs(x);
  puts((x % now) ? "NO" : "YES");
  return 0;
}