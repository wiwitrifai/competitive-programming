#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int add[N << 2], mi[N << 2];
int n;

void build(int id = 1, int l = 0, int r = n) {
  add[id] = mi[id] = 0;
  if (r-l < 2) {
    return ;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}

inline void upd(int id, int x) {
  add[id] += x;
  mi[id] += x;
}

inline void push(int id, int il, int ir) {
  if (add[id] == 0) return;
  upd(il, add[id]);
  upd(ir, add[id]);
  add[id] = 0;
}

void update(int x, int y, int v, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    upd(id, v);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, il, ir);
  update(x, y, v, il, l, mid);
  update(x, y, v, ir, mid, r);
  mi[id] = max(mi[il], mi[ir]);
}

int get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return 0;
  if (x <= l && r <= y) {
    return mi[id];
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, il, ir);
  return max(get(x, y, il, l, mid), get(x, y, ir, mid, r));
}

vector<int> pos[N];
int a[N];

void solve(int tc) {
  int s;
  scanf("%d %d", &n, &s);
  for (int i = 0; i < N; ++i)
    pos[i].clear();
  build();
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    int now = a[i];
    pos[now].push_back(i);
    int lef = 0;
    int siz = pos[now].size();
    if (siz >= s+1) {
      lef = pos[now][siz-s-1] + 1;
    }
    update(lef, i+1, +1);
    if (siz >= s+1) {
      int rig = pos[now][siz-s-1] + 1;
      lef = 0;
      if (siz >= s+2) {
        lef = pos[now][siz-s-2] + 1;
      }
      update(lef, rig, -s);
    }
    ans = max(ans, get(0, i+1));
  }
  printf("Case #%d: %d\n", tc, ans);
}

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    solve(tc);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << " s" << endl;
  }
  return 0;
}
