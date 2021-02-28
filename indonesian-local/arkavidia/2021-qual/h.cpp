#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);
    int ansx = n / x, ansy = n / y, ansxy = ansx / (y / gcd(x, y));
    printf("%d %d\n", ansx - ansxy, ansy - ansxy);
  }
  return 0;
}
