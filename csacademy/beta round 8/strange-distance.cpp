#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

vector< int > pos[N + 5];
vector< int > seg[(N<<2) + 5];
pair<int, int> pp[N + 5];
int cntx[N + 5], cnty[N + 5];
void build(int id = 1, int l = 0, int r = N) {
  // cerr << id << " " << l  << " " << r << endl;
  if(r-l < 2) {
    seg[id] = pos[l];
    return;
  }
  int mid = (l + r) >> 1, il = id<<1, ir = il|1;
  build(il, l, mid);
  build(ir, mid, r);
  seg[id].resize(seg[il].size() + seg[ir].size());
  merge(seg[il].begin(), seg[il].end(), seg[ir].begin(), seg[ir].end(), seg[id].begin());
}

int get(int xl, int xu, int yl, int yu, int id = 1, int l = 0, int r = N) {
  if(r <= xl || xu <= l) return 0;
  if(xl <= l && r <= xu) {
    int res =  0;
    res = upper_bound(seg[id].begin(), seg[id].end(), yu) -
           upper_bound(seg[id].begin(), seg[id].end(), yl-1);
    cerr << res << " get " << l << " " << r << endl;
    return res;
  }
  int mid = (l + r) >> 1, il = id<<1, ir = il|1;
  return get(xl, xu, yl, yu, il, l, mid)
      +  get(xl, xu, yl, yu, ir, mid, r);
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for(int i = 0; i<n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    pp[i] = {x, y};
    cntx[x]++;
    cnty[y]++;
  }
  for(int i = 1; i<N; i++) {
    cntx[i] += cntx[i-1];
    cnty[i] += cnty[i-1];
  }
  sort(pp, pp+n);
  for(int i = 0; i<N; i++) {
    pos[pp[i].first].push_back(pp[i].second);
  }
  cerr << "byild " << endl;
  build();
  cerr << " que " << endl;
  int l = 0, r =  N;
  while(l < r) {
    int mid = (l + r)>>1;
    int cnt = 0;
    for(int i = 0; i<n; i++) {
      int x = pp[i].first, y = pp[i].second;
      cerr << x << " xy " << y << endl;
      cerr << cnt << " h ";
      cnt += cntx[min(x+mid, N-1)]-cntx[x-1] + cnty[min(y+mid, N-1)] - cnty[y-1] - get(x, x+mid, y, y+mid);
      cerr << " " << cntx[min(x+mid, N-1)] << " - " << cntx[x-1] << " + " << cnty[min(y+mid, N-1)] << " - " <<  cnty[y-1]  << " - " <<  1  << " - " <<  get(x, x+mid, y, y+mid) << " "; 
      cerr << cnt << endl;
    }
    cerr << mid << " " << cnt << " " << k << endl;
    if(cnt < k)
      l = mid+1;
    else         
      r = mid;
  }
  printf("%d\n", l);
  return 0;
}