#include <bits/stdc++.h>

using namespace std;

int get(long long n) {
  long long now = 1, b = 9, d = 1;
  while(n > b*d) {
    now *= 10;
    n -= b*d;
    b *= 10;
    d++;
  }
  now += (n-1)/d;
  n -= ((n-1)/d) * d;
  d -= n;
  while(d) {
    now /= 10;
    d--;
  }
  return now % 10;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    long long ans = 1;
    for(int i = 0; i<7; i++) {
      long long n;
      scanf("%lld", &n);
      ans *= get(n);
    }
    printf("%lld\n", ans);
  }

  return 0;
}