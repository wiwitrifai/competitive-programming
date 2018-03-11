// by wiwit
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

pair<int, int> p[N];
int t[N];
vector<int> vx;
set<pair<int, int> > st[N << 2];

bool cek(int id, int x, int y) {
  int dx = x - p[id].first;
  int dy = y - p[id].second;
  return 1LL * dx * dx + 1LL * dy * dy < 1LL * p[id].second * p[id].second;
}

void add(int x, int y, pair<int, int> val, int id = 1, int l = 0, int r = vx.size()) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    st[id].insert(val);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  add(x, y, val, il, l, mid);
  add(x, y, val, ir, mid, r);
}
void remove(int x, int y, pair<int, int> val, int id = 1, int l = 0, int r = vx.size()) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    st[id].erase(val);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  remove(x, y, val, il, l, mid);
  remove(x, y, val, ir, mid, r);
}
int get(int x, int y, int id = 1, int l = 0, int r = vx.size()) {
  auto it = st[id].lower_bound(make_pair(y, -1));
  if (it != st[id].end()) {
    if (cek(it->second, x, y))
      return it->second;
  }
  if (it != st[id].begin()) {
    --it;
    if (cek(it->second, x, y))
      return it->second;
  }
  if (r-l < 2)
    return -1;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < vx[mid])
    return get(x, y, il, l, mid);
  else
    return get(x, y, ir, mid, r);
}

int main() {
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int x, y;
    scanf("%d %d %d", t+i, &x, &y);
    p[i] = {x, y};
    if (t[i] == 2)
      vx.push_back(x);
  }
  sort(vx.begin(), vx.end());
  vx.erase(unique(vx.begin(), vx.end()), vx.end());
  for (int i = 0; i < q; ++i) {
    if (t[i] == 1) {
      int l = p[i].first - p[i].second+1, r = p[i].first + p[i].second;
      l = lower_bound(vx.begin(), vx.end(), l) - vx.begin();
      r = lower_bound(vx.begin(), vx.end(), r) - vx.begin();
      if (l < r)
        add(l, r, make_pair(p[i].second, i));
    }
    else {
      int res = get(p[i].first, p[i].second);
      if (res < 0)
        puts("-1");
      else {
        int l = p[res].first - p[res].second+1, r = p[res].first + p[res].second;
        l = lower_bound(vx.begin(), vx.end(), l) - vx.begin();
        r = lower_bound(vx.begin(), vx.end(), r) - vx.begin();
        remove(l, r, make_pair(p[res].second, res));
        printf("%d\n", res+1);
      }
    }
  }
  return 0;
}