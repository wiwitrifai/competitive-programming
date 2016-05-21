#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    long long n;
    scanf("%lld", &n);
    long long l = 0, r = 1e5;
    while(l < r) {
      long long mid = (l + r + 1) >>1;
      if(mid*(mid+1)/2 > n)
        r = mid-1;
      else
        l = mid;
    }
    printf("%lld\n", l);
  }
  return 0;
}