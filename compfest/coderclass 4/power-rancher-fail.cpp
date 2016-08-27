#include <bits/stdc++.h>

using namespace std;

const int N = 300;
#define x first
#define y second

struct fen {
  int * bit;
  int n;
  fen(int n) : n(n) {
    bit = new int[n+1];
  }
  void upd(int x, int v) {
    for(; x<=n; x += x&(-x))
      bit[x] += v;
  }
  int get(int x) {
    int ret = 0;
    for(; x; x -= x&(-x))
      ret += bit[x];
    return ret;
  }
};

typedef pair<int, int> point;
point p[N], p2[N*N];
int m, xa, xb, ya, yb;
vector< int > vy[(N*N)<<2]; 
vector< int > px;
vector< int > py[N*N];
fen * cnt[(N*N)<<2];

void build(int id = 1, int l = 0, int r = m) {
  if (r-l < 2) {
    sort(py[l].begin(), py[l].end());
    vy[id] = py[l];
    cnt[id] = new fen(vy[id].size());
    return;
  }
  int mid = (l+r) >> 1, il = id<<1, ir = il|1;
  build(il, l, mid);
  build(ir, mid, r);
  vy[id].clear();
  int jl = 0, jr = 0;
  while(jl < vy[il].size() && jr <vy[ir].size()) {
    int mi = 0;
    if(vy[il][jl] < vy[ir][jr])
      mi = vy[il][jl++];
    else
      mi = vy[ir][jr++];
    if(vy[id].empty() || mi > vy[id].back())
      vy[id].push_back(mi);
  }
  while(jl < vy[il].size()) {
    vy[id].push_back(vy[il][jl++]);
  }
  while(jr < vy[ir].size()) {
    vy[id].push_back(vy[ir][jr++]);
  }
  cnt[id] = new fen(vy[id].size());
}

void update(int x, int y, int id = 1, int l = 0, int r = m) {
  if(r-l < 2) {
    assert(px[l] == x);
    int ix = lower_bound(vy[id].begin(), vy[id].end(), y) - vy[id].begin() + 1;
    cnt[id]->upd(ix, +1);
    return;
  }
  int mid = (l+r)>>1, il = id<<1, ir = il|1;
  if(x < px[mid])
    update(x, y, il, l, mid);
  else
    update(x, y, ir, mid, r);
  int ix = lower_bound(vy[id].begin(), vy[id].end(), y) - vy[id].begin() + 1;
  cnt[id]->upd(ix, +1);  
}

int get(int xa, int xb, int ya, int yb, int id = 1, int l = 0, int r = m) {
  if (xa >= px[r-1] || xb <= px[l]) return 0;
  if (xa <= px[l] && px[r-1] <= xb) {
    int ia = lower_bound(vy[id].begin(), vy[id].end(), ya) - vy[id].begin(),
        ib = upper_bound(vy[id].begin(), vy[id].end(), yb) - vy[id].begin();
    return cnt[id]->get(ib) - cnt[id]->get(ia);
  }
  int mid = (l+r)>>1, il = id << 1, ir=il|1;
  return get(xa, xb, ya, yb, il, l, mid) + get(xa, xb, ya, yb, ir, mid, r);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
    xa *= 4; ya *= 4;
    xb *= 4; yb *= 4;
    for (int i = 0; i < 4 * n; i++) {
      scanf("%d%d", &p[i].x, &p[i].y);
    }
    m = 0;
    px.clear();
    for(int i = 0; i<n; i++)
      for(int j = i+1; j<n; j++) {
        p2[m++] = {p[i].x + p[j].x, p[i].y + p[j].y};
        px.push_back(p[i].x + p[j].x);
      }
    sort(px.begin(), px.end());
    px.erase(unique(px.begin(), px.end()), px.end());
    for(int i = 0; i<px.size(); i++) {
      py[i].clear();
    }
    for(int i = 0; i<m; i++) {
      int id = lower_bound(px.begin(), px.end(), p2[i].x) - px.begin();
      py[id].push_back(p2[i].y);
    }
    m = px.size();
    px.push_back(px.back()+1);
    build();
    int ans = 0;
    for(int i = 1; i<n; i++) {
      for(int j = i+1; j<n; j++) {
        int xx = p[i].x + p[j].x, yy = p[i].y + p[j].y;
        ans += get(xa-xx, xb-xx, ya-yy, yb-yy);
      }
      for(int j = 0; j<i; j++) {
        int xx = p[i].x + p[j].x, yy = p[i].y + p[j].y;
        update(xx, yy);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}