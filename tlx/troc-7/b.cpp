#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int a[N];

int up[N], down[N];

void upd_up(int x, int v) {
  for (; x; x -= x &-x)
    up[x] = max(up[x], v);
}
void upd_down(int x, int v) {
  for (; x < N; x += x &-x)
    down[x] = max(down[x], v);
}
int get_up(int x) {
  int ret = 0;
  for (; x < N; x += x &-x)
    ret = max(ret, up[x]);
  return ret;
}
int get_down(int x) {
  int ret = 0;
  for (; x; x -= x &-x)
    ret = max(ret, down[x]);
  return ret;
}

int dp[N][2];

int main() {
  int n;
  scanf("%d", &n);
  int best = -1;
  int is_up = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    dp[i][0] = get_down(a[i]-1) + 1;
    dp[i][1] = get_up(a[i]+1) + 1;
    upd_up(a[i], dp[i][0]); 
    upd_down(a[i], dp[i][1]);
    // cerr << i << " " << dp[i][0] << " " << dp[i][1] << endl;
    for (int j = 0; j < 2; ++j) {
      if (best == -1 || dp[i][j] > dp[best][is_up]) {
        best = i;
        is_up = j;
      }
    }
  }
  vector<int> ans;
  int cur = dp[best][is_up];
  int last = -1;
  if (is_up == 0)
    last = -1;
  else
    last = N + 5;
  for (int i = n-1; i >= 0; --i) {
    bool ok = dp[i][is_up] == cur;
    if (is_up == 0) {
      ok &= a[i] > last;
    }
    else
      ok &= a[i] < last;
    if (ok) {
      ans.push_back(a[i]);
      // cerr << i << " " << a[i] << endl;
      is_up ^= 1;
      last = a[i];
      --cur;
    }
  }
  reverse(ans.begin(), ans.end());
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < (int)ans.size(); ++i) {
    printf("%d%c", ans[i], i+1 == (int)ans.size() ? '\n' : ' ');
  }
  return 0;
}
