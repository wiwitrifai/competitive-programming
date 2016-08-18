#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, m, t[N], q[N], p[N], b[N];
pair< int, int > x[N];

// seg_tree
int y[N<<2];
set< pair<int, int > > que;
set< int > exe;

void build(int id = 1, int l = 0, int r = n) {
  if(r-l < 2) {
    y[id] = x[l].first + t[x[l].second];
    auto it = que.lower_bound({x[l].first, -1});
    auto nx = it;
    for(; nx != que.end() && nx->first <= y[id]; nx++) {
      exe.insert(nx->second);
    }
    que.erase(it, nx);
    return;
  }
  int mid = (l+r)>>1, il = id<<1, ir = il|1;
  build(il, l, mid);
  build(ir, mid, r);
  y[id] = max(y[il], y[ir]);
}
void update(int pos, int val, int id = 1, int l = 0, int r = n) {
  if(r-l < 2) {
    t[x[l].second] += val;
    y[id] += val;
    q[x[l].second]++;
    auto it = que.lower_bound({x[l].first, -1});
    auto nx = it;
    for(; nx != que.end() && nx->first <= y[id]; nx++) {
      exe.insert(nx->second);
    }
    que.erase(it, nx);
    return;
  }
  int mid = (l+r)>>1, il = id<<1, ir = il|1;
  if(pos < mid)
    update(pos, val, il, l, mid);
  else
    update(pos, val, ir, mid, r);
  y[id] = max(y[il], y[ir]);
}

int get(int pos, int id = 1, int l = 0, int r = n) {
  if(r-l < 2) {
 
    if(pos <= y[id] && x[l].first <= pos)
      return l;
    else
      return -1;
  }
  int mid = (l+r)>>1, il = id<<1, ir = il|1;
 
  if(y[il] >= pos)
    return get(pos, il, l, mid);
  else
    if(y[ir] >= pos && pos >= x[mid].first)
      return get(pos, ir, mid, r);
    else
      return -1;
}

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i<n; i++) {
    int val;
    scanf("%d%d", &val, t+i);
    x[i] = {val, i};
  }
  sort(x, x+n);
  for(int i = 0; i<m; i++) {
    scanf("%d%d", &p[i], &b[i]);
    que.insert({p[i], i});
  }
  build();
  while(!exe.empty()) {
    auto it = exe.begin();
    int v = *it;
    exe.erase(it);
 
    int id = get(p[v]);
 
    if(id >= 0)
      update(id, b[v]);
    else
      break;
  }
  for(int i = 0; i<n; i++)
    printf("%d %d\n", q[i], t[i]);
  return 0;
}