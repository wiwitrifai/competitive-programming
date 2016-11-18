#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18 + 9;

long double C(long long n, long long k) {
  k = min(k, n-k);
  long double ret = 1;
  for (int i = 1; i <= k; i++) {
    ret = (ret * (n-i+1)) / i;
  }
  return ret;
}


int main() {

  long long n, k;
  cin >> n >> k; 
  int tc = 1;
  while (n || k) {
    printf("Case %d: ", tc++);
    if (n == 1) {
      printf("%lld\n", k);
      cin >> n >> k;
      continue;
    }
    if (n == 2) {
      long long l = 0, r = 2e9;
      while (l < r) {
        long long mid = (l+r+1)>>1;
        long long sum = (mid+1) * mid / 2;
        if (sum > k)
          r = mid - 1;
        else
          l = mid;
      }
      k -= (l+1) * l / 2;
      printf("%lld %lld\n", k, l-k);
      cin >> n >> k;
      continue;
    }
    long long sum = 0;
    long long l = 0, r = 1e7 + 5;
    while (l < r) {
      long long mid = (l + r + 1) >> 1;
      long double cnt = C(mid+n, n);
      if (cnt > k)
        r = mid -1;
      else
        l = mid;
    }
    long long now = C(l+n, n);
    if (k >= now) {
      k -= now;
      l++;
    }
    sum = l;
    // cerr << sum << endl;
    for (int i = n-1; i>0; i--) {
      long long ans = 0;
      l = 0; r = sum;
      long double tot = C(sum+i, i);
      while(l < r) {
        long long mid = (l + r + 1) >> 1;
        long double cnt = tot - C(sum+i-mid, i);
        // cerr << mid << " " << tot << "-" << C(sum+i-mid, i) << "=" << tot - C(sum+i-mid, i)  << " "<< k << endl;
        if (k < cnt)
          r = mid - 1;
        else
          l = mid; 
      }
      k -= (long long)(tot - C(sum+i-l, i));
      sum -= l;
      printf("%lld ", l);
    }
    printf("%lld\n", sum);
    cin >> n >> k;
  }
  return 0;
}