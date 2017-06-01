#include <bits/stdc++.h>

using namespace std;

long long x, y, t, n; 

int main() {
  scanf("%lld", &t);
  while(t--) {
    scanf("%lld", &n);
    long long k = n/4;
    x = y = -2*k;
    k = n - (n % 4);
    if(k + 3 <= n) 
      x += -2;
    else {
      if(k<n)
        x += k+1;
    }
    if(k+2 <= n) {
      y += k+2;
    }
    printf("%lld %lld\n", x, y);
  }

  return 0;
}