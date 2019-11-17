#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  vector<int> b = a;
  sort(b.begin(), b.end());
  int l = 0;
  while (l < n && a[l] == b[l]) ++l;
  int r = n-1;
  while (r >= 0 && a[r] == b[r]) --r;
  if (r < l) {
    puts("1 1");
    return 0;
  }
  reverse(a.begin() + l, a.begin() + r + 1);
  bool ok = 1;
  for (int i = 0; i < n; ++i)
    ok &= a[i] == b[i];
  if (ok) {
    printf("%d %d\n", l+1, r+1);
    return 0;
  }
  else {
    puts("impossible");
  }

  return 0;
}
