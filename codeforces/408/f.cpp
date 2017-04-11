#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5, inf = 1e9 + 7;

int ma[N << 2], lz[N << 2], ma2[N << 2], n;
int vma[N];

void build1(int id = 1, int l = 0, int r = n) {
  ma[id] = inf;
  lz[id] = inf;
  if (r-l < 2)
    return;
  int mid = (l+r) >> 1, il = id << 1, ir = il | 1;
  build1(il, l, mid);
  build1(ir, mid, r);  
}
void shift(int id) {
  if (lz[id] < inf) {
    int il = id << 1, ir = il | 1;
    ma[il] = min(ma[il], lz[id]);
    lz[il] = min(lz[il], lz[id]);
    ma[ir] = min(ma[ir], lz[id]);
    lz[ir] = min(lz[ir], lz[id]);
    lz[id] = inf;
  }
}
int get1(int x, int id = 1, int l = 0, int r = n) {
  if (r-l < 2)
    return ma[id];
  shift(id);
  int mid = (l+r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    return get1(x, il, l, mid);
  else
    return get1(x, ir, mid, r);
}
void upd1(int x, int y, int val, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    ma[id] = min(ma[id], val);
    lz[id] = min(lz[id], val);
    return;
  }
  shift(id);
  int mid = (l+r) >> 1, il = id << 1, ir = il | 1;
  upd1(x, y, val, il, l, mid);
  upd1(x, y, val, ir, mid, r); 
  ma[id] = max(ma[il], ma[ir]);
}

void build2(int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    ma2[id] = vma[l];
    return;
  }
  int mid = (l+r) >> 1, il = id << 1, ir = il | 1;
  build2(il, l, mid);
  build2(ir, mid, r);  
  ma2[id] = max(ma2[il], ma2[ir]);
}
int get2(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return -inf;
  if (x <= l && r <= y) return ma2[id];
  int mid = (l+r) >> 1, il = id << 1, ir = il | 1;
  return max(get2(x, y, il, l, mid), get2(x, y, ir, mid, r));
}
void upd2(int x, int val, int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    ma2[id] = val;
    return;
  }
  int mid = (l+r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    upd2(x, val, il, l, mid);
  else
    upd2(x, val, ir, mid, r);
  ma2[id] = max(ma2[il], ma2[ir]);
}
int t[N], x[N], y[N], z[N];

int main() {
  int m;
  scanf("%d %d", &n, &m);
  fill(vma, vma+n, -1);
  build1();
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", t+i, x+i, y+i);
    x[i]--;
    if (t[i] == 1) {
      scanf("%d", z+i);
      upd1(x[i], y[i], z[i]);
    }
    else {
      if (vma[x[i]] == -1) {
        vma[x[i]] = get1(x[i]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (vma[i] == -1) vma[i] = get1(i);
  }
  build2();
  bool ok = 1;
  for (int i = 0; i < m; i++) {
    if (t[i] == 1) {
      int res = get2(x[i], y[i]);
      if (res != z[i]) {
        ok = 0;
        break;
      }
    }
    else
      upd2(x[i], y[i]);
  }
  if (!ok) {
    puts("NO");
    return 0;
  }
  puts("YES");
  map< int, int > mp;
  for (int i = 0; i < n; i++) {
    mp[vma[i]]++;
  }
  if (mp[inf] > 1) {
    for (int i = 0; i < n; i++) {
      if (vma[i] == inf) {
        if (--mp[inf] == 0)
          vma[i] = (1<<29)-1;
        else
          vma[i] = 1e9;
      }
    }
  }
  else {
    int all = 0;
    for (int i = 0; i < n; i++) {
      if (vma[i] == inf || vma[i] == 0) continue;
      if (mp[vma[i]] > 1) {
        int lg = 31-__builtin_clz(vma[i]);
        mp[vma[i]]--;
        vma[i] = (1<<lg)-1;
      }
      all |= vma[i];
    }
    int now = 0;
    for (int i = 29; i >= 0; i--) {
      if (all & (1<<i)) continue;
      if (now + (1<<i) > 1e9) continue;
      now |= 1<<i;
    }
    for (int i = 0; i < n; i++)
      if (vma[i] == inf)
        vma[i] = now;
  }
  for (int i = 0; i < n; i++) {
    if (i) printf(" ");
    printf("%d", vma[i]);
  }
  printf("\n");
  return 0;
}