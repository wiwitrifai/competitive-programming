#include <bits/stdc++.h>

using namespace std;

struct BIT {
  vector<int> sum;

  BIT(int _n) : sum(_n + 1, 0) {}

  void upd(int x, int v) {
    for (++x; x < (int)sum.size(); x += x&-x)
      sum[x] += v;
  }

  int get(int x) {
    int ret = 0;
    for (++x; x; x -= x&-x)
      ret += sum[x];
    return ret;
  }
};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> b(m + n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[m+i]);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", &b[m-1-i]);
  }
  long long ans = 0;
  BIT bit(n+m);
  for (int i = 0; i < n; ++i)
    bit.upd(m+i, +1);
  vector<int> pos(n+1);
  for (int i = 0; i < n; ++i) {
    pos[b[m+i]] = m+i;
  }
  for (int i = m-1; i >= 0; --i) {
    int cur = b[i];
    ans += bit.get(pos[cur]) - 1;
    bit.upd(pos[cur], -1);
    pos[cur] = i;
    bit.upd(pos[cur], +1);
  }
  ans *= 2LL;
  printf("%lld\n", ans);
  return 0;
}
