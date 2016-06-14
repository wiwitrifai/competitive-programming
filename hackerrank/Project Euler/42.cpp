#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    long long n;
    scanf("%lld", &n);
    long long l = 0, r = min(n, (long long)(1e9+1));
    while(l < r) {
      long long mid = (l + r) >> 1;
      long long val = mid*(mid + 1)/2LL;
      if(val < n)
        l = mid+1;
      else
        r = mid;
    }
    if(l * (l + 1)/2LL == n)
      printf("%lld\n", l);
    else
      puts("-1");
  }  
  return 0;
}