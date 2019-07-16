#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int x[N];
bool used[N];

int main() {
  int n, z;
  scanf("%d %d", &n, &z);
  for (int i = 0; i < n; ++i)
    scanf("%d", x+i);
  sort(x, x+n);
  int lo = 0, ri = n/2;
  while (lo < ri) {
    int mid = (lo + ri + 1) >> 1;
    bool ok = 1;
    for (int i = 0; i < mid; ++i) {
      if (x[n-mid+i] - x[i] < z) {
        ok = 0;
        break;
      }
    }
    if (ok)
      lo = mid;
    else
      ri = mid - 1;
  }
  int ans = lo;
  printf("%d\n", ans);
  return 0;
}
