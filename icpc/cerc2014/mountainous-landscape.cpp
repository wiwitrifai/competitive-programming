/*
  2014 Central Europe Regional Contest - (B) Mountainous Landscape
  Wiwit Rifa'i
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

#define x first
#define y second

int n;
typedef pair<int, int > point;
vector< point > vpoint;
vector< point > vvp[N<<2];

long long cross(point a, point b, point c) {
  return 1LL*(a.x-b.x)*(c.y-b.y) - 1LL*(a.y-b.y)*(c.x-b.x);
}

void build(vector< point > const &vp, int id = 1, int l = 0, int r = n) {
  vector< point > &h = vvp[id];
  h.clear();
  for(int i = l; i<r; i++) {
    while(h.size() > 1 && cross(h[h.size()-2], h.back(), vp[i]) <= 0) 
      h.pop_back();
    h.push_back(vp[i]);
  }
  if(r-l < 2)
    return;
  int me = (l+r)>>1, il = id << 1, ir = il|1;
  build(vp, il, l, me);
  build(vp, ir, me, r);
}

bool cut(point p, point q, const vector< point > &h) {
  if(h.size() == 1)
    return cross(p, q, h.back()) < 0;
  int l = 0, r = (int)h.size()-2;
  while(l<r) {
    int me = (l+r) >> 1;
    if(cross(p, q, h[me]) < cross(p, q, h[me+1]))
      r = me;
    else
      l = me+1;
  }
  return (cross(p, q, h[l]) < 0 || cross(p, q, h[l+1]) < 0);
}

int cek(point p, point q, int x, int y, int id = 1, int l = 0, int r = n) {
  if(l >= y || x >= r) return 0;
  if(x <= l && r <= y) {
    if(!cut(p, q, vvp[id]))
      return 0;
    if(r-l< 2)
      return l;
  }
  int me = (l+r) >> 1, il = id<<1, ir = il|1;
  int res = cek(p,q,x,y,il,l,me);
  if(res)
    return res;
  return cek(p,q,x,y,ir,me,r);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    vpoint.assign(n, point());
    for(int i = 0; i<n; i++) {
      scanf("%d%d", &vpoint[i].x, &vpoint[i].y);
    }
    build(vpoint);
    for(int i = 0; i<n-2; i++)
      printf("%d ", cek(vpoint[i], vpoint[i+1], i+2, n));
    puts("0");
  }
  return 0;
}