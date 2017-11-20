#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a+i);
    }
    sort(a, a+n);
    n = unique(a, a+n) - a;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      while (k > 0 && ans < a[i]) {
        ans++;
        k--;
      }
      ans += ans == a[i];
    }
    ans += k;
    printf("%d\n", ans);
  }
  return 0;
}