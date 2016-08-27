#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
int cnt[N], grundy[N], a[N], b[N];
bool full[N<<2];


void build(int id = 1, int l = 0, int r = n) {
  full[id] = false;
  if(r-l < 2) {
    cnt[l] = 0;
    return;
  }
  int mid = (l+r)>>1, il = id<<1, ir = il|1;
  build(il, l, mid);
  build(ir, mid, r);
}

void upd(int x, int v, int id = 1, int l = 0, int r = n) {
  if(r-l < 2) {
    cnt[x] += v;
    full[id] = cnt[l] > 0;
    return;
  }
  int mid = (l+r)>>1, il = id<<1, ir = il|1;
  if(x < mid)
    upd(x, v, il, l, mid);
  else
    upd(x, v, ir, mid, r);
  full[id] = full[il] && full[ir];
}

int get(int id = 1, int l = 0, int r = n) {
  if(full[id])
    return r;
  if(r-l<2)
    return l;
  int mid = (l+r)>>1, il = id<<1, ir = il|1;
  if(full[il])
    return get(ir, mid, r);
  else
    return get(il, l, mid);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i<n; i++) {
      scanf("%d%d", a+i, b+i);
      a[i]--; b[i]--;
    }
    build();
    grundy[0] = 0;
    int l = 0, r = 0;
    for(int i= 1; i<n; i++) {
      while(r <= b[i])
        upd(grundy[r++], +1);
      while(l < a[i])
        upd(grundy[l++], -1);
      // cerr << l << " " << r << endl;
      grundy[i] = get();
      // cerr << i << " " << grundy[i] << endl;
    }
    int ans = 0;
    for(int i = 0; i<m; i++) {
      int x;
      scanf("%d", &x);
      x--;
      ans ^= grundy[x];
    }
    puts(ans ? "Marko" : "Ferde");
  }

  return 0;
}