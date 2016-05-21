#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

pair< int, int > order[N];

struct range_tree {
  const int n;
  vector< pair<int, int> > val[N];
  range_tree(int n_) : n(n_) {
    build(1, 0, n);
  }
  void build(int id, int l, int r) {
    if(r-l < 2) {
      val[id].push_back(order[l]);
      return;
    }
    int mid = (l+r) >> 1, il = id<<1, ir = il|1;
    build(il, l, mid);
    build(ir, mid, r);
    val[id].resize(r-l);
    l = r = 0;
    for(int i = 0; i<val[id].size(); i++) {
      if(l == val[il].size())
        val[id][i] = val[ir][r++];
      else if(r == val[ir].size())
        val[id][i] = val[il][l++];
      else if(val[il][l] < val[ir][r])
        val[id][i] = val[il][l++];
      else
        val[id][i] = val[il][l++];        
    }
  }
  int get(int x, int y, pair<int, int> v, int id, int l, int  r) {
    if(l >= y || r <= x) return 0;
    if(x <= l && r <= y) return distance(upper_bound(val[id].begin(), val[id].end(), v), val[id].begin())-1;
    int mid = (l+r) >> 1, il = id<<1, ir = il|1;
    return get(x, y, v, il, l, mid) + get(x, y, v, ir, mid, r);
  }
  int query(int x, int y, pair<int, int> v) {
    return get(x, y+1, v, 0, n);
  }
};

int n, q, a[N], id[N];

int main() {
  scanf("%d%d", &n, &q);
  for(int i = 0; i<n; i++)
    scanf("%d", a+i), id[i] = i;
  map<int, int> mp;  
  sort(id, id+n, [](int x, int y) {
    return a[x] < a[y];
  });
  for(int i = 0; i<n; i++)
    order[id[i]].first = i;
  for(int i = 0; i<n; i++) {
    order[i].second = (mp.count(a[i]) ? mp[a[i]] : -1);
    mp[a[i]] = i;
  }
  range_tree rt(n);
  int ans = 0;
  while(q--) {
    int x, y, p, q, k;
    scanf("%d%d%d%d%d", &x, &y, &p, &q, &k);
    int l = ((1LL * x * max(0, ans) + y) % n), r = ((1LL * p * max(0, ans) + q) % n); 
    if(l > r)
      swap(l, r);
      
  }
  return 0;
}