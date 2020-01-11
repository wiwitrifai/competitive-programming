#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

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
    for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      a[i] = x - a[i];
    }
    int l = 0, r = n-1;
    while (l <= r && a[l] == 0) ++l;
    while (l <= r && a[r] == 0) --r;
    bool ok = 1;
    if (l <= r) {
      int k = a[l];
      ok &= k > 0;
      for (int i = l; i <= r; ++i) {
        ok &= a[i] == k;
      }
    }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}
