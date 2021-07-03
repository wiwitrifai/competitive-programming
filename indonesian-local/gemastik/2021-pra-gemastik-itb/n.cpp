#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, inf = 1e9 + 7, MAGIC = sqrt(N);

int bit[N], cnt[N];

void upd(int x, int v) {
  for (++x; x < N; x += x&-x)
    bit[x] += v;
}

int get(int x) {
  int ret = 0;
  for (++x; x; x -= x &-x)
    ret += bit[x];
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    --a[i];
  }
  int q;
  scanf("%d", &q);
  vector<int> ans(q, 0), l(q), r(q), low(q), hig(q);
  for (int i = 0; i < q; ++i) {
    scanf("%d %d %d %d", &l[i], &r[i], &low[i], &hig[i]);
    --l[i];
    --low[i];
  }
  vector<int> ids(q);
  iota(ids.begin(), ids.end(), 0);
  auto update = [&](int x, int v) {
    upd(cnt[x], -1);
    cnt[x] += v;
    upd(cnt[x], +1);
  };
  sort(ids.begin(), ids.end(), [&](int lef, int rig) {
    int gl = l[lef] / MAGIC, gr = l[rig] / MAGIC;
    return make_pair(gl, r[lef]) < make_pair(gr, r[rig]);
  });
  int lef = 0, rig = 0;
  for (auto id : ids) {
    while (rig < r[id]) {
      update(a[rig], +1);
      ++rig;
    }
    while (lef > l[id]) {
      --lef;
      update(a[lef], +1);
    }
    while (rig > r[id]) {
      --rig;
      update(a[rig], -1);
    }
    while (lef < l[id]) {
      update(a[lef], -1);
      ++lef;
    }
    ans[id] = get(hig[id]) - get(low[id]);
  }
  for (int i = 0; i < q; ++i)
    printf("%d\n", ans[i]);
  return 0;
}
