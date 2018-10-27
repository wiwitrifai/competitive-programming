#include <bits/stdc++.h>

using namespace std;

long long find(int n) {
  if (n == 0)
    return 0;
  long long l = 1, r = sqrt(n) * 2 + 5;
  while (l < r) {
    long long mid = (l + r + 1) >> 1;
    long long cur = 1LL * mid * (mid - 1) / 2;
    if (cur <= n)
      l = mid;
    else
      r = mid-1;
  }
  if (1LL * l * (l-1) / 2 != n)
    return -1;
  return l;
}

int main() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  long long sum = a + b + c + d;
  if (sum == 0) {
    puts("0");
    return 0;
  }
  long long n = find(a), m = find(d);
  long long s = find(sum);
  if ((b + c) > 0 && n == 0)
    n = 1;
  if ((b + c) > 0 && m == 0)
    m = 1;
  if (n == -1 || m == -1 || ((b + c) != 1LL * n * m)) {
    puts("impossible");
    return 0;
  }
  long long cur = n;
  for (int i = 0; i < m; ++i) {
    while (cur > c) {
      printf("0");
      --cur;
    }
    printf("1");
    c -= cur;
  }
  while (cur > 0) {
    printf("0");
    --cur;
  }
  printf("\n");
  return 0;
}