#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> pos;
vector<int> ps, ans;

vector<int> a, h;
int n, m;
vector<int> bit;

int get(int x) {
  int ret = 0;
  for (++x; x < (int)bit.size(); x += x&-x)
    ret += bit[x];
  return ret;
}

void upd(int x, int v) {
  for (++x; x; x -= x&-x)
    bit[x] += v;
}

int main() {
  scanf("%d %d", &n, &m);
  a.resize(n);
  h.resize(m);
  pos.resize(m);
  ps.resize(n);
  bit.assign(n+5, 0);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    --a[i];
    ps[i] = pos[a[i]].size();
    pos[a[i]].push_back(i);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", &h[i]);
  }
  int q;
  scanf("%d", &q);
  ans.resize(q);
  vector<tuple<int, int, int>> queries;
  for (int i = 0; i < q; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l;
    queries.emplace_back(l, r, i);
  }
  sort(queries.begin(), queries.end());
  for (int i = 0; i < m; ++i) {
    upd(n, +1);
    pos[i].push_back(n);
  }
  for (int i = n-1, iq = q-1; i >= 0; --i) {
    int x = a[i];
    if (h[x]) {
      if (ps[i] + h[x] + 1 < (int)pos[x].size()) {
        upd(pos[x][ps[i]+h[x]+1], -1);
        upd(pos[x][ps[i]+h[x]], 1);
      }
      if (ps[i] + h[x] < (int)pos[x].size()) {
        upd(pos[x][ps[i]+h[x]], 1);
        if (ps[i] + h[x] - 1 >= 0)
          upd(pos[x][ps[i]+h[x]-1], -1);
      }
    }
    upd(i, +1);
    upd(pos[x][ps[i]+1], -1);
    while (iq >= 0 && get<0>(queries[iq]) == i) {
      int l, r, id;
      tie(l, r, id) = queries[iq];
      --iq;
      ans[id] = get(r) == m;
    }
  }
  for (int i = 0; i < q; ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
