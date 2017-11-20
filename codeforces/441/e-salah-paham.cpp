#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;

struct seg_tree {
  long long ma[N << 2], lz[N << 2];
  int n;
  seg_tree() {
  }
  void build(int id, int l, int r) {
    ma[id] = inf;
    lz[id] = 0;
    if (r-l < 2)
      return;
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    build(il, l, mid);
    build(ir, mid, r); 
  }
  void push(int id) {
    if (lz[id] == 0) return;
    int il = id << 1,ir = il | 1;
    ma[il] += lz[id];
    lz[il] += lz[id];
    ma[ir] += lz[id];
    lz[ir] += lz[id];
    lz[id] = 0;
  }
  void update(int x, long long v) {
    upd(x, v, 1, 0, n);
  }
  void upd(int x, long long v, int id, int l, int r) {
    if (r-l < 2) {
      ma[id] = min(ma[id], v);
      return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    push(id);
    if (x < mid)
      upd(x, v, il, l, mid);
    else
      upd(x, v, ir, mid, r);
    ma[id] = min(ma[il], ma[ir]);
  }
  long long get(int x, int y) {
    return get(x, y, 1, 0, n);
  }
  long long get(int x, int y, int id, int l, int r) {
    if (x >= r || l >= y) return inf;
    if (x <= l && r <= y) return ma[id];
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    push(id);
    return min(get(x, y, il, l, mid), get(x, y, ir, mid, r));
  }
};
vector<int> vx;
int id(int x) {
  return lower_bound(vx.begin(), vx.end(), x) - vx.begin();
}

int x[N];
seg_tree incc, decc, flat;

int main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  vx.push_back(a);
  vx.push_back(b);
  for (int i = 0; i < n; i++)
    scanf("%d", x+i), vx.push_back(x[i]);
  sort(vx.begin(), vx.end());
  vx.erase(unique(vx.begin(), vx.end()), vx.end());
  incc.n = decc.n = flat.n = vx.size();
  incc.build(1, 0, vx.size());
  flat.build(1, 0, vx.size());
  decc.build(1, 0, vx.size());
  incc.update(id(a), abs(x[0] - b) + a);
  flat.update(id(a), abs(x[0] - b));
  decc.update(id(a), abs(x[0] - b) - a);
  incc.update(id(b), abs(x[0] - a) + b);
  flat.update(id(b), abs(x[0] - a));
  decc.update(id(b), abs(x[0] - a) - b);
  cerr << flat.get(0, vx.size()) << endl;
  for (int i = 1; i < n; i++) {
    int cur = id(x[i]);
    long long now = min(decc.get(0, cur) + x[i], incc.get(cur, vx.size()) - x[i]);
    incc.lz[1] += abs(x[i-1]-x[i]);
    flat.lz[1] += abs(x[i-1]-x[i]);
    decc.lz[1] += abs(x[i-1]-x[i]);
    int bef = id(x[i-1]);
    incc.update(bef, now + x[i-1]);
    flat.update(bef, now);
    decc.update(bef, now - x[i-1]);
  }
  cout << flat.get(0, vx.size()) << endl;
  return 0;
}