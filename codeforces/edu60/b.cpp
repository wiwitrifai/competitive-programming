#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  sort(a, a+n);
  long long big = a[n-1], sec = a[n-2];
  int w = m / (k + 1);
  m -= w * (k + 1);
  long long ans = 1LL * (1LL * big * k + sec) * w + m * big;
  printf("%lld\n", ans); 
  return 0;
}