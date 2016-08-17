#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, len, m;
pair<pair<int, int>, int > p[N];
int vy[N];
long long sum[N<<2], lazy[N<<2];

void build(int id = 1, int l = 0, int r = m) {
  sum[id] = lazy[id] = 0;
  if(r-l < 2)
    return;
  int mid = (l+r)>>1, il = id<<1, ir = il|1;
  build(il, l, mid);
  build(ir, mid, r);
}
void shift(int id) {
  if(lazy[id]) {
    int il = id<<1, ir = il|1;
    sum[il] += lazy[id];
    lazy[il] += lazy[id];
    sum[ir] += lazy[id];
    lazy[ir] += lazy[id];
    lazy[id] = 0;
  }
}
void upd(int x, int c, int id = 1, int l = 0, int r = m) {
  if(vy[l] + len >= x && x >= vy[r-1]) {
    sum[id] += c;
    lazy[id] += c;
    return;
  }
  if(x < vy[l] || x > vy[r-1]+len)
    return;
  int mid = (l+r)>>1, il = id<<1, ir = il|1;
  shift(id);
  upd(x, c, il, l, mid);
  upd(x, c, ir, mid, r);
  sum[id] = max(sum[il], sum[ir]);
}

long long getsum(int ll) {
  int tmp = len;
  len = ll;
  build();
  int l = 0;
  long long ans = 0;
  for(int i = 0; i<n; i++) {
    upd(p[i].first.second, p[i].second);
    while(l < i && (p[l].first.first + len < p[i].first.first))
      upd(p[l].first.second, -p[l].second), l++;
    ans = max(ans, sum[1]);
  }
  len = tmp;
  return ans;
}


int main() {
  scanf("%d%d", &n, &len);
  for(int i = 0; i<n; i++) {
    int x, y, c;
    scanf("%d%d%d", &x, &y, &c);
    p[i] = {{x, y}, c};
    vy[i] = y;
  }
  sort(p, p+n);
  sort(vy, vy + n);
  m = unique(vy, vy+n) - vy;
  len--;
  long long s = getsum(len);
  int l = 0, r = len;
  while(l < r) {
    int mid = (l+r)>>1;
    long long res = getsum(mid);
    if(res == s)
      r = mid;
    else
      l = mid+1;
  }
  printf("%lld %d\n", s, l+1);
  return 0;
}