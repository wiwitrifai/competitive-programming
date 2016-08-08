#include <bits/stdc++.h>

using namespace std;

const int N = 303;
#define x first
#define y second

typedef pair<int, int> point;
point p[4 * N], p2[N*N];
int m, xa, xb, ya, yb;
vector< int > vy[(N*N)<<2]; 
vector< int > px;
vector< int > py[N*N];

void build(int id = 1, int l = 0, int r = m) {
  if (r-l < 2) {
    sort(py[l].begin(), py[l].end());
    vy[id].clear();
    vy[id] = py[l];
    return;
  }
  int mid = (l+r) >> 1, il = id<<1, ir = il|1;
  build(il, l, mid);
  build(ir, mid, r);
  vy[id].clear();
  int jl = 0, jr = 0;
  while(jl < vy[il].size() && jr <vy[ir].size()) {
    int mi;
    if(vy[il][jl] < vy[ir][jr])
      mi = vy[il][jl++];
    else
      mi = vy[ir][jr++];
    vy[id].push_back(mi);
  }
  while(jl < vy[il].size()) {
    vy[id].push_back(vy[il][jl++]);
  }
  while(jr < vy[ir].size()) {
    vy[id].push_back(vy[ir][jr++]);
  }
  assert(vy[id].size() == (vy[il].size() + vy[ir].size()));
}

int get(int xa, int xb, int ya, int yb, int id = 1, int l = 0, int r = m) {
  if (xa > px[r-1] || xb < px[l]) return 0;
  if (xa <= px[l] && px[r-1] <= xb) {
    return upper_bound(vy[id].begin(), vy[id].end(), yb) - lower_bound(vy[id].begin(), vy[id].end(), ya);
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
    if(xa > xb)
      swap(xa, xb);
    if(ya > yb)
      swap(ya, yb);
    xa *= 4; ya *= 4;
    xb *= 4; yb *= 4;
    for (int i = 0; i < 4 * n; i++) {
      scanf("%d%d", &p[i].x, &p[i].y);
    }
    m = 0;
    px.clear();
    for(int i = 0; i<n; i++)
      for(int j = 0; j<n; j++) {
        p2[m++] = {p[i].x + p[n+j].x, p[i].y + p[n+j].y};
        px.push_back(p[i].x + p[n+j].x);
      }
    sort(px.begin(), px.end());
    px.erase(unique(px.begin(), px.end()), px.end());
    for(int i = 0; i<=px.size(); i++) {
      py[i].clear();
    }
    for(int i = 0; i<m; i++) {
      int id = lower_bound(px.begin(), px.end(), p2[i].x) - px.begin();
      py[id].push_back(p2[i].y);
    }
    m = px.size();
    build();
    long long ans = 0;
    for(int i = 0; i<n; i++) {
      for(int j = 0; j<n; j++) {
        int xx = p[i+2*n].x + p[j+3*n].x, yy = p[i+2*n].y + p[j+3*n].y;
        ans += get(xa-xx, xb-xx, ya-yy, yb-yy);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}