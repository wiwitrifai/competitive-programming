#include <bits/stdc++.h>

using namespace std;

void openfile(string name) {
#ifndef LOCAL
  freopen((name + ".in").c_str(), "r", stdin);
  freopen((name + ".out").c_str(), "w", stdout);
#endif
}
void closefile() {
#ifndef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
}

const int N = 1024;
int a[N << 1][N << 1], n;
void upd1(int x, int y, int idd, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    a[idd][id] = 1;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  upd1(x, y, idd, il, l, mid);
  upd1(x, y, idd, ir, mid, r);
}
void upd2(int x, int y, int lo, int hi, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    upd1(lo, hi, id);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  upd2(x, y, lo, hi, il, l, mid);
  upd2(x, y, lo, hi, ir, mid, r);
}
int get1(int x, int idd, int id = 1, int l = 0, int r = n) {
  if (a[idd][id]) return 1;
  if (r-l < 2)
    return 0;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    return get1(x, idd, il, l, mid);
  else
    return get1(x, idd, ir, mid, r);
}
int get2(int x, int y, int id = 1, int l = 0, int r = n) {
  if (get1(y, id)) return 1;
  if (r-l < 2)
    return 0;
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    return get2(x, y, il, l, mid);
  else
    return get2(x, y, ir, mid, r);
}
int x[N][N], le[N * N], ri[N * N], lo[N * N], hi[N * N];
bool fst[N * N];
vector< pair< int, int > > pos[N * N];
int main() {
  openfile("art");
  scanf("%d", &n);
  memset(fst, 1, sizeof fst);
  for (int i = 0; i <= n * n; i++) {
    lo[i] = le[i] = n+1;
    ri[i] = hi[i] = -1;
    pos[i].clear();
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int col;
      scanf("%d", &col);
      x[i][j] = col;
      le[col] = min(le[col], j);
      ri[col] = max(ri[col], j);
      lo[col] = min(lo[col], i);
      hi[col] = max(hi[col], i);
      pos[col].emplace_back(i, j);
    }
  }
  memset(a, 0, sizeof a);
  for (int i = 1; i <= n * n; i++) {
    if (lo[i] > hi[i] || le[i] > ri[i]) continue;
    for (pair< int, int > it : pos[i])
      if (get2(it.first, it.second)){
        fst[i] = 0;
        break;
      }
    upd2(lo[i], hi[i]+1, le[i], ri[i]+1);
  }
  memset(a, 0, sizeof a);
  for (int i = n * n; i > 0; i--) {
    if (lo[i] > hi[i] || le[i] > ri[i]) continue;
    if (fst[i]) {
      for (pair< int, int > it : pos[i])
        if (get2(it.first, it.second)){
          fst[i] = 0;
          break;
        }
    }
    upd2(lo[i], hi[i]+1, le[i], ri[i]+1);
  }
  bool last = 0;
  int cnt = 0;
  for (int i = 1; i <= n * n; i++) {
    if (lo[i] > hi[i] || le[i] > ri[i]) continue;
    if (pos[i].size() == (hi[i]-lo[i] + 1) * (ri[i]-le[i]+1)) {
      cnt++;
      if (!fst[i])
        last = 1;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n * n; i++)
    ans += fst[i];
  if (!last && cnt <= 1)
    ans--;
  ans = max(ans, 1);
  printf("%d\n", ans);
  closefile();
  return 0;
}