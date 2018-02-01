#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const int inf = 1e9;

int a[N], b[N];
int n, m;

int until(int u) {
  int ans = inf;
  for (int i = 0; i < m; i++) {
    if (u < a[i]) {
      ans = min(ans, a[i]);
    }
  }
  return ans;
}

int get(int l, int r) {
  int ori = r;
  for (int i = 0; i < m; i++) {
    if (l <= a[i] && a[i] <= r) {
      r = max(r, b[i]);
    }
  }
  if (ori == r) return r;
  return get(l, r);
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) scanf("%d %d", a + i, b + i);
  int now = 0;
  int ans = n + 1;
  while (now <= n) {
    int lef = until(now);
    if (lef == inf) break;
    int rig = get(lef, lef);
    ans += (rig - lef) * 2;
    now = rig;
  }
  cout << ans << endl;
  return 0;
}