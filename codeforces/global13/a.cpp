#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  vector<int> a(n);
  int one = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    one += a[i];
  }
  for (int i = 0; i < q; ++i) {
    int t, x;
    scanf("%d %d", &t, &x);
    if (t == 1) {
      --x;
      if (a[x])
        --one;
      else
        ++one;
      a[x] ^= 1;
    } else {
      if (x <= one)
        puts("1");
      else
        puts("0");
    }
  }
  return 0;
}
