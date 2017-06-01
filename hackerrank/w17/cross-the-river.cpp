#include <bits/stdc++.h>

using namespace std;

#define X first.second
#define Y first.first
#define Z second

typedef pair< int , int > ii;
typedef pair< ii, int > iii;

const int N = 1e5 + 5;
const int inf = 1e9 + 7;

int n, h, dw, dh, score[N];
iii rock[N];

deque< int > dq[N];
int s[N<<2];

void build(int id = 1, int l = 0, int r = N) {
  s[id] = -inf;
  if(r-l<2)
    return;
  int mid = (l+r)>>1, il = id << 1, ir = il|1;
  build(il, l, mid);
  build(ir, mid, r);
}

void update(int pos, int val, int id = 1, int l = 0, int r = N) {
  s[id]  = max(s[id], val);
  if(r-l<2) {
    while(!dq[l].empty()) {
      int fr = dq[l].back();
      if(fr < val)
        dq[l].pop_back(); 
      else
        break;
    }
    dq[l].push_back(val);
    return;
  }
  int mid = (l+r)>>1, il = id << 1, ir = il|1;
  if(pos< mid)
    update(pos, val, il, l, mid);
  else
    update(pos, val, ir, mid, r);
}

void del(int pos, int val, int id = 1, int l = 0, int r = N) {
  if(r-l<2) {
    if(!dq[l].empty() && dq[l].front() == val)
      dq[l].pop_front();
    s[id] = (dq[l].empty() ? -inf : dq[l].front());
    return;
  }
  int mid = (l+r)>>1, il = id << 1, ir = il|1;
  if(pos < mid)
    del(pos, val, il, l, mid);
  else
    del(pos, val, ir, mid, r);
  s[id] = max(s[il], s[ir]);
}
int query(int x, int y, int id = 1, int l = 0, int r = N) {
  if(x >= r || y <= l) return -inf;
  if(x <= l && y >= r) return s[id];
  int mid = (l+r)>>1, il = id << 1, ir = il|1;
  return max(query(x, y, il, l, mid), query(x, y, ir, mid, r));
}

bool cmp(iii x, iii y) {
  if(x.Y != y.Y)
    return x.Y < y.Y;
  return x.X < y.X;
}

int main() {
  scanf("%d%d%d%d", &n, &h, &dh, &dw);
  for(int i = 0; i<n; i++) {
    int x, y, z;
    scanf("%d%d%d", &y, &x, &z); 
    rock[i] = make_pair(make_pair(y, x), z);
  }
  sort(rock, rock + n, cmp);
  for(int i = 0; i<n; i++) score[i] = -inf;
  build();
  int last = 0, rast = 0;
  for(int i = 0; i<n; i++) {
    if(rock[i].Y <= dh) score[i] = max(score[i], rock[i].Z);
    while(rast < i && rock[rast].Y < rock[i].Y) update(rock[rast].X, score[rast]), rast++;
    while(last < rast && rock[last].Y + dh < rock[i].Y) del(rock[last].X, score[last]), last++;
    int res = query(rock[i].X-dw, rock[i].X+dw+1);
    if(res > -inf)
      score[i] = max(score[i], rock[i].Z+res);
  }
  int ans = -inf;
  for(int i = 0; i<n; i++) {
    if(rock[i].Y+dh >= h)
        ans = max(ans, score[i]);
  }
  printf("%d\n", ans);
  return 0;
}