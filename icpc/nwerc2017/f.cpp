#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, A = 1e7;

int last[A], le[N], ri[N], lp[A], a[N];
int pos[N << 2];
int n;

void build(int id = 1, int l = 0, int r = n) {
  pos[id] = n;
  if (r-l < 2)
    return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}

void update(int x, int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    pos[id] = x;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    update(x, il, l, mid);
  else
    update(x, ir, mid, r);
  pos[id] = ri[pos[il]] > ri[pos[ir]] ? pos[il] : pos[ir];
}

int get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return n;
  if (x <= l && r <= y)
    return pos[id];
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  int ll = get(x, y, il, l, mid), rr = get(x, y, ir, mid, r);
  return ri[ll] > ri[rr] ? ll : rr;
}

int ans[N];
vector<pair<int, int> > ev;
int it = 0;
bool dfs(int l, int r, int par = -1) {
  if (r < l) return true;
  while (it < ev.size() && ev[it].first <= l) {
    update(ev[it++].second);
  }
  int v = get(l, r+1);
  if (v == n || ri[v] < r)
    return false;
  ans[v] = par+1;
  bool res = dfs(l, v-1, v);
  if (!res)
    return false;
  return dfs(v+1, r, v);
}

int main() {
  scanf("%d", &n);
  for (int i = 2; i < A; ++i) {
    if (lp[i]) continue;
    for (int j = i; j < A; j += i)  {
      if (lp[j] == 0)
        lp[j] = i;
    }
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  memset(last, -1, sizeof last);
  for (int i = 0; i < n; ++i) {
    int now = a[i];
    le[i] = 0;
    while (now > 1) {
      int p = lp[now];
      while ((now % p) == 0) now /= p;
      int id = last[p];
      if (id != -1) {
        le[i] = max(le[i], id+1);
      }
      last[p] = i;
    }
  }
  memset(last, -1, sizeof last);
  for (int i = n-1; i >= 0; --i) {
    int now = a[i];
    ri[i] = n-1;
    while (now > 1) {
      int p = lp[now];
      while ((now % p) == 0) now /= p;
      int id = last[p];
      if (id != -1) {
        ri[i] = min(ri[i], id-1);
      }
      last[p] = i;
    }
    ev.emplace_back(le[i], i);
  }
  sort(ev.begin(), ev.end());
  build();
  bool res = dfs(0, n-1);
  if (res) {
    for (int i = 0; i < n; ++i) {
      printf("%d%c", ans[i], i == n-1 ? '\n' : ' ');
    }
  }
  else
    puts("impossible");
  return 0;
}