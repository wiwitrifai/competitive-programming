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
    int maxi = 0;
    int last = a[0];
    for (int i = 1; i < n; ++i) {
      if (a[i] < last) {
        maxi = max(maxi, last - a[i]);
      }
      last = max(last, a[i]);
    }
    int ans = 0;
    if (maxi > 0) {
      while ((1LL << ans) <= maxi) ++ans;
    }
    printf("%d\n", ans);
  }
  return 0;
}
