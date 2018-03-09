#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N], n, d, b;
long long c[N];

long long bisa(long long x) {
  for (int i = 0; i < n; ++i) c[i] = a[i];
  long long sum = 0;
  long long need = (n + 1)/2 - x;
  long long tot = 1LL * need * b;
  for (int i = 0, j = 0; i + i < n; ++i) {
    while (j <= (i + 1LL * d * (i+1)) && j < n) {
      long long v = min(c[j], tot);
      c[j] -= v;
      tot -= v;
      sum += v;
      ++j;
    }
    if (sum >= b) {
      --need;
      sum -= b;
    }
  }
  if (need > 0) return false;
  need = n/2 - x;
  sum = 0;
  for (int i = 0, j = 0; i+i+1 < n; ++i) {
    while (j <= (i + 1LL * d * (i+1)) && j < n) {
      long long v = c[n-1-j];
      c[n-1-j] -= v;
      sum += v;
      ++j;
    }
    if (sum >= b) {
      --need;
      sum -= b;
    }
  }
  if (need > 0) return false;
  return true;
}


int main() {
  scanf("%I64d %I64d %I64d", &n, &d, &b);
  for (int i = 0; i < n; ++i)
    scanf("%I64d", a+i);
  long long l = 0, r = (n+1)/2;
  while (l < r) {
    long long mid = (l + r) >> 1;
    if (bisa(mid))
      r = mid;
    else
      l = mid+1;
  }
  printf("%I64d\n", l);
  return 0;
}