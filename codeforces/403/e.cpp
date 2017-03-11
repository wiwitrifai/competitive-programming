#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6, mod = 1e9 + 7;
set< int > st[N << 2];
int n, dp[N];
void build(int id = 1, int l = 0, int r = n) {
  st[id].clear();
  st[id].insert(0);
  if (r-l < 2)
    return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}
void add(int x, int y, int v, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    st[id].insert(v);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  add(x, y, v, il, l, mid);
  add(x, y, v, ir, mid, r);
}
void erase(int x, int y, int v, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    st[id].erase(v);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  erase(x, y, v, il, l, mid);
  erase(x, y, v, ir, mid, r);
}
int get(int x, int id = 1, int l = 0, int r = n) {
  int ret = *(--st[id].end());
  if (r-l < 2) {
    return ret;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    ret = max(ret, get(x, il, l, mid));
  else
    ret = max(ret, get(x, ir, mid, r));
  return ret; 
}
pair< pair< int, int >, pair< int, int > > seg[N]; 
int main() __attribute__((optimize("-O2")));
int main() {
  int h, w, m;
  scanf("%d %d %d", &h, &w, &m);
  n = w;
  for (int i = 1; i <= m; i++) {
    int u, l, r, s;
    scanf("%d %d %d %d", &u, &l, &r, &s);
    seg[i] = {{u, u+s+1}, {l-1, r}};
  }
  sort(seg+1, seg + m + 1);
  vector< pair< int, int > > events;
  for (int i = 1; i <= m; i++) {
    events.emplace_back(seg[i].first.first, i);
    if (seg[i].first.second <= h+1)
      events.emplace_back(seg[i].first.second, -i);
  }
  sort(events.begin(), events.end());
  dp[0] = 1;
  build();
  for (auto it : events) {
    int id = it.second;
    if (id < 0) {
      id = -id;
      erase(seg[id].second.first, seg[id].second.second, id);
    }
    else {
      int x = seg[id].second.first-1;
      if (x < 0)
        x = seg[id].second.second;
      dp[id] = dp[get(x)];
      x = seg[id].second.second;
      if (x >= n)
        x = seg[id].second.first-1;
      dp[id] += dp[get(x)];
      if (dp[id] >= mod) dp[id] -= mod;
      add(seg[id].second.first, seg[id].second.second, id);
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += dp[get(i)];
    if (ans >= mod)
      ans -= mod;
  }
  cout << ans << endl;
  return 0;
}