#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5, M = 1505;

struct Entry {
  pair<int, int> a[2];
  Entry() {
    reset();
  }
  void reset() {
    a[0] = a[1] = {-1, -1};
  }
  void upd(pair<int, int> v) {
    if (v > a[0])
      a[1] = a[0], a[0] = v;
    else if (v > a[1])
      a[1] = v;
  }
  void combine(Entry oth) {
    upd(oth.a[0]);
    upd(oth.a[1]);
  }
};
Entry st[M << 2];
int n, m;
int xl[N], yl[N], xr[N], yr[N];

void build(int id = 1, int l = 0, int r = m) {
  st[id].reset();
  if (r-l < 2)
    return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}

void update(int x, int y, pair<int, int> v, int id = 1, int l = 0, int r = m) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    st[id].upd(v);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  update(x, y, v, il, l, mid);
  update(x, y, v, ir, mid, r);
}

Entry get(int x, int id = 1, int l = 0, int r = m) {
  if (r-l < 2)
    return st[id];
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  Entry res = st[id];
  if (x < mid)
    res.combine(get(x, il, l, mid));
  else
    res.combine(get(x, ir, mid, r));
  return res;
}

vector<int> events[M];
int add[M][M];
int hapus[N];

void solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i <= m; ++i)
    for (int j = 0; j <= m; ++j)
      add[i][j] = 0;
  build();
  for (int i = 0; i <= m; ++i)
    events[i].clear();
  for (int i = 0; i < n; ++i) {
    scanf("%d %d %d %d", xl+i, xr+i, yl+i, yr+i);
    --xl[i];
    --yl[i];
    ++add[xl[i]][yl[i]];
    --add[xr[i]][yl[i]];
    --add[xl[i]][yr[i]];
    ++add[xr[i]][yr[i]];
    events[xl[i]].push_back(i);
  }
  fill(hapus, hapus+n+1, 0);
  int tot = 0;
  vector<pair<int, int>> dua;
  for (int i = 0; i < m; ++i) {
    for (int v : events[i]) {
      update(yl[v], yr[v], {xr[v], v});
    }
    for (int j = 0; j < m; ++j) {
      add[i+1][j+1] -= add[i][j];
      add[i+1][j] += add[i][j];
      add[i][j+1] += add[i][j];
      tot += add[i][j] > 0;
      if (add[i][j] > 2 || add[i][j] == 0) continue;
      Entry res = get(j);
      if (add[i][j] == 1)
        hapus[res.a[0].second] += 1;
      else {
        if (res.a[0].second > res.a[1].second)
          swap(res.a[0], res.a[1]);
        dua.emplace_back(res.a[0].second, res.a[1].second);
      }
    }
  }
  int ans = 0;
  sort(dua.begin(), dua.end());
  for (int i = 0; i < (int)dua.size();) {
    int j = i;
    while (j < (int)dua.size() && dua[j] == dua[i]) ++j;
    ans = max(ans, hapus[dua[i].first] + hapus[dua[i].second] + j - i);
    i = j;
  }
  sort(hapus, hapus+n);
  ans = max(ans, hapus[n-1] + hapus[n-2]);
  ans = tot - ans;
  printf("%d\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
