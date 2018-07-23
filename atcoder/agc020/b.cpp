#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, a[N];

int main() {
  long long lo = 2, hi = 2;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  for (int i = n-1; i >= 0; --i) {
    long long low = 1LL * (lo+a[i]-1)/a[i] * a[i], hig = 1LL * (hi) / a[i] * a[i];
    if (low > hig) {
      puts("-1");
      return 0;
    }
    hig += a[i]-1;
    lo = low;
    hi = hig;
  }
  printf("%lld %lld\n", lo, hi);
  return 0;
}