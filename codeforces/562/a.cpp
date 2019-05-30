#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int n, m;
int a[N];

bool can(int x) {
  int last = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] + x < last)
      return false;
    if (a[i] + x < m) {
      last = max(last, a[i]);
    }
    else {
      int from = (a[i]+x) % m;
      if (from < last)
        last = max(last, a[i]);
    }
  }
  return true;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  int lo = 0, hi = m-1;
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    if (can(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  printf("%d\n", lo);
  return 0;
}
