#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct Entry {
  int mins, cnt;
  Entry(int mins = 0, int cnt = 0) : mins(mins), cnt(cnt) {}
  void add(int x) {
    mins += x;
  }
  Entry operator+(Entry other) {
    if (mins < other.mins)
      return *this;
    else if (mins > other.mins)
      return other;
    return Entry(mins, cnt + other.cnt);
  }
  void reset(int mins, int cnt) {
    this->mins = mins;
    this->cnt = cnt;
  }
};

Entry seg[N << 2];
int lazy[N << 2];
int n;

inline void push(int id, int il, int ir) {
  if (lazy[id] == 0) return;
  seg[il].add(lazy[id]);
  lazy[il] += lazy[id];
  seg[ir].add(lazy[id]);
  lazy[ir] += lazy[id];
  lazy[id] = 0;
}

void build(int id = 1, int l = 0, int r = n) {
  seg[id].reset(0, r-l);
  lazy[id] = 0;
  if (r-l < 2)
    return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}

void update(int x, int y, int z, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    seg[id].add(z);
    lazy[id] += z;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, il, ir);
  update(x, y, z, il, l, mid);
  update(x, y, z, ir, mid, r);
  seg[id] = seg[il] + seg[ir];
}

const int inf = 1e9 + 7;
Entry get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return Entry(inf, 0);
  if (x <= l && r <= y) {
    return seg[id];
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, il, ir);
  return get(x, y, il, l, mid) + get(x, y, ir, mid, r);
}

int a[N], lef[N];
const int LG = 30;
int last[LG];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", a+i);
    memset(last, -1, sizeof last);
    for (int i = 0; i < n; ++i) {
      lef[i] = 0;
      for (int j = 0; j < LG; ++j) {
        if (a[i] & (1 << j))
          lef[i] = max(lef[i], last[j]+1);
        else
          last[j] = i;
      }
    }
    fill(last, last+LG, n+1);
    vector<tuple<int, int, int, int> > events;
    for (int i = n-1; i >= 0; --i) {
      int rig = n-1;
      for (int j = 0; j < LG; ++j) {
        if (a[i] & (1 << j))
          rig = min(rig, last[j]-1);
        else
          last[j] = i;
      }
      events.emplace_back(i, 1, lef[i], i+1);
      events.emplace_back(rig+1, -1, lef[i], i+1);
    }
    sort(events.begin(), events.end());
    build();
    long long ans = 0;
    for (int i = 0, j = 0; i < n; ++i) {
      while (j < events.size() && get<0>(events[j]) <= i) {
        int l, r, v;
        tie(ignore, v, l, r) = events[j++];
        update(l, r, v);
      }
      Entry res = get(0, i);
      if (res.mins == 0)
        ans += res.cnt;
    }
    printf("%lld\n", ans);
  }
  return 0;
}