#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int a[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  sort(a, a+n);
  if (m >= n) {
    long long sum = 0;
    for (int i = 0; i < n; ++i)
      sum += a[i];
    printf("%lld %lld\n", sum, sum);
    return 0;
  }
  long long mins = 0;
  for (int i = 0; i < m; ++i)
    mins += a[i];
  long long maks = 0;
  int r = n % m;
  for (int i = 0; i < n; ) {
    maks += a[i];
    i += n/m;
    if (r > 0) {
      ++i;
      --r;
    }
  }
  printf("%lld %lld\n", mins, maks);
  return 0;
}