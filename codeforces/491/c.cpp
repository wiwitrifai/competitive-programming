#include <bits/stdc++.h>

using namespace std;



int main() {
  long long n;
  cin >> n;
  long long l = 1, r = n;
  while (l < r) {
    long long mid = (l + r) >> 1;
    long long cur = n;
    long long now = 0;
    while (cur > 0) {
      long long d = min(cur, mid);
      cur -= d;
      now += d;
      cur -= cur / 10;
    }
    if (now * 2 >= n)
      r = mid;
    else
      l = mid + 1;
  }
  printf("%lld\n", l);
  return 0;
}