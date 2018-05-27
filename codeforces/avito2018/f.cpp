#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

long long a[N], b[N];
int add[N];
int n;
long long m;

bool can(long long x) {
  int l = 0, r = 0;
  fill(add, add+n, 0);
  for (int i = 0; i < n; ++i) {
    while (l < 3 * n && b[l] < a[i]-x) ++l;
    while (r+1 < 3 * n && b[r+1] <= a[i]+x) ++r;
    if (l > r) return false;
    int xl = l-i, xr = min(r, l+n-1)-i;
    xl %= n;
    xr %= n;
    if (xl < 0) xl += n;
    if (xr < 0) xr += n;
    ++add[xl];
    --add[xr+1];
    if (xl > xr) {
      ++add[0];
    }
  }
  int now = 0;
  for (int i = 0; i < n; ++i) {
    now += add[i];
    if (now == n) return true;
  }
  return false;
}

int main() {
  scanf("%d %lld", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%lld", a+i);
  for (int i = 0; i < n; ++i)
    scanf("%lld", b+i);
  sort(a, a+n);
  sort(b, b+n);
  for (int i = 0; i < n; ++i) {
    long long x = b[i];
    b[i] = x-m;
    b[i+n] = x;
    b[i+2*n] = x+m;
  }
  long long l = 0, r = m;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (can(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%lld\n", l);
  return 0;
}