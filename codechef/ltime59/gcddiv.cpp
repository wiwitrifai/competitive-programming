#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    int g = 0;
    for (int i = 0; i < n; ++i) {
      int a;
      scanf("%d", &a);
      g = gcd(g, a);
    }
    for (int i = 2; i * i <= g && i <= k; ++i) {
      while ((g % i) == 0) {
        g /= i;
      }
    }
    puts((g <= k) ? "YES" : "NO");
  }
  return 0;
}