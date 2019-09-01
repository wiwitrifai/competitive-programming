#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5;
 
int a[N], b[N + N];
 
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  int ans = 0;
  int q;
  scanf("%d", &q);
  while (q--) {
#ifdef LOCAL
    ans = 0;
#endif
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int x, y;
      scanf("%d %d", &x, &y);
      x ^= ans;
      y ^= ans;
      --x, --y;
      swap(a[x], a[y]);
    }
    else {
      int l, r, k;
      scanf("%d %d %d", &l, &r, &k);
      l ^= ans;
      r ^= ans;
      k ^= ans;
      --l;
      for (int i = l; i < r; ++i)
        b[a[i]] = 1;
      ans = -1;
      while (k > 0) {
        ++ans;
        while (b[ans]) ++ans;
        --k;
      }
      for (int i = l; i < r; ++i)
        b[a[i]] = 0;
      printf("%d\n", ans);
    }
  }
  return 0;
}
