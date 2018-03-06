#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, inf = 1e9 + 7;

int up[N], down[N];

int get1(int x) {
  int ret = inf;
  for (; x < N; x += x&-x)
    ret = min(ret, up[x]);
  return ret;
}
void upd1(int x, int v) {
  for (; x; x -= x&-x)
    up[x] = min(v, up[x]);
}
int get2(int x) {
  int ret = inf;
  for (; x; x -= x&-x)
    ret = min(ret, down[x]);
  return ret;
}
void upd2(int x, int v) {
  for (; x < N; x += x&-x)
    down[x] = min(v, down[x]);
}

int a[N], dp[N];

int main() {
  int n;
  scanf("%d", &n);
  vector<int> val;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    val.push_back(a[i]-i);
    val.push_back(a[i]-i+1);
  }
  sort(val.begin(), val.end());
  val.erase(unique(val.begin(), val.end()), val.end());
  for (int i = 0; i < n; ++i) {
    int now = a[i]-i;
    a[i] = lower_bound(val.begin(), val.end(), now)-val.begin()+1;
  }
  int offset = 0;
  fill(up, up+N, inf);
  fill(down, down+N, inf);
  upd2(1, 0);
  int ans = n-1;
  for (int i = 0; i < n; ++i) {
    dp[i] = get2(a[i]) + offset;
    ++offset;
    upd2(a[i], dp[i]-offset);
    ans = min(ans, dp[i] + max(n-i-2, 0));
  }
  upd1(val.size()+2, 0);
  offset = 0;
  for (int i = n-1; i >= 0; --i) {
    if (i >= 1) {
      int cur = get1(a[i-1]) + offset;
      ans = min(ans, dp[i-1] + cur);
    }
    int cur = get1(a[i]+1) + offset;
    ans = min(ans, cur + max(i-1, 0));
    ++offset;
    upd1(a[i]+1, cur-offset);
  }
  printf("%d\n", ans);
  return 0;
}