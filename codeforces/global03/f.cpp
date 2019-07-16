#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int n;
long long val[N], mask[N];

int main() {
  scanf("%d", &n);
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%lld %lld", val+i, mask+i);
    sum += val[i];
  }
  if (sum < 0) {
    for (int i = 0; i < n; ++i)
      val[i] *= -1;
    sum *= -1;
  }
  long long s = 0;
  for (int bit = 61; bit >= 0; --bit) {
    long long cur = 0;
    for (int i = 0; i < n; ++i) {
      if (__builtin_ctzll(mask[i]) == bit) {
        cur += ((__builtin_popcountll(s & mask[i]) & 1) ? -1 : 1) * val[i]; 
      }
    }
    if (cur > 0) {
      s |= 1LL << bit;
    }
  }
  printf("%lld\n", s);
  return 0;
}
