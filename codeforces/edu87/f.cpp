#include <bits/stdc++.h>

using namespace std;

const int N = 77, inf = 1e9 + 7;

int vid[N];
pair<int, int> ba[N];

int mem[N][N];
int n, k;

;inline int add(int a, int b) {
  if (a <= -inf || b <= -inf)
    return -inf;
  return a + b;
}

int dp(int id, int s) {
  if (id == n) {
    return s == k ? 0 : -inf;
  }
  int & ret = mem[id][s];
  if (ret != -1)
    return ret;
  int v = vid[id];
  if (s < k)
    ret = add(dp(id+1, s+1), ba[v].first * s + ba[v].second);
  ret = max(ret, add(dp(id+1, s), (k-1) * ba[v].first));
  return ret;
}

bool selected[N];

void backtrack(int id, int s) {
  if (id == n)
    return;
  int v = vid[id];
  if (s < k && dp(id, s) == (dp(id+1, s+1) + ba[v].first * s + ba[v].second)) {
    selected[id] = true;
    backtrack(id+1, s+1);
  } else {
    selected[id] = false;
    backtrack(id+1, s);
  }
}

void solve() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &ba[i].second, &ba[i].first);
  }
  iota(vid, vid+n, 0);
  sort(vid, vid+n, [](int l, int r) {
    return ba[l] < ba[r];
  });
  int m = 2 * n - k;
  vector<int> ada;
  memset(mem, -1, sizeof mem);
  int ans = dp(0, 0);
  backtrack(0, 0);
  for (int i = 0; i < n; ++i) {
    if (selected[i])
      ada.push_back(vid[i]);
  }
  printf("%d\n", m);
  for (int i = 0; i+1 < (int)ada.size(); ++i) {
    printf("%d ", ada[i]+1);
  }
  for (int i = 0; i < n; ++i) {
    if (selected[i]) continue;
    int v = vid[i];
    printf("%d ", v+1);
    printf("%d ", -(v+1));
  }
  printf("%d\n", ada.back() + 1);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
