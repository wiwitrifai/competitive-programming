#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  set<int> dislike;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    dislike.insert(x);
  }
  int ans = 0, m;
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    int k;
    scanf("%d", &k);
    bool ok = true;
    for (int j = 0; j < k; ++j) {
      int x;
      scanf("%d", &x);
      ok &= !dislike.count(x);
    }
    ans += ok;
  }
  printf("%d\n", ans);
  return 0;
}
