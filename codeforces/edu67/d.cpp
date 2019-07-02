#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5, inf = 1e9 + 7;

int n;
int a[N], b[N];

int mins[N << 2];

vector<int> pos[N];

void build(int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    mins[id] = a[l];
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  mins[id] = min(mins[il], mins[ir]);
}

void update(int x, int v, int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    mins[id] = v;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    update(x, v, il, l, mid);
  else
    update(x, v, ir, mid, r);
  mins[id] = min(mins[il], mins[ir]);
}

int get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return inf;
  if (x <= l && r <= y) {
    return mins[id];
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  return min(get(x, y, il, l, mid), get(x, y, ir, mid, r));
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", a+i);
    for (int i = 0; i < n; ++i)
      scanf("%d", b+i);
    bool ans = 1;
    for (int i = 0; i <= n; ++i)
      pos[i].clear();
    for (int i = n-1; i >= 0; --i) {
      pos[a[i]].push_back(i);
    }
    build();
    for (int i = 0; i < n; ++i) {
      if (pos[b[i]].empty()) {
        ans = 0;
        break;
      }
      int p = pos[b[i]].back();
      pos[b[i]].pop_back();
      int r = get(0, p);
      if (r < b[i]) {
        ans = 0;
        break;
      }
      update(p, inf);
    }
    puts(ans ? "YES" : "NO");
  }
  return 0;
}
