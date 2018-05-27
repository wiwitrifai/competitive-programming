#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 4, LG = 30;

vector<int> ver[N << 2];
bitset<N> mask[LG];
int n, q;
void add(int x, int y, int z, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    ver[id].push_back(z);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  add(x, y, z, il, l, mid);
  add(x, y, z, ir, mid, r);
}
bitset<N> ans;
void dfs(int id = 1, int l = 0, int r = n, int lv = 0) {
  for (auto x : ver[id]) {
    mask[lv] = mask[lv] | (mask[lv] << x);
  }
  if (r-l < 2) {
    ans = ans | mask[lv];
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  mask[lv+1] = mask[lv];
  dfs(il, l, mid, lv+1);
  mask[lv+1] = mask[lv];
  dfs(ir, mid, r, lv+1);
}

int main() {
  scanf("%d %d", &n, &q);
  for (int i = 0; i < q; ++i) {
    int l, r, x;
    scanf("%d %d %d", &l, &r, &x); --l;
    add(l, r, x);
  }
  for (int i = 0; i < LG; ++i)
    mask[i].reset(); 
  mask[0][0] = 1;
  dfs();
  vector<int> all;
  for (int i = 1; i <= n; ++i)
    if (ans[i])
      all.push_back(i);
  printf("%d\n", (int)all.size());
  for (int i = 0; i < all.size(); ++i) {
    printf("%d%c", all[i], i+1 == (int)all.size() ? '\n' : ' ');
  }
  return 0;
}