#include <bits/stdc++.h>

using namespace std;

const int N =2e5 + 5;

int n, k;
pair< int, int > ts[N], bb[N];
int mi[N<<2], ans[N];
pair< int, int > st[N];

bool cmp(pair<int, int> a, pair< int, int> b) {
  if(a.first == b.first)
    return a.second < b.second;
  return a.first > b.first;
}

void build(int id = 1, int l = 0, int r = n) {
  if(r-l < 2) {
    mi[id] = ts[l].second;
    return;
  }
  int mid = (l + r) >> 1, il = id<<1, ir = il|1;
  build(il, l, mid);
  build(ir, mid, r);
  mi[id] = min(mi[il], mi[ir]);
}
int get(int x, int y, int id =1, int l = 0, int r = n) {
  // cerr << x << " " << y << " " << id << " " << l << " " << r << endl;
  if(r <= x)
    return n;
  if(mi[id] > y)
    return n;
  if(r-l < 2)
    return l;
  int mid = (l + r) >> 1, il = id<<1, ir = il|1;
  int res = get(x, y, il, l, mid);
  if(res < n)
    return res;
  return get(x, y, ir, mid, r);
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    int c, q;
    scanf("%d%d", &c, &q);
    ts[i] = make_pair(q, c);
  }
  sort(ts, ts+n, cmp);
  build();
  scanf("%d", &k);
  for(int i= 0; i<k; i++) {
    int b;
    scanf("%d", &b);
    bb[i] = make_pair(b, i);
  }
  sort(bb, bb+k, cmp);
  int cur = 0, cans = 0, ncur = 1;
  st[0] = {0, -1};
  for(int i = 0; i<k; i++) {
    ncur = upper_bound(st, st+ncur, make_pair(bb[i].first, n+1)) - st;
    int id = st[ncur-1].second;
    cur = st[ncur-1].first;
    int now = bb[i].first-cur;
    // cerr << id << " " << now<<  endl;
    while(true) {
      id = get(id+1, now);
      // cerr << id << " now " << now << endl;
      if(id < n) {
        now -= ts[id].second;
        cur += ts[id].second;
        st[ncur++] = {cur, id};
      }
      else break;
    }
    // cerr << bb[i].second << " " << cans << " " << cur << endl;
    ans[bb[i].second] = ncur-1;
  }
  for(int i = 0; i<k; i++)
    printf("%d ", ans[i]);
  printf("\n");
  return 0;
}