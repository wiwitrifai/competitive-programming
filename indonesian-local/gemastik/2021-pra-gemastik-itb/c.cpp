#include <bits/stdc++.h>

using namespace std;

int main() {
  int p, n;
  scanf("%d %d", &p, &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a.begin(), a.end());
  int q;
  scanf("%d", &q);
  while (q--) {
    int x;
    scanf("%d", &x);
    if (x >= n) {
      printf("%d\n", p);
      continue;
    }
    int ans = *lower_bound(a.begin(), a.end(), a[x]) - 1;
    printf("%d\n", ans);
  }
  return 0;
}
