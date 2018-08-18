#include <bits/stdc++.h>

using namespace std;

const int A = 1e4 + 5, N = 1e6 + 6;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a+i);
    }
    sort(a, a+n);
    int x = -1, y = -1, last = -1;
    for (int i = 0; i + 1 < n; ++i) {
      if (i - 2 >= 0 && a[i-2] == a[i-1]) {
        last = a[i-1];
      }
      if (a[i] == a[i+1]) {
        if (x == -1 || 1LL * (x + y) * (x + y) * last * a[i] > 1LL * (last + a[i]) * (last + a[i]) * x * y)
          x = last, y = a[i];
      }
    }
    assert(x != -1 && y != -1);
    printf("%d %d %d %d\n", x, x, y, y);
  }
  return 0;
}