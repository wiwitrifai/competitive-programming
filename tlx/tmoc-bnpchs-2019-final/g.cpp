#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, LG = 20;

int sp[LG][N];
int x[N];

int get(int l, int r) {
  int len = r - l + 1;
  int lg = 31 - __builtin_clz(len);
  int le = sp[lg][l], ri = sp[lg][r-(1 << lg) + 1];
  return x[le] > x[ri] ? le : ri;
}

long long calc(int l, int r, int m) {
  if (l > r)
    return 0;
  if (l == r) {
    return m - x[l];
  }
  if (x[l] == m)
    return calc(l+1, r, m);
  if (x[r] == m)
    return calc(l, r-1, m);
  int mid = get(l, r);
  return (m - x[mid]) + calc(l, mid-1, x[mid]) + calc(mid+1, r, x[mid]);
}

void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", x+i);
    sp[0][i] = i;
  }
  for (int i = 0; i + 1 < LG; ++i) {
    for (int j = 0; j + (1 << (i+1)) <= n; ++j) {
      int le = sp[i][j], ri = sp[i][j+(1 << i)];
      sp[i+1][j] = (x[le] > x[ri]) ? le : ri;
    }
  }
  long long ans = calc(0, n-1, m);
  printf("%lld\n", ans);
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    printf("Case #%d: ", tc);
    solve();
  }
  return 0;
}
