#include <bits/stdc++.h>

using namespace std;

const int N = 6e5 + 5;

int a[N], b[N];
int prv[N], dp[N];

pair<int, int> bit[N];
void reset() {
  for (int i = 0; i < N; ++i)
    bit[i] = {0, -1};
}

pair<int, int> get(int x) {
  pair<int, int> res = {0, -1};
  for (; x; x -= x&-x)
    res = max(res, bit[x]);
  return res;
}

void upd(int x, pair<int, int> v) {
  for (; x < N; x += x&-x)
    bit[x] = max(bit[x], v);
}

int main() {
  vector<int> incr, decr;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", a+i, b+i);
    if (a[i] < b[i])
      incr.push_back(i);
    else
      decr.push_back(i);
  }
  memset(prv, -1, sizeof prv);
  vector<int> ans;
  fill(dp, dp+n, 1);
  {
    reset();
    sort(incr.begin(), incr.end(), [](int l, int r) { return a[l] < a[r]; });
    for (int u : incr) {
      auto res = get(b[u]);
      dp[u] = res.first + 1;
      prv[u] = res.second;
      upd(a[u], {dp[u], u});
    }
  }
  {
    reset();
    sort(decr.begin(), decr.end(), [](int l, int r) { return b[l] < b[r]; });
    for (int u : decr) {
      auto res = get(a[u]);
      dp[u] = res.first + 1;
      prv[u] = res.second;
      upd(b[u], {dp[u], u});
    }
  }
  int best = 0;
  for (int i = 0; i < n; ++i)
    if (dp[i] > dp[best])
      best = i;
  int now = best;
  while (now != -1) {
    ans.push_back(now+1);
    now = prv[now];
  }
  if (a[best] > b[best])
    reverse(ans.begin(), ans.end());
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < ans.size(); ++i)
    printf("%d%c", ans[i], i+1 == ans.size() ? '\n' : ' ');

  return 0;
}
