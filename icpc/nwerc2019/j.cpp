#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5, inf = 1e8 + 7;

int s[N], n;

struct State {
  int dp[2][2];
  State() {
    reset();
  }
  void reset() {
    dp[0][0] = dp[0][1] = dp[1][0] = dp[1][1] = inf;
  }
  void combine(State & a, State & b) {
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        dp[i][j] = min(a.dp[i][1] + b.dp[0][j], a.dp[i][0] + b.dp[1][j]);
        dp[i][j] = min(dp[i][j], inf);
      }
    }
  }
  int get() {
    return min(min(dp[0][0], dp[0][1]), min(dp[1][0], dp[1][1]));
  }
  void debug() {
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j)
        cerr << dp[i][j] << " ";
      cerr << endl;
    }
  }
};

State seg[N << 2];

void build(int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    seg[id].dp[1][0] = seg[id].dp[0][1] = 1;
    if (s[l] < 0)
      seg[id].dp[0][0] = 0;
    else if (s[l] > 0)
      seg[id].dp[1][1] = 0;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  seg[id].combine(seg[il], seg[ir]);
}

void update(int x, int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    seg[id].dp[0][0] = seg[id].dp[1][1] = 0;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    update(x, il, l, mid);
  else
    update(x, ir, mid, r);
  seg[id].combine(seg[il], seg[ir]);
}

int main() {
  int r, c;
  scanf("%d %d %d", &n, &c, &r);
  vector<pair<int, int>> vx;
  for (int i = 0; i < n; ++i) {
    scanf("%d", s+i);
    vx.emplace_back(abs(s[i])+1, i);
  }
  build();
  long long ans = 1LL * seg[1].get() * r;
  sort(vx.begin(), vx.end());
  for (auto it : vx) {
    update(it.second);
    long long cur = 1LL * seg[1].get() * r + 1LL * it.first * c;
    ans = min(ans, cur);
  }
  printf("%lld\n", ans);
  return 0;
}
