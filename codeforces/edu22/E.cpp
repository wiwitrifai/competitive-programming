#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, a[N], b[N], k;
deque<int> last[N];
vector< int > s[N << 2];

void build(int id = 1, int l = 0, int r = n) {
  s[id].resize(r-l);
  if (r-l < 2) {
    s[id][0] = b[l];
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  merge(s[il].begin(), s[il].end(), s[ir].begin(), s[ir].end(), s[id].begin());
}
int get(int x, int y, int z, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return 0;
  if (x <= l && r <= y) {
    return lower_bound(s[id].begin(), s[id].end(), z) - s[id].begin();
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  return get(x, y, z, il, l, mid) + get(x, y, z, ir, mid, r);
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < N; i++)
    last[i].push_front(n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  for (int i = n-1; i >= 0; i--) {
    b[i] = last[a[i]].back();
    last[a[i]].push_front(i);
    if (last[a[i]].size() > k)
      last[a[i]].pop_back();
  }
  build();
  int ans = 0, q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    l = (l + ans) % n;
    r = (r + ans) % n;
    if (l > r) swap(l, r);
    r++;
    ans = r-l-get(l, r, r);
    printf("%d\n", ans);
  }
  return 0;
}