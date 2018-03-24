#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, LG = 20, inf = 1e9 + 7;

int n;
struct sp {
  int val[N];
  int a[LG][N];
  void build() {
    for (int i = 0; i < n; ++i)
      a[0][i] = i;
    for (int i = 0; i + 1 < LG; ++i) {
      for (int j = 0; j + (1 << (i+1)) <= n; ++j) {
        int le = a[i][j], ri = a[i][j+(1 << i)];
        a[i+1][j] = val[le] > val[ri] ? le : ri; 
      }
    }
  }

  int get(int l, int r) {
    int len = r-l;
    int lg = 31 - __builtin_clz(len);
    int le = a[lg][l], ri = a[lg][r-(1 << lg)];
    return val[le] > val[ri] ? le : ri;
  }
  int getv(int l, int r) {
    return val[get(l, r)];
  }
};

sp ma_x, mi_y, mi_x, ma_y;

int main() {
  int q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    mi_x.val[i] = -x;
    ma_x.val[i] = x;
    mi_y.val[i] = -y;
    ma_y.val[i] = y;
  }
  mi_x.build();
  ma_x.build();
  mi_y.build();
  ma_y.build();
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l;
    if (r-l <= 2)
      puts("0");
    else {
      vector<int> rem;
      rem.push_back(mi_x.get(l, r));
      rem.push_back(ma_x.get(l, r));
      rem.push_back(mi_y.get(l, r));
      rem.push_back(ma_y.get(l, r));
      long long ans = 4LL * inf * inf;
      for (int v : rem) {
        int vax = max((l < v) ? ma_x.getv(l, v) : -inf, (v+1 < r) ? ma_x.getv(v+1, r) : -inf);
        int vix = max((l < v) ? mi_x.getv(l, v) : -inf, (v+1 < r) ? mi_x.getv(v+1, r) : -inf);
        int vay = max((l < v) ? ma_y.getv(l, v) : -inf, (v+1 < r) ? ma_y.getv(v+1, r) : -inf);
        int viy = max((l < v) ? mi_y.getv(l, v) : -inf, (v+1 < r) ? mi_y.getv(v+1, r) : -inf);
        long long ma = max(0LL + vax + vix, 0LL + vay + viy);
        ans = min(ans, ma);
      }
      printf("%lld\n", ans);
    }
  }
  return 0;
}