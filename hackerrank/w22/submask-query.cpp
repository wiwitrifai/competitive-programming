#include <bits/stdc++.h>

using namespace std;

const int N = 1<<16;
vector< pair<int, int> > xr[N];
pair<int, int> init[N];

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  int nn = 1<<n;
  int m = n/2, mm = 1<<m, mask = mm-1;
  int k = n-m, kk = 1<<k;
  for (int i = 0; i < nn; i++) {
    init[i] = {-1, 0};
    xr[i].push_back({-1, 0});
  }
  for (int ts = 0; ts < q; ts++) {
    int t, x, val;
    char s[20];
    scanf("%d", &t);
    if (t != 3)
      scanf("%d", &x);
    scanf("%s", s);
    val = 0;
    for (int i = 0; i < n; i++) {
      val = (val << 1) | (s[i] == '1');
    }
    if (t == 1) {
      int valk = val >> m, valm = val & mask;
      for (int i = 0; i < kk; i++) {
        if ((i & valk) ==  i)
          init[(i<<m) | valm] = {ts, x};
      }
    }
    else if (t == 2) {
      int valk = val >> m, valm = val & mask;
      for (int i = 0; i < kk; i++) {
        if ((i & valk) ==  i) {
          int now = (i<<m) | valm;
          xr[now].push_back({ts, xr[now].back().second ^ x});
        }
      }
    }
    else {
      int valk = (val & (-1 ^ mask)), valm = val & mask;
      int last = -1, ans = 0, valmm = val | mask;
      for (int i = val; i <= valmm; i = (i + 1) | valm) {
        if (last < init[i].first) {
          last = init[i].first;
          ans = init[i].second;
        }
      }
      for (int i = val; i <= valmm; i = (i + 1) | valm) {
        ans ^= xr[i].back().second;
        auto it = --lower_bound(xr[i].begin(), xr[i].end(), make_pair(last+1, -1));
        ans ^= it->second;
      }

      printf("%d\n", ans);
    }
  }


  return 0;
}