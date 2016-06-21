#include <bits/stdc++.h>
 
using namespace std;
const int N = 1e5 + 6;
int n, q, a[N], b[N];
pair<int, int> * x[N<<2];
pair<long long, long long> * sum[N<<2];
bool cmp(pair<int, int> c, pair<int, int> d) {
  return c.second == 0 || 1LL * c.second * d.first < 1LL * c.first * d.second;
}
 
void build(int id = 1, int l = 0, int r = n) {
  x[id] = new pair<int, int>[r-l+1];
  sum[id] = new pair<long long, long long>[r-l+1];
  if(r-l < 2) {
    x[id][0] = make_pair(a[l], b[l]);
    sum[id][0] = make_pair(a[l], b[l]);
    return;
  }
  int mid = (l + r) >> 1, il = id<<1, ir = il|1;
  build(il, l, mid);
  build(ir, mid, r);
  int c = 0, d = 0;
  int szr = r - mid, szl = mid - l, sz = 0;
  long long suma = 0, sumb = 0;
  while(c < szl && d < szr) {
    pair< int, int> chosed;
    if(cmp(x[il][c], x[ir][d]))
      chosed = x[il][c++];
    else
      chosed = x[ir][d++];
    x[id][sz] = chosed;
    suma += chosed.first;
    sumb += chosed.second;
    sum[id][sz++] = make_pair(suma, sumb);
  }
  while(c < szl) {
    pair< int, int> chosed = x[il][c++];
    x[id][sz] = chosed;
    suma += chosed.first;
    sumb += chosed.second;
    sum[id][sz++] = make_pair(suma, sumb);
  }
  while(d < szr) {
    pair< int, int> chosed = x[ir][d++];
    x[id][sz] = chosed;
    suma += chosed.first;
    sumb += chosed.second;
    sum[id][sz++] = make_pair(suma, sumb);
  }
}
 
long long get(int xx, int y, long long c, long long d, int id = 1, int l = 0, int r = n) {
  if(l >= y || r <= xx)
    return 0;
  if(xx <= l && r <= y) {
    int ll = 0, rr = r-l-1 ;
    while(ll < rr) {
      int mid = (ll + rr + 1)>>1;
      if(x[id][mid].first * c >= x[id][mid].second * d)
        ll = mid;
      else
        rr = mid-1;
    }
    return max(0LL, c * sum[id][ll].first - d * sum[id][ll].second);
  }
  int mid = (l + r) >> 1, il = id<<1, ir = il|1;
  return max(0LL, get(xx, y, c, d, il, l, mid) + get(xx, y, c, d, ir, mid, r));
}
 
int main() {
  scanf("%d", &n);
  for(int i = 0; i<n; i++)
    scanf("%d", a+i);
  for(int j = 0; j<n; j++) {
    scanf("%d", b+j);
    if(a[j] == 0)
      b[j] = 0;
  }
  build();
  scanf("%d", &q);
  while(q--) {
    int l, r, c, d;
    scanf("%d%d%d%d", &l, &r, &c, &d);
    printf("%lld\n", get(l-1, r, c, d));
    fflush(stdout);
  }
  return 0;
} 