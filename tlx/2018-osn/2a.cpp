#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];
int sa[N];
long long a = 0, b = 0;
int len;
long long countA(long long c) {
  long long z = c / len;
  int r = c % len;
  return z * a + sa[r];
}

long long countB(long long c) {
  return c - countA(c);
}

int main() {
  scanf("%*s");
  int k, q;
  scanf("%s %d %d", s, &k, &q);
  len = strlen(s);
  for (int i = 0; i < len; ++i)
    if (s[i] == 'A')
      ++a;
    else
      ++b;
  sa[0] = 0;
  for (int i = 0; i < len; ++i) {
    sa[i+1] = sa[i] + (s[i] == 'A');
  }
  long long n = 1LL * len * k + 1;
  long long center = 1LL * b * k + 1;
  while (q--) {
    long long l, r;
    scanf("%lld %lld", &l, &r);
    if (l <= center && center <= r) {
      printf("%lld\n", n);
    }
    else  if (r < center) {
      long long lo = 1, hi = n;
      while (lo < hi) {
        long long mid = (lo + hi) >> 1;
        if (countB(mid) >= r)
          hi = mid;
        else
          lo = mid+1;
      }
      printf("%lld\n", lo);
    }
    else {
      long long lo = 1, hi = n;
      while (lo < hi) {
        long long mid = (lo + hi) >> 1;
        if (countA(mid) >= n-l+1)
          hi = mid;
        else
          lo = mid+1;
      }
      printf("%lld\n", lo);
    }
  }
  return 0;
}