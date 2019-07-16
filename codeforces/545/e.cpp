// WA
#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;
const long long inf = 4e18 + 8;

long long mi[N << 2];
long long b[N << 2], s[N << 2];
long long sum[N], a[N];
int n;

void build(int id = 1, int l = 0, int r = n) {
  b[id] = s[id] = mi[id] = 0;
  if (r-l < 2)
    return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}

void upd(int id, long long bb, long long ss) {
  mi[id] += bb;
  b[id] += bb;
  s[id] += ss;
}

void push(int id, int l, int r) {
  if (b[id] == 0 && s[id] == 0)
    return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  upd(il, b[id], s[id]);
  upd(ir, b[id] + 1LL * (sum[mid]-sum[l]) * s[id], s[id]);
  b[id] = s[id] = 0;
}

void update(int x, int y, long long bb, long long ss, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    upd(id, bb + 1LL * (sum[l] - sum[x]) * ss, ss);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, l, r);
  cerr << id << " bef " << mi[il] << " " << mi[ir] << " = " << min(mi[il], mi[ir]);
  update(x, y, bb, ss, il, l, mid);
  update(x, y, bb, ss, ir, mid, r);
  mi[id] = min(mi[il], mi[ir]);
  cerr << id << " aft =  " << mi[id] << endl;
}

pair<long long, long long> get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return make_pair(inf, inf);
  if (r-l < 2) {
    // cerr << l << " cek " << mi[id] << endl;
    return make_pair(mi[id], sum[l]);
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, l, r);
  if (x <= l && r <= y) {
    return mi[il] <= mi[ir] ? get(x, y, il, l, mid) : get(x, y, ir, mid, r);  
  }
  return min(get(x, y, il, l, mid), get(x, y, ir, mid, r));
}

int ty[N];
long long x[N], y[N];

int main() {
  int awal, m;
  scanf("%d %d", &awal, &m);
  deque<long long> dq;
  dq.push_back(awal);
  awal = 0;
  for (int i = 0; i < m; ++i) {
    scanf("%d %lld", ty+i, x+i);
    if (ty[i] == 1) {
      dq.push_front(x[i]);
      ++awal;
    }
    else if (ty[i] == 2) {
      dq.push_back(x[i]);
    }
    else if (ty[i] == 3) {
      scanf("%lld", y+i);
    }
  }
  n = 0;
  long long of = 0;
  while (!dq.empty()) {
    sum[n] = of;
    a[n++] = dq.front();
    of += dq.front();
    dq.pop_front();
  }
  sum[n] = of;
  build();
  int lef = awal, rig = awal + 1;
  for (int i = 0; i < m; ++i) {
    if (ty[i] == 1)
      --lef;
    else if (ty[i] == 2)
      ++rig;
    else {
      update(lef, rig, x[i], y[i]);
    }
    assert(lef >= 0 && rig <= n);
    auto res = get(lef, rig);
    assert(res.second <= sum[n]);
    assert(res.first < inf);
    printf("%lld %lld\n", res.second + 1 - sum[lef], res.first);
  }
  return 0;
}