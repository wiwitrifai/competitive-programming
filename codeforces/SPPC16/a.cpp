#include <bits/stdc++.h>

using namespace std;

pair< long long, long long> get(long long n) {
  if (n == 1)
    return make_pair(0, 0);
  long long l = 0, r = 31000;
  while (l < r) {
    long long mid = (l + r + 1) >> 1;
    long long k = mid * 2 + 1;
    if (k * k < n)
      l = mid;
    else
      r = mid - 1;
  }
  long long k = l + l + 1;
  n -= k * k;
  if (n <= k+1)
    return make_pair(-(k+1)/2 + n, (k+1)/2);
  n -= k+1;
  if (n <= k+1)
    return make_pair((k+1)/2, (k+1)/2-n);
  n -= k+1;
  if (n <= k+1)
    return make_pair((k+1)/2-n, -(k+1)/2);
  n -= k+1;
  assert(n <= k+1);
  return make_pair(-(k+1)/2, -(k+1)/2+n);
}

int main() {
  long long a, b;
  cin >> a >> b;
  pair< long long, long long> aa = get(a), bb = get(b);
  cout << abs(aa.first - bb.first) + abs(aa.second - bb.second) << endl;

  return 0;
}