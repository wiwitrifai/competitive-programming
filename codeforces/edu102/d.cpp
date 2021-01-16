#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N];
int lup[N], ldown[N];
int rup[N], rdown[N], pre[N];

void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  scanf("%s", s);
  int now = 0;
  lup[0] = ldown[0] = 0;
  rup[0] = rdown[0] = 0;
  pre[0] = 0;
  for (int i = 0; i < n; ++i) {
    lup[i+1] = lup[i];
    ldown[i+1] = ldown[i];
    if (s[i] == '+') {
      ++now;
      lup[i+1] = max(lup[i+1], now);
    } else {
      --now;
      ldown[i+1] = min(ldown[i+1], now);
    }
    pre[i+1] = rdown[i+1] = rup[i+1] = now;
  }
  for (int i = n-1; i >= 0; --i) {
    rdown[i] = min(rdown[i], rdown[i+1]);
    rup[i] = max(rup[i], rup[i+1]);
  }
  while (m--) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l;
    int vmax = lup[l], vmin = ldown[l];
    vmax = max(vmax, pre[l] + rup[r] - pre[r]);
    vmin = min(vmin, pre[l] + rdown[r] - pre[r]);
    printf("%d\n", vmax - vmin + 1);
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
