#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, m;
  cin >> n >> m;
  long long ans = min(n, m);
  long long l = 0, r = 2e9 + 5;
  while (l < r) {
    long long mid = (l + r)/2;
    long long cur = mid * (mid+1)/2;
    if (cur < n-m)
      l = mid + 1;
    else
      r = mid;
  }
  ans += l;
  if (ans > n)
    ans = n;
  cout << ans << endl;
  return 0;
}