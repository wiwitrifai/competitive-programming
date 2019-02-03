#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

pair<long long, long long> calc(int n, long long k) {
  return {k, 2 * n + 1};
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, p, x, y, z;
    scanf("%d %d %d %d %d", &n, &p, &x, &y, &z);
    if (p == 3)
      swap(x, z);
    p &= 1;
    pair<long long, long long> ans = {0, 1};
    if (p) {
      if (x < y) {
        if (z < y) {
          ans = calc(n, z);
        }
        else {
          ans = calc(n, z);
          ans.first = ans.second - ans.first;
        }
      }
      else {
        if (z < y) {
          ans = calc(n, z);
          ans.first = ans.second - ans.first;
        }
        else {
          ans = calc(n, z);
        }
      }
    }
    else {
      if (y - x == y - z)
        ans = calc(n, 0);
      else {
        ans = calc(n, 2 * y);
        ans.first = ans.second - ans.first;
      }
    }
    long long d = gcd(ans.first, ans.second);
    if (d == 0) {
      ans.first = 0;
      ans.second = 1;
      d = 1;
    }
    ans.first /= d;
    ans.second /= d;
    printf("%lld %lld\n", ans.first, ans.second);
  }
  return 0;
}