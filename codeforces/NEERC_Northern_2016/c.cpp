#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
int a[N], b[N], ca[N], cb[N];
pair< int, int > da[N], db[N];
int va[N], vb[N], cnta[N], cntb[N];

pair< int, int > getb(int v, int ma, int mb);
pair< int, int > geta(int v, int ma = 0, int mb = 0) {
  if (va[v] == 2)
    return da[v];
  if (va[v] == 1)
    return make_pair(ma, mb);
  va[v] = 1;
  da[v] = getb(cb[v], ma, max(mb, cb[v]));
  va[v] = 2;
  // cerr << "a " << v << " " << da[v].first << " " << da[v].second << endl;
  return da[v];
}

pair< int, int > getb(int v, int ma = 0, int mb = 0) {
  if (vb[v] == 2)
    return db[v];
  if (vb[v] == 1)
    return make_pair(ma, mb);
  vb[v] = 1;
  db[v] = geta(ca[v], max(ma, ca[v]), mb);
  vb[v] = 2;
  // cerr << "b " << v << " " << db[v].first << " " << db[v].second << endl;
  return db[v];
}

int bit[N];
void upd(int x, int v) {
  if (x <= 0) return;
  for (; x<N; x += x&(-x))
    bit[x] += v;
}
int get(int x) {
  if (x <= 0)
    return 0;
  int ret = 0;
  for (; x; x -= x&(-x))
    ret += bit[x];
  return ret;
}
int ans[N];

int main() {
  freopen("codecoder.in", "r", stdin);
  freopen("codecoder.out", "w", stdout);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", a+i, b+i);
    cnta[a[i]]++;
    cntb[b[i]]++;
    ca[b[i]] = max(ca[b[i]], a[i]);
    cb[a[i]] = max(cb[a[i]], b[i]);
  }
  for (int i = 1; i < N; i++) {
    ca[i] = max(ca[i], ca[i-1]);
    cb[i] = max(cb[i], cb[i-1]);
    cnta[i] += cnta[i-1];
    cntb[i] += cntb[i-1];
  }
  vector< pair<pair< int, int >, int > > que;
  vector< pair< int, int > > vupd; 
  for (int i = 0; i < n; i++) {
    auto aa = geta(a[i], a[i], 0), bb = getb(b[i], 0, b[i]);
    int x = max(aa.first, bb.first), y = max(aa.second, bb.second);
    que.push_back(make_pair(make_pair(x, y), i));
    vupd.push_back(make_pair(a[i], b[i]));
    ans[i] = cnta[x-1] + cntb[y-1] - (a[i] < x || b[i] < y);
    // cerr << i << " " << aa.first << " " << aa.second << " " << bb.first << " " << bb.second << " " << ans[i] << endl;
    // cerr << i << " " << x << " " << y << endl;
  }
  sort(que.begin(), que.end());
  sort(vupd.begin(), vupd.end());
  int id = 0;
  for (int i = 0; i < n; i++) {
    while (id < n && vupd[id].first < que[i].first.first) {
      upd(vupd[id].second, +1);
      id++;
    }
    ans[que[i].second] -= get(que[i].first.second-1);
  }
  for (int i = 0; i < n; i++)
    printf("%d\n", ans[i]); 
  return 0;
}