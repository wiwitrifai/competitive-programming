#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  int n, k, x;
  scanf("%d%d", &n, &k);
  int d = 0;
  for(int i = 0; i<n; i++) {
    scanf("%d", &x);
    d = gcd(d, x);
  }
  int ans = (k/d) * d;
  for(int i = 2; 1LL*i*i<= d; i++) if((d % i) == 0) {
    int j = d/i;
    ans = max(ans, max((k/i) * i), (k/j) * j);
  }
  printf("%d\n", ans);
  return 0;
}