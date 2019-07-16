#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;

int lis[N], s[N], a[N];

int bit[N];

int get(int x) {
  int ret = 0;
  for (++x; x < N; x += x&-x)
    ret = max(ret, bit[x]);
  return ret;
}

void upd(int x, int v) {
  for (++x; x; x -= x&-x)
    bit[x] = max(bit[x], v);
}

int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  int ans = 0;
  vector<int> vx;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    int id = lower_bound(s, s+ans, a[i]) - s;
    s[id] = a[i];
    lis[i] = id+1;
    ans += id == ans;
    vx.push_back(a[i] - x);
    vx.push_back(a[i]);
  }
  sort(vx.begin(), vx.end());
  vx.erase(unique(vx.begin(), vx.end()), vx.end());
  for (int i = n-1; i >= 0; --i) {
    int id = lower_bound(vx.begin(), vx.end(), a[i] - x) - vx.begin();
    ans = max(ans, lis[i] + get(id+1));
    id = lower_bound(vx.begin(), vx.end(), a[i]) - vx.begin();
    upd(id, get(id+1) + 1);
  }
  printf("%d\n", ans);
  return 0;
}