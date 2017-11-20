#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct segtree {
  segtree(int n) : n(n) {
    num.assign(n << 2, -1);
  }
  void upd(int at, int val) {
    upd(1, 0, n - 1, at, val);
  }
  void upd(int p, int l, int r, int at, int val) {
    if (l == r) {
      num[p] = val;
      return;
    }
    int mid = (l + r) >> 1;
    if (at <= mid) {
      upd(p + p, l, mid, at, val);
    } else {
      upd(p + p + 1, mid + 1, r, at, val);
    }
    num[p] = max(num[p + p], num[p + p + 1]);
  }
  int find(int l, int r) {
    return find(1, 0, n - 1, l, r);
  }
  int find(int p, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) return num[p];
    if (rr < l || r < ll) return -1;
    int mid = (l + r) >> 1;
    return max(find(p + p, l, mid, ll, rr), find(p + p + 1, mid + 1, r, ll, rr));
  }
  int n;
  vector<int> num, add;
};

int ans[N], ox[N], oy[N], cx[N], cy[N];

vector<int> px, py;

vector<pair<int, int>> add[2 * N], del[2 * N];

int idx(int u) {
  return lower_bound(px.begin(), px.end(), u) - px.begin();
}

int idy(int u) {
  return lower_bound(py.begin(), py.end(), u) - py.begin();
}

int rev(int u) {
  return (int) py.size() - u - 1;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<tuple<int, int, int>> a, b;
  for (int i = 0; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    a.emplace_back(u, v, i);
    px.push_back(u);
    py.push_back(v);
    ox[i] = u;
    oy[i] = v;
  }
  for (int i = 0; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    b.emplace_back(u, v, i);
    px.push_back(u);
    py.push_back(v);
    cx[i] = u;
    cy[i] = v;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  set<pair<int, int>> s, same;    // y id
  int j = n - 1, last = get<0>(a[n-1]);
  for (int i = n - 1; i >= 0; i--) {
    while (last < get<0>(a[i]) && !same.empty()) {
      auto it = same.begin();
      s.insert(*it);
      same.erase(it);
    }
    while (j >= 0 && get<0>(b[j]) > get<0>(a[i])) {
      int x, y, z;
      tie(x, y, z) = b[j];
      s.insert(make_pair(y, z));
      j--;
    }
    while (j >= 0 && get<0>(b[j]) == get<0>(a[i])) {
      int x, y, z;
      tie(x, y, z) = b[j];
      same.insert(make_pair(y, z));
      j--;
    }
    auto it = s.lower_bound(make_pair(get<1>(a[i])+1, -1)), it2 = same.lower_bound(make_pair(get<1>(a[i]), -1));
    if (it == s.end() && it2 == same.end()) {
      puts("syntax error");
      return 0;
    }
    else if (it == s.end()) {
      ans[get<2>(a[i])] = it2->second;
      same.erase(it2);
    }
    else if (it2 == same.end()) {
      ans[get<2>(a[i])] = it->second;
      s.erase(it);
    }
    else {
      if (*it < *it2) {
        ans[get<2>(a[i])] = it->second;
        s.erase(it);
      }
      else {
        ans[get<2>(a[i])] = it2->second;
        same.erase(it2);
      }
    }
    last = get<0>(a[i]);
  }
  sort(px.begin(), px.end());
  sort(py.begin(), py.end());
  px.resize(distance(px.begin(), unique(px.begin(), px.end())));
  py.resize(distance(py.begin(), unique(py.begin(), py.end())));
  
  for (int i = 0; i < n; i++) {
    int oox = idx(ox[i]);
    int ooy = idy(oy[i]);
    int ccx = idx(cx[ans[i]]);
    int ccy = idy(cy[ans[i]]);
    add[oox].emplace_back(ooy, ccy);
    del[ccx].emplace_back(ooy, ccy);
  }
  segtree seg(py.size());
  for (int i = 0; i < px.size(); i++) {
    for (auto it : add[i]) {
      if (seg.find(it.first, it.second) >= it.second) {
        puts("syntax error");
        return 0;
      }
      seg.upd(it.first, it.second);
    }
    for (auto it : del[i]) {
      seg.upd(it.first, -1);
    }
  }
  seg = segtree(py.size());
  for (int i = 0; i < px.size(); i++) {
    for (auto it : add[i]) {
      if (seg.find(rev(it.second), rev(it.first)) >= rev(it.first)) {
        puts("syntax error");
        return 0;
      }
      seg.upd(rev(it.second), rev(it.first));
    }
    for (auto it : del[i]) {
      seg.upd(rev(it.second), -1);
    }
  }
  
  for (int i = 0; i < n; i++) printf("%d\n", ans[i] + 1);
  return 0;
}
