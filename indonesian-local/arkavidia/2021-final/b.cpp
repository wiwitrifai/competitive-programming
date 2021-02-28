#include <bits/stdc++.h>

using namespace std;

const int inf = 2e9;

struct BIT {
  vector<int> bit;

  BIT(int _n) : bit(_n+1, -inf) {}

  int get(int x) {
    int ret = -inf;
    for (++x; x; x -= x&-x)
      ret = max(ret, bit[x]);
    return ret;
  }

  void upd(int x, int v) {
    for (++x; x < (int)bit.size(); x += x&-x) {
      bit[x] = max(bit[x], v);
    }
  }
};


int main() {
  int n, q;
  scanf("%d", &n);
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &x[i], &y[i]);
  }
  scanf("%d", &q);
  x.resize(n+q);
  y.resize(n+q);
  for (int i = 0; i < q; ++i) {
    scanf("%d %d", &x[n+i], &y[n+i]);
  }
  vector<int> ans(q);
  vector<int> dx = x, dy = y;
  sort(dx.begin(), dx.end());
  dx.erase(unique(dx.begin(), dx.end()), dx.end());
  BIT bit(dx.size());
  auto get_id = [&](int z) {
    return (int)(lower_bound(dx.begin(), dx.end(), z) - dx.begin());
  };
  vector<int> id(n+q);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int l, int r) {
    return y[l] != y[r] ? y[l] < y[r] : x[l] < x[r];
  });
  for (int z : id) {
    if (z < n) {
      bit.upd(get_id(x[z]), x[z] + y[z]);
    } else {
      int res = bit.get(get_id(x[z]));
      ans[z-n] = res <= -inf ? -1 : x[z] + y[z] - res;
    }
  }
  for (int i = 0; i < q; ++i)
    printf("%d\n", ans[i]);
  return 0;
}
