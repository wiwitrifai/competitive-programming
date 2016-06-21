#include <bits/stdc++.h>

using namespace std;

long long n, c;
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%lld%lld", &n, &c);
    bool ok = true;
    if(n == 1) {
      puts("Yes");
      continue;
    }
    if(n & 1) {
      if((c % n) != 0)
        ok = false;
      else {
        c /= n;
        long long k = (n-1)/2;
        long long b = c/k;
        long long a = c % k;
        if(a == 0)
          a += k, b--;
        if(b <= 0 || a <= 0)
          ok = false;
      }
    }
    else {
      long long k = n/2;
      if(c % k)
        ok = false;
      else {
        c /= k;
        k = n-1;
        long long r = c % k;
        long long b = c / k;
        while(r <= 0 || (r & 1)) {
          r += k;
          b--;
        }
        if(r <= 0 || b <= 0 || (r & 1))
          ok = false;
      }
    }
    puts(ok ? "Yes" : "No");
  }

  return 0;
}