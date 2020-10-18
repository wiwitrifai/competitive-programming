#include <bits/stdc++.h>

using namespace std;

long long ans[5];

long long sqrti(long long n) {
  long long x = sqrt(n);
  if (x * x > n)
    --x;
  assert(x * x <= n);
  if ((x+1) * (x+1) > n)
    return x;
  long long low = x, hig = x * 2;
  while (low < hig) {
    long long mid = (low + hig + 1) >> 1;
    if (mid * mid <= n)
      low = mid;
    else
      hig = mid - 1;
  }
  return low;
}

bool calc(long long n, int k) {
  if (k == 3) {
    long long x = sqrti(n);
    ans[k] = x;
    return (x * x == n);
  }
  long long x = sqrti(n);
  while (x >= 0) {
    ans[k] = x;
    if (calc(n - x * x, k+1))
      return true;
    --x;
  }
  return false;
}

int main() {
  long long n;
  scanf("%lld", &n);
  cerr << calc(n, 0) << endl;
  for (int i = 0; i < 4; ++i)
    printf("%lld%c", ans[i], i == 3 ? '\n' : ' ');
  return 0;
}
