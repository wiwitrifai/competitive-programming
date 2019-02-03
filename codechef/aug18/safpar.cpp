#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5, mod = 1e9 + 7, LG = 21;

int sum[N << 2], add[N << 2];
int n;

void build(int id = 1, int l = 0, int r = n) {
  sum[id] = add[id] = 0;
  if (r-l < 2)
    return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}

void upd(int id, int l, int r, int v) {
  sum[id] = (sum[id] + 1LL * (r - l) * v) % mod;
  add[id] += v;
  if (add[id] >= mod)
    add[id] -= mod;
}

void pushdown(int id, int l, int r) {
  if (add[id] == 0) return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  upd(il, l, mid, add[id]);
  upd(ir, mid, r, add[id]);
  add[id] = 0;
}

void update(int x, int y, int v, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    upd(id, l, r, v);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  pushdown(id, l, r);
  update(x, y, v, il, l, mid);
  update(x, y, v, ir, mid, r);
  sum[id] = sum[il] + sum[ir];
  if (sum[id] >= mod) sum[id] -= mod;
}

int get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return 0;
  if (x <= l && r <= y) return sum[id];
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  pushdown(id, l, r);
  int ret = get(x, y, il, l, mid) + get(x, y, ir, mid, r);
  if (ret >= mod) ret -= mod;
  return ret;
}

int le[N], ri[N], a[N], sp[LG][N];

int mini(int l, int r) {
  if (l > r) return mod;
  int len = r-l+1;
  int lg = 31-__builtin_clz(len);
  return min(sp[lg][l], sp[lg][r-(1<<lg)+1]);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i), sp[0][i] = a[i];
  for (int i = 0; i+1 < LG; ++i) {
    for (int j = 0; j + (1 << (i+1)) <= n; ++j) {
      sp[i+1][j] = min(sp[i][j], sp[i][j+(1<<i)]);
    }
  }
  stack<int> st;
  for (int i = n-1; i >= 0; --i) {
    while (!st.empty() && a[st.top()] < a[i]) st.pop();
    ri[i] = st.empty() ? n-1 : st.top() - 1;
    st.push(i);
  }
  while (!st.empty()) st.pop();
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && a[st.top()] <= a[i]) st.pop();
    le[i] = st.empty() ? 0 : st.top() + 1;
    st.push(i);
  }
  ++n;
  build();
  update(0, 1, 1);
  for (int i = 0; i < n-1; ++i) {
    if (ri[i] - i < i - le[i]) {
      for (int j = i; j <= ri[i]; ++j) {
        int from = max(le[i], j-a[i]+1), to = i;
        int lo = from, hi = to;
        while (lo < hi) {
          int mid = (lo + hi+1) >> 1;
          if (mini(mid, j) <= j-mid+1)
            lo = mid;
          else
            hi = mid-1;
        }
        if (lo > hi || mini(lo, j) > j-lo+1) continue;
        to = lo;
        int v = get(from, to+1);
        v %= mod;
        if (v < 0) v += mod;
        update(j+1, j+2, v);
      }
    }
    else {
      for (int j = le[i]; j <= i; ++j) {
        int from = i, to = min(ri[i], j+a[i]-1);
        int lo = from, hi = to;
        while (lo < hi) {
          int mid = (lo + hi) >> 1;
          if (mini(j, mid) <= mid-j+1)
            hi = mid;
          else
            lo = mid+1;
        }
        if (lo > hi || mini(j, lo) > lo-j+1) continue;
        from = hi;
        int v = get(j, j+1);
        v %= mod;
        if (v < 0) v += mod;
        update(from+1, to+2, v);
      }
    }
  }
  int ans = get(n-1, n);
  ans %= mod;
  if (ans < 0) ans += mod;
  printf("%d\n", ans);
  return 0;
}