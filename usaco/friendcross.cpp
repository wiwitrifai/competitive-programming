#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

struct fen {
  int * bit, n;
  fen(int n) : n(n) {
    bit = new int[n + 1];
    for (int i = 0; i <= n; i++)
      bit[i] = 0;
  }
  void upd(int x, int v) {
    for (; x; x -= x&(-x))
      bit[x] += v;
  }
  int get(int x) {
    int ret = 0;
    for (; x <= n; x += x&(-x))
      ret += bit[x];
    return ret;
  }
};
int n, k, a[N], b[N];
int to[N], to2[N];
fen * bit[N];
vector< int > y[N];
void upd(int x, int v, int add) {
  for (; x <= n; x += x&(-x)) {
    int id = lower_bound(y[x].begin(), y[x].end(), v) - y[x].begin() + 1;
    assert(id <= y[x].size() && y[x][id-1] == v);
    bit[x]->upd(id, add);
  }
}
int get(int x, int v) {
  int ret = 0;
  for (; x; x -= x&(-x)) {
    int id = upper_bound(y[x].begin(), y[x].end(), v) - y[x].begin() + 1;
    if (id <= y[x].size())
      ret += bit[x]->get(id);
  }
  return ret;
}


int main() {
#ifndef LOCAL
  freopen("friendcross.in", "r", stdin);
  freopen("friendcross.out", "w", stdout);
#endif
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a+i);
    to[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", b+i);
    to2[b[i]] = i;
    int x = i;
    for (; x <= n; x += x&(-x))
      y[x].push_back(to[b[i]]);
  }
  for (int i = 1; i <= n; i++) {
    sort(y[i].begin(), y[i].end());
    bit[i] = new fen(y[i].size());
    assert(bit[i]->get(1) == 0);
  }
  for (int i = k+2; i <= n; i++) {
    upd(to2[i], to[i], +1);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += get(to2[i], to[i]);
    if (i + k + 1 <= n)
      upd(to2[i + k + 1], to[i + k + 1], -1);
    if (i - k >= 1)
      upd(to2[i - k], to[i - k], +1);
  }
  printf("%lld\n", ans);
  return 0;
}