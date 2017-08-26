#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, H = 1e8 - 1;

const double PI = acos(-1);
int m;
int seg[N << 2];
void build(int id = 1, int l = 0, int r = m) {
  seg[id] = 0;
  if (r-l < 2)
    return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  seg[id] = max(seg[il], seg[ir]);  
}
void upd(int x, int val, int id = 1, int l = 0, int r = m) {
  if (r-l < 2) {
    seg[id] = val;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    upd(x, val, il, l, mid);
  else
    upd(x, val, ir, mid, r);
  seg[id] = max(seg[il], seg[ir]);  
}

int get(int x, int y, int id = 1, int l = 0, int r = m) {
  if (x >= r || l >= y) return 0;
  if (x <= l && r <= y) return seg[id];
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  return max(get(x, y, il, l, mid), get(x, y, ir, mid, r));
}


int a, b, c, d, n;
int x[N], y[N], id[N], tmp[N];
bool cmp(int l, int r) {
  return x[l] < x[r];
}

int getid(vector<int>&v, int a) {
  return lower_bound(v.begin(), v.end(), a) - v.begin();
}


int main() {
  scanf("%d %d %d %d", &a, &b, &c, &d);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d %d", x+i, y+i), id[i] = i;
  if (a > c) {
    swap(a, c);
    swap(b, d);
  }
  if (b > d) {
    b = H - b;
    d = H - d;
    for (int i = 0; i < n; i++)
      y[i] = H - y[i];
  }
  sort(id, id+n, cmp);
  for (int i = 0; i < n; i++)
    tmp[i] = x[id[i]];
  for (int i = 0; i < n; i++)
    x[i] = tmp[i];
  for (int i = 0; i < n; i++)
    tmp[i] = y[id[i]];
  for (int i = 0; i < n; i++)
    y[i] = tmp[i];
  vector<int> vx, vy;
  vx.push_back(a);
  vx.push_back(c);
  vy.push_back(b);
  vy.push_back(d);
  for (int i = 0; i < n; i++) {
    vx.push_back(x[i]);
    vy.push_back(y[i]);
  }
  int dx = c-a, dy = d-b;
  double ans = (double)100.0 * ((c-a) + (d-b));
  sort(vx.begin(), vx.end());
  vx.erase(unique(vx.begin(), vx.end()), vx.end());
  sort(vy.begin(), vy.end());
  vy.erase(unique(vy.begin(), vy.end()), vy.end());
  a = getid(vx, a);
  b = getid(vy, b);
  c = getid(vx, c);
  d = getid(vy, d);
  for (int i = 0; i < n; i++) {
    x[i] = getid(vx, x[i]);
    y[i] = getid(vy, y[i]);
  }
  m = vy.size();
  int bst = 0;
  build();
  for (int i = 0; i < n; i++) {
    if (a <= x[i] && x[i] <= c && b <= y[i] && y[i] <= d) {
      int val = get(0, y[i]+1) + 1;
      bst = max(val, bst);
      upd(y[i], val);
    } 
  }
  if (bst == min(dx, dy)+1)
    ans += PI * 5;
  ans += bst * (PI * 5 - 20);
  printf("%.20lf\n", ans);
  return 0;
}