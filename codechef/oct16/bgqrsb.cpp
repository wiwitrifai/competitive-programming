#include <bits/stdc++.h>

using namespace std;

const int N = 10024;
int a[N], cnt2[N], cnt5[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%lld", a+i);
      int x = a[i], y = 0;
      while ((x % 2) == 0) {
        y++; x /= 2;
      }
      cnt2[i] = y;
      y = 0;
      while ((x % 5) == 0) {
        y++; x /= 5;
      }
      cnt5[i] = y;
    }
    int ans = 0;
    while (m--) {
      int ty, l, r;
      int x;
      scanf("%d %d %d", &ty, &l, &r);
      if (ty == 1) {
        scanf("%d", &x);
        int y = 0;
        while ((x % 2) == 0) {
          y++; x /= 2;
        }
        for (int i = l-1; i < r; i++) {
          cnt2[i] += y;
        }
        y = 0;
        while ((x % 5) == 0) {
          y++; x /= 5;
        }
        for (int i = l-1; i < r; i++) {
          cnt5[i] += y;
        }
      }
      else if (ty == 2) {
        scanf("%d", &x);
        int y = 0;
        while ((x % 2) == 0) {
          y++; x /= 2;
        }
        for (int i = l-1, j = 1; i < r; i++, j++) {
          cnt2[i] = y;
          int now = j;
          while ((now % 2) == 0) {
            now /= 2;
            cnt2[i]++;
          }
        }
        y = 0;
        while ((x % 5) == 0) {
          y++; x /= 5;
        }
        for (int i = l-1, j = 1; i < r; i++, j++) {
          cnt5[i] = y;
          int now = j;
          while ((now % 5) == 0) {
            now /= 5;
            cnt5[i]++;
          }
        }
      }
      else {
        int a2 = 0, a5 = 0;
        for (int i = l-1; i < r; i++) {
          a2 += cnt2[i];
          a5 += cnt5[i];
        }
        // printf("%d %d\n", a2, a5);
        ans += min(a2, a5);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}