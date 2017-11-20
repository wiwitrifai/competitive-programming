#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N], n, x;

int cek(int m) {
  for (int i = 0; i < n; i++)
    b[i] = a[i];
  reverse(b, b+n-m);
  int now = 0;
  for (int i = 0; i < n; i++) {
    if (1LL * now * n < 1LL * i * b[i])
      now++;
  }
  return now;
}

int main() {
  scanf("%d %d", &n, &x);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  sort(a, a+n);
  int l = 0, r = n;
  while (l < r) {
    int m = (l + r) >> 1;
    if (cek(m) < x)
      l = m+1;
    else
      r = m;
  }
  int now = l;
  l = 0, r = n;
  while (l < r) {
    int m = (l + r + 1) >> 1;
    if (cek(m) <= x)
      l = m;
    else
      r = m-1;
  }
  int ans = l;
  if (abs(cek(now) - x) < abs(cek(ans) - x))
    ans = now;
  cek(now);
  for (int i = 0; i < n; i++)
    printf("%d%c", b[i], i == (n-1) ? '\n' : ' ');
  return 0;
}