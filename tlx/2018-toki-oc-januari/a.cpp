#include <bits/stdc++.h>

using namespace std;

int main() {
  long long k;
  cin >> k;
  if (k == 1) {
    puts("0 0");
    return 0;
  }
  int l = 0, r = 1e9;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    long long now = 2LL * mid * mid - 2LL * mid + 1LL;
    if (now < k)
      l = mid;
    else
      r = mid-1;
  }
  long long cnt = 2LL * l * l - 2LL * l + 1LL;
  k -= cnt;
  if (k == 1) {
    cout << -l << " 0" << endl;
    return 0;
  }
  k -= 1;
  if (k <= 2 * (l-1)) {
    int x = (k + 1) / 2;
    x = l-x;
    cout << -x << " ";
    if (k & 1) {
      cout << l-x << endl;
    }
    else
      cout << -(l-x) << endl;
    return 0;
  }
  k -= 2 * (l-1);
  if (k <= l+1) {
    cout << k-1 << " " << l-(k-1) << endl;
  }
  else {
    k -= l+1;
    cout << l-k << " " << -k << endl;
  }
  return 0;
}