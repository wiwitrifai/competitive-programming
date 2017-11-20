#include <bits/stdc++.h>

using namespace std;

const int N = 2017;

int n, m, k;
int x[N], y[N];

struct seg_tree {
  int lz[N << 2], mn[N << 2], le[N << 2];
  void build(int id, int l, int r) {
    lz[id] = mn[id] = 0;
    le[id] = l;
    if (r-l < 2)
      return;
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    build(il, l, mid);
    build(ir, mid, r);
  }

  void push(int id) {
    if (!lz[id]) return;
    int il = id << 1, ir = il | 1;
    mn[il] += lz[id];
    lz[il] += lz[id];
    mn[ir] += lz[id];
    lz[ir] += lz[id];
    lz[id] = 0;
  }

  void upd(int x, int y, int val, int id, int l, int r) {
    if (x >= r || l >= y) return;
    if (x <= l && r <= y) {
      mn[id] += val;
      lz[id] += val;
      return;
    }
    push(id);
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    upd(x, y, val, il, l, mid);
    upd(x, y, val, ir, mid, r); 
    mn[id] = min(mn[il], mn[ir]);
    if (mn[id] == mn[il])
      le[id] = le[il];
    else
      le[id] = le[ir];
  }
};

seg_tree st;

pair<int, int> lineSweep(vector<pair<int, pair<int, int> > > &ev, int ns) {
  sort(ev.begin(), ev.end());
  st.build(1, 0, ns);
  int xm = n+1, ym = ns;
  for (int i = 0; i < ev.size(); ) {
    int vx = ev[i].first;
    if (vx > n) break;
    while (i < ev.size() && ev[i].first == vx) {
      int lo = ev[i].second.first, hi = ev[i].second.second;
      int add = 1;
      if (lo > hi)
        swap(lo, hi), add = -1;
      st.upd(lo, hi, add, 1, 0, ns);
      i++;
    }
    if (st.mn[1] == 0) {
      xm = min(xm, vx);
      ym = min(ym, st.le[1]);
    }
  }
  return make_pair(xm, ym);
}


bool can(int t) {
  vector< int > vy;
  vy.push_back(1);
  vy.push_back(m+1);
  for (int i = 0; i < k; i++) {
    vy.push_back(max(1, y[i]-t));
    vy.push_back(min(m+1, y[i]+t+1));
  }
  sort(vy.begin(), vy.end());
  vy.erase(unique(vy.begin(), vy.end()), vy.end());
  for (int x : vy) {
    vy.push_back(min(x + 2 * t + 1, m+1));
  }
  sort(vy.begin(), vy.end());
  vy.erase(unique(vy.begin(), vy.end()), vy.end());
  vector<pair<int, pair<int, int > > > ev;
  ev.push_back({1, {0,0}});
  ev.push_back({n+1, {0,0}});
  for (int i = 0; i < k; i++) {
    int lo = max(y[i]-t, 1), hi = min(m+1, y[i]+t+1);
    lo = lower_bound(vy.begin(), vy.end(), lo) - vy.begin();
    hi = lower_bound(vy.begin(), vy.end(), hi) - vy.begin();
    assert(lo < hi);
    ev.push_back({max(x[i]-t, 1), {lo, hi}});
    ev.push_back({min(x[i]+t+1, n+1), {hi, lo}});
  }
  int ns = (int)vy.size() - 1;
  pair<int, int > res = lineSweep(ev, ns);
  int xm = res.first, ym = res.second;
  if (xm > n) return true;
  int lo = ym, hi = lower_bound(vy.begin(), vy.end(), min(vy[ym] + 2*t + 1, m +1)) - vy.begin();
  ev.push_back({max(xm, 1), {lo, hi}});
  ev.push_back({min(xm + 2 * t, n) + 1, {hi, lo}});
  return lineSweep(ev, ns).first > n;
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < k; i++) {
    scanf("%d %d", x+i, y+i);
  }
  int ans = max(n, m)/2;
  int le = 0, ri = ans;
  while (le < ri) {
    int mid = (le + ri) / 2;
    if (can(mid))
      ri = mid;
    else
      le = mid + 1;
  }
  printf("%d\n", le);
  return 0;
}