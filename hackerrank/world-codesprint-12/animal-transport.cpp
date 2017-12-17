#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 4;

int n, m;

struct seg_tree {
  int ma[N << 2], lz[N << 2];
  seg_tree() {
    memset(ma, 0, sizeof ma);
    memset(lz, 0, sizeof lz);
  }
  inline void build(int id, int l, int r) {
    ma[id] = lz[id] = 0;
    if (r-l < 2)
      return;
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    build(il, l, mid);
    build(ir, mid, r);
  }

  inline void push(int id) {
    if (lz[id] == 0) return;
    int il = id << 1, ir = il | 1;
    ma[il] += lz[id];
    ma[ir] += lz[id];
    lz[il] += lz[id];
    lz[ir] += lz[id];
    lz[id] = 0;
  }
  inline void update(int x, int y, int v, int id, int l, int r) {
    if (x >= r || l >= y) return;
    if (x <= l && r <= y) {
      ma[id] += v;
      lz[id] += v;
      return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    push(id);
    update(x, y, v, il, l, mid);
    update(x, y, v, ir, mid, r);
    ma[id] = max(ma[il], ma[ir]);
  }
  inline void assign(int x, int v, int id, int l, int r) {
    if (r-l < 2) {
      ma[id] = max(ma[id], v);
      lz[id] = 0;
      return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    push(id);
    if (x < mid)
      assign(x, v, il, l, mid);
    else
      assign(x, v, ir, mid, r);
    ma[id] = max(ma[il], ma[ir]);
  }
};

char t[N];
int s[N], d[N], dp[N];
vector<int> range[N];

int main() {
  seg_tree s1, s2;
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; ++i)
      scanf(" %c", t+i);
    for (int i = 0; i < n; ++i)
      scanf("%d", s+i);
    for (int i = 0; i < n; ++i)
      scanf("%d", d+i);
    for (int i = 1; i <= m; ++i)
      range[i].clear();
    for (int i = 0; i < n; ++i) {
      if (s[i] >= d[i]) continue;
      range[d[i]].push_back(i);
    }
    s1.build(1, 0, m+1);
    s2.build(1, 0, m+1);
    for (int i = 1; i <= m; ++i) {
      for (int j : range[i]) {
        if (t[j] == 'E' || t[j] == 'C') {
          s1.update(0, s[j]+1, 1, 1, 0, m+1);
        }
        else {
          s2.update(0, s[j]+1, 1, 1, 0, m+1);
        }
        int cur = max(s1.ma[1], s2.ma[1]);
        s1.assign(i, cur, 1, 0, m+1);
        s2.assign(i, cur, 1, 0, m+1);
      }
      dp[i] = max(s1.ma[1], s2.ma[1]);
    }
    for (int i = 1, j = 1; i <= n; ++i) {
      while (j <= m && dp[j] < i) ++j;
      printf("%d%c", j > m ? -1 : j, " \n"[i == n]);
    }
  }
  return 0;
}