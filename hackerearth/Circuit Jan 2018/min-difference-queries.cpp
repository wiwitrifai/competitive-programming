#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int upper(int len) {
  int l = 1, r = len;
  while (l < r) {
    int mid = (l + r) >> 1;
    long long cnt = 1LL * mid * (mid + 1) / 2;
    if (cnt <= len)
      l = mid+1;
    else
      r = mid;
  }
  return l;
}
vector<int> va[N << 2];
int a[N], n;
void build(int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    va[id].push_back(a[l]);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  va[id].resize(va[il].size() + va[ir].size());
  merge(va[il].begin(), va[il].end(), va[ir].begin(), va[ir].end(), va[id].begin());
  va[id].erase(unique(va[id].begin(), va[id].end()), va[id].end());
}

int lim;
set<int> st;
void get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (st.size() >= lim) return;
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    for (int x : va[id]) {
      st.insert(x);
      if (st.size() >= lim) return;
    }
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  get(x, y, il, l, mid);
  get(x, y, ir, mid, r);
}

vector<int> id[N];
int count(int x, int l, int r) {
  return lower_bound(id[x].begin(), id[x].end(), r) - lower_bound(id[x].begin(), id[x].end(), l);
}

int main() {
  int q;
  scanf("%d %d", &n, &q);
  vector<int> da;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    da.push_back(a[i]);
  }
  sort(da.begin(), da.end());
  da.erase(unique(da.begin(), da.end()), da.end());
  for (int i = 0; i < n; ++i) {
    a[i] = lower_bound(da.begin(), da.end(), a[i]) - da.begin();
    id[a[i]].push_back(i);
  }
  build();
  int ans = 0;
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    l = (l + ans + n) % n;
    r = (r + ans + n) % n;
    if (l > r) swap(l, r);
    ++r;
    st.clear();
    lim = upper(r-l);
    get(l, r);
    if (st.size() <= 1)
      ans = -1;
    else if (st.size() >= lim)
      ans = 0;
    else {
      vector<int> val;
      for (int x : st)
        val.push_back(count(x, l, r));
      sort(val.begin(), val.end());
      ans = val[1]-val[0];
      for (int i = 1; i + 1 < val.size(); ++i)
        ans = min(ans, val[i+1] - val[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}