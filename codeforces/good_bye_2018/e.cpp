#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int ma[N << 2], lz[N << 2];

inline void upd(int id, int v) {
  ma[id] += v;
  // mi[id] += v;
  lz[id] += v;
}

inline void push(int id) {
  if (lz[id] == 0) return;
  int il = id << 1, ir = il | 1;
  upd(il, lz[id]);
  upd(ir, lz[id]);
  lz[id] = 0;
}

int a[N], b[N], n;

inline void combine(int id, int il, int ir) {
  ma[id] = max(ma[il], ma[ir]);
  // mi[id] = min(mi[il], mi[ir]);
}

inline void build(int id = 1, int l = 0, int r = n) {
  lz[id] = 0;
  if (r-l < 2) {
    ma[id] = a[l];
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  combine(id, il, ir);
}

inline void update(int x, int y, int v, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    upd(id, v);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id);
  update(x, y, v, il, l, mid);
  update(x, y, v, ir, mid, r);
  combine(id, il, ir);
}

inline int get(int x, int id = 1, int l = 0, int r = n) {
  if (r-l < 2)
    return ma[id];
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id);
  return x < mid ? get(x, il, l, mid) : get(x, ir, mid, r);
}

inline int get_low(int v, int id = 1, int l = 0, int r = n) {
  if (ma[id] < v)
    return r;
  if (r-l < 2)
    return ma[id] >= v ? l : r;
  // if (mi[id] >= v)
  //   return l;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id);
  if (ma[il] >= v)
    return get_low(v, il, l, mid);
  return get_low(v, ir, mid, r);
}

inline int solve_min() {
  for (int i = 0; i < n; ++i)
    a[i] = b[i];
  sort(a, a+n);
  if (a[0] < 0)
    return -1;
  build();
  int ans = 0;
  for (int i = n-1; i >= 0; --i) {
    int v = get(i);
    int rem = min(v, i);
    int vl = get(i-rem);
    if (vl == 0) {
      int to = min(get_low(1), i);
      rem = i - to;
      vl = get(i-rem);
    }
    v -= rem;
    if (v > 1)
      return -1;
    int le = get_low(vl), ri = min(get_low(vl+1), i);
    update(ri, i, -1);
    rem -= (i - ri);
    if (le + rem > ri)
      return -1;
    update(le, le+rem, -1);
    ans += v;
  }
  return ans;
}

inline int solve_max() {
  for (int i = 0; i < n; ++i)
    a[i] = b[i];
  sort(a, a+n);
  if (a[0] < 0)
    return -1;
  build();
  int ans = 0;
  for (int i = n-1; i >= 0; --i) {
    int v = get(i);
    int rem = min(max(v-1, 0), i);
    int vl = get(i-rem);
    if (vl == 0) {
      int to = min(get_low(1), i);
      rem = i - to;
      vl = get(i-rem);
    }
    v -= rem;
    int le = get_low(vl), ri = min(get_low(vl+1), i);
    update(ri, i, -1);
    rem -= (i - ri);
    if (le + rem > ri)
      return -1;
    update(le, le+rem, -1);
    if (v > 1) {
      int butuh = v-1;
      if (ans < butuh)
        return -1;
      ans -= butuh;
      v -= butuh;
    }
    ans += v;
  }
  return ans;
}

inline int solve(int k) {
  for (int i = 0; i < n; ++i)
    a[i] = b[i];
  for (int i = 0; i < k; ++i)
    --a[n-1-i];
  sort(a, a+n);
  if (a[0] < 0)
    return -1;
  build();
  int ans = 0;
  for (int i = n-1; i >= 0; --i) {
    int v = get(i);
    int rem = v;
    if (rem > i)
      return -1;
    int vl = get(i-rem);
    if (vl == 0 && v > 0) {
      return -1;
    }
    int le = get_low(vl), ri = min(get_low(vl+1), i);
    update(ri, i, -1);
    rem -= i - ri;
    if (le + rem > ri)
      return -1;
    update(le, le+rem, -1);
  }
  return ans;
}


int main() {
  scanf("%d", &n);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    b[i] = a[i];
    sum += a[i] & 1;
  }
  sort(b, b+n);
  int le = solve_min(), ri = n;
  if (le < 0) {
    puts("-1");
    return 0;
  }
  int v = sum & 1;
  int lo = le / 2, hi = (n-v)/2;

  while (lo < hi) {
    int mid = (lo + hi + 1) >> 1;
    int k = mid * 2 + v;
    if (solve(k) < 0)
      hi = mid-1;
    else
      lo = mid;
  }
  ri = lo * 2 + v;
  // ri = solve_max();
  if (ri < le) {
    puts("-1");
    return 0;
  }
  for (int i = le; i <= ri; i += 2)
    printf("%d ", i);
  printf("\n");
  return 0;
}