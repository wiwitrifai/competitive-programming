#include <bits/stdc++.h>

using namespace std;

long long powlong(long long b, long long p) {
  long long ret = 1;
  while (p) {
    if (p&1)
      ret = ret * b;
    b = b * b;
    p >>= 1;
  }
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n;
    scanf("%lld", &n);
    if (n == 0)
      puts("0");
    else if (n == 1) 
      puts("INFINITY");
    else {
      long long ans = 0;
      for (int k = 1; k <= 44; k++) {
        long long up = pow((double)n, (double)1/k);
        long long low = pow((double)n/2., (double)1/k); 
        while (powlong(up+1, k) <= n)
          up++;
        while (powlong(up, k) > n)
          up--;
        while (2LL * powlong(low, k) <= n)
          low++;
        while (2LL * powlong(low-1, k) > n)
          low--;
        // cerr << powlong(low, k) << " " << n << " " << powlong(up, k) << endl;
        // cerr << low << " " << up << endl;
        ans += max(up-low+1, 0LL);
      }
      printf("%lld\n", ans);
    } 
  }

  return 0;
}