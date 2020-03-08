#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, m;
  scanf("%d %d %d", &a, &b, &m);
  vector<int> va(a), vb(b);
  for (int i = 0; i < a; ++i) {
    scanf("%d", &va[i]);
  }
  for (int i = 0; i < b; ++i) {
    scanf("%d", &vb[i]);
  }
  int ans = *min_element(va.begin(), va.end()) + * min_element(vb.begin(), vb.end());
  for (int i = 0; i < m; ++i) {
    int x, y, c;
    scanf("%d %d %d", &x, &y, &c);
    --x, --y;
    ans = min(ans, va[x] + vb[y] - c);
  }
  ans = max(ans, 0);
  printf("%d\n", ans);
  return 0;
}
