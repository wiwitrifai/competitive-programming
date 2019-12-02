#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> c(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &c[i]);
    sort(c.begin(), c.end());
    vector<int> vcnt;
    int last = c[0], cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (c[i] != last) {
        vcnt.push_back(cnt);
        cnt = 0;
        last = c[i];
      }
      ++cnt;
    }
    vcnt.push_back(cnt);
    int maxs = (*min_element(vcnt.begin(), vcnt.end())) + 1;
    int ans = n;
    for (int s = 2; s <= maxs; ++s) {
      bool ok = 1;
      int tot = 0;
      for (int x : vcnt) {
        int g = (x + s - 1) / s;
        int r = g * s - x;
        if (r > g) {
          ok = 0;
          break;
        }
        tot += g;
      }
      if (ok)
        ans = min(ans, tot);
    }
    printf("%d\n", ans);
  }
  return 0;
}
