#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9 + 7;
vector< int > ord[N<<2];

struct node {
  int id, l, r;
  node * nl, * nr;
  int sum;
  node(int id, int l, int r) : id(id), l(l), r(r) {
    sum = 0;
    nl = NULL; nr = NULL;
  }
  void build() {
    // cerr << id << " node " << l << " " << r << endl;
    sum = 0;
    if(r-l < 2)
      return;
    int mid = (l+r) >> 1;
    nl = new node(id, l, mid);
    nl->build();
    nr = new node(id, mid, r);
    nr->build();
  }
  node * update(int x) {
    // cerr << l << " " << r << endl;
    node * ret = new node(id, l, r);
    ret->sum = sum+1;
    if(r-l < 2)
      return ret;
    ret->nl = nl;
    ret->nr = nr;
    // cerr << "ok" << endl;
    // cerr << nl->r << " sz " << id << endl;
    if(x < ord[id][nl->r])
      ret->nl = nl->update(x);
    else
      ret->nr = nr->update(x);
    return ret;
  }
  int get(int x) {
    if(ord[id][r-1] < x)
      return sum;
    if(ord[id][l] >= x)
      return 0;
    return nl->get(x) + nr->get(x);
  }
};
struct pnode {
  int id, l, r;
  vector< int > vers;
  vector< node * > nodes;
  pnode * nl, * nr;
  pnode(int id, int l, int r) : id(id), l(l), r(r), nl(NULL), nr(NULL) {
  }
  void build() {
    vers.push_back(-1);
    nodes.push_back(new node(id, 0, ord[id].size()));
    nodes.back()->build();
    if(r-l < 2)
      return;
    int mid = (l+r)>>1, il = id<<1, ir = il|1;
    nl = new pnode(il, l, mid);
    nl->build();
    nr = new pnode(ir, mid, r);
    nr->build();
  }
  int get(int ver, int ll, int rr) {
    if(ll >= r || rr <= l) return 0;
    if(ll <= l && r <= rr) {
      int x = upper_bound(vers.begin(), vers.end(), ver)-vers.begin()-1;
      // cerr << "pnode " << l << " " << r << " " << vers[x] << endl; 
      return nodes[x]->get(ll);
    }
    return nl->get(ver, ll, rr) + nr->get(ver, ll, rr);
  }
  void update(int x, int ver, int val) {
    // cerr << id << " - " << x << " " << ver << " " << val << endl;
    // if(val < l) {
    vers.push_back(ver);
    node * upd = nodes.back()->update(val);
    nodes.push_back(upd);
    // }
    if(r-l < 2)
      return;
    if(x < nl->r)
      nl->update(x, ver, val);
    else
      nr->update(x, ver, val);
  }
};

int n;
int a[N], b[N], c[N];
void build(int id = 1, int l = 0, int r = n) {
  if(r-l < 2) {
    ord[id].push_back(a[l]);
    return;
  }
  int mid = (l+r)>>1, il = id<<1, ir = il|1;
  build(il, l, mid);
  build(ir, mid, r);
  l = 0; r = 0;
  while(l < ord[il].size() || r < ord[ir].size()) {
    if(r >= ord[ir].size())
      ord[id].push_back(ord[il][l++]);
    else if(l >= ord[il].size())
      ord[id].push_back(ord[ir][r++]);
    else {
      int p = min(ord[il][l], ord[ir][r]);
      if(p == ord[il][l]) l++;
      if(p == ord[ir][r]) r++;
      ord[id].push_back(p);
    }
  }
  // cerr << id << "  ";
  // for(int i = 0; i<ord[id].size(); i++)
  //   cerr << ord[id][i] << " ";
  // cerr << endl;
}

int main() {
  int q;
  scanf("%d%d", &n, &q);
  for(int i = 0; i<n; i++) {
    scanf("%d", b+i);
    c[i] = i;
  }
  map<int, int> mp;
  for(int i = 0; i<n; i++) {
    if(mp.count(b[i]))
      a[i] = mp[b[i]];
    else
      a[i] = -1;
    mp[b[i]] = i;
  }
  sort(c, c+n, [](int x, int y) {return b[x] < b[y];});
  build();
  pnode * root = new pnode(1, 0, n);
  root->build();
  for(int i = 0; i<n; i++) {
    root->update(c[i], i, a[c[i]]);
  }
  int ver = 0;
  a[0] = b[c[0]];
  c[0] = 0;
  for(int i = 1; i<n; i++) {
    if(a[ver] != b[c[i]]) {
      ver++;
      a[ver] = b[c[i]];
    }
    c[ver] = i;
  }
  ver++;
  // cerr << "query start" << endl;
  int ans = 0;
  while(q--) {
    int x, y, u, v, k;
    scanf("%d%d%d%d%d", &x, &y, &u, &v, &k);
    int l = (1LL*x*ans + y ) % n, r = (1LL*u*ans + v) % n;
    if(l > r)
      swap(l, r);
    r++;
    int lo = 0, hi = ver, res, mid;
    while(lo < hi) {
      mid = (lo+hi)>>1;
      res = root->get(c[mid], l, r);
      // cerr << l << " " << r-1 << " | " << a[mid] << ", " << c[mid] << " = " << res << endl;
      if(res == k)
        break;
      if(res < k)
        lo = mid+1;
      else
        hi = mid;
    }
    if(k == res)
      ans = a[mid];
    else
      ans = -1;
    printf("%d\n", ans);
    if(ans < 0)
      ans = 0;
  }
  return 0;
}   