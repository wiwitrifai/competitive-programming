#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int le[N << 2], add[N << 2], ri[N << 2], lz[N << 2], n;
void build(int id = 1, int l = 0, int r = n) {
  lz[id] = 0;
  if (r-l < 2) {
    add[id] = 1;
    le[id] = ri[id]+1;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  ri[ir] = ri[id];
  build(ir, mid, r);
  ri[il] = le[ir];
  build(il, l, mid);
  le[id] = le[il];
  add[id] = add[il] + add[ir];
}

void upd_add(int id, int val) {
  lz[id] += val;
  le[id] += val;
  ri[id] += val;
}

void push(int id) {
  int il = id << 1, ir = il | 1;
  if (lz[id]) {
    upd_add(il, lz[id]);
    upd_add(ir, lz[id]);
    lz[id] = 0;
  }
  ri[ir] = ri[id];
  ri[il] = min(le[ir], ri[ir] + add[ir]);
}

void addt(int x, int y, int z, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    upd_add(id,  z);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id);
  addt(x, y, z, ir, mid, r);
  if (mid < y) {
    addt(x, y, z, il, l, mid);
  }
  else {
    ri[il] = le[ir];
    le[il] = min(ri[il] + add[il], le[il]);
  }
  le[id] = le[il];
}

void change(int x, int z, int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    add[id] += z;
    le[id] = ri[id] + add[id];
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id);
  if (x < mid) {
    change(x, z, il, l, mid);
  }
  else {
    change(x, z, ir, mid, r);
    ri[il] = le[ir];
    le[il] = min(ri[il] + add[il], le[il]);
  }
  le[id] = le[il];
  add[id] = add[il] + add[ir];
}

int get(int x, int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    return le[id];
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id);
  if (x < mid)
    return get(x, il, l, mid);
  else
    return get(x, ir, mid, r);
}

int x[N][2], y[N][2];

vector<int> ins[N], rem[N];
int tinggi[N], lebar[N];

int main() {
  int m;
  n = 3e5+1;
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < 2; ++ j)
      scanf("%d %d", x[i]+j, y[i]+j);
    ins[x[i][0]].push_back(y[i][0]);
    rem[x[i][1]].push_back(y[i][0]);
  }
  build();
  multiset<int> mset;
  for (int i = 0; i < n; ++i) {
    for (int x : ins[i]) {
      mset.insert(x);
    }
    for (int x : rem[i]) {
      auto it = mset.find(x);
      if (it != mset.end())
        mset.erase(it);
    }
    tinggi[i] = n-1;
    if (mset.size() > 0)
      tinggi[i] = *mset.begin();
    ins[i].clear();
    rem[i].clear();
  }
  mset.clear();
  for (int i = 0; i < m; ++i) {
    ins[y[i][0]].push_back(x[i][0]);
    rem[y[i][1]].push_back(x[i][0]);
  }
  for (int i = 0; i < n; ++i) {
    for (int x : ins[i]) {
      mset.insert(x);
    }
    for (int x : rem[i]) {
      auto it = mset.find(x);
      if (it != mset.end())
        mset.erase(it);
    }
    lebar[i] = n-1;
    if (mset.size() > 0)
      lebar[i] = *mset.begin();
    ins[i].clear();
    rem[i].clear();
  }
  for (int i = 0; i < n; ++i)
    rem[lebar[i]].push_back(i);
  cerr << get(0) << endl;
  for (int i = n-1; i >= 0; --i) {
    addt(tinggi[i]+1, n, 1);
    for (int x : rem[i]) {
      cerr << " " << x << " " << i << endl;
      change(x, -1);
    }
  }
  printf("%d\n", get(0));
  return 0;
}