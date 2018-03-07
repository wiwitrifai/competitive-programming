#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5, B = 30, inf = 1e9;

int dp[N], d[N], l[N], h[N], n, s, t, pre[N];
pair<int, int> bit[B][N];

pair<int, int> get(int b, int x) {
  pair<int, int> ret = {inf, inf};
  ++x;
  for (; x < N; x += x&-x)
    ret = min(ret, bit[b][x]);
  return ret;
}

void updmin(int b, int x, pair<int, int> val) {
  ++x;
  for (; x; x -= x&-x)
    bit[b][x] = min(bit[b][x], val);
}

void reset(int b, int x) {
  ++x;
  for (; x; x-= x&-x)
    bit[b][x] = {inf, inf};
}

int main() {
  scanf("%d %d %d", &n, &s, &t);
  d[0] = -inf;
  dp[0] = s;
  set<pair<int, int> > st;
  for (int i = 0; i < B; ++i)
    for (int j = 0; j < N; ++j)
      bit[i][j] = {inf, inf};
  int dnow = 0, offset = 0;
  for (int i = 1, j = 0; i <= n; ++i) {
    scanf("%d %d %d", d+i, l+i, h+i);
    while (dnow < d[i]) {
      ++dnow; --offset;
      if (offset < 0) offset = B-1;
      while (dnow-d[j] >= B) {
        st.insert(make_pair(dp[j], j));
        if (dp[j] >= 0)
          reset(offset, dp[j]);
        ++j;
      }
    }
    dp[i] = -inf;
    auto it = st.lower_bound(make_pair(l[i], -1));
    if (it != st.end())
      dp[i] = h[i], pre[i] = it->second;
    for (int k = 1, offs = offset; k < B; ++k) {
      ++offs;
      if (offs >= B) offs = 0;
      pair<int, int> res = get(offs, l[i]);

      int f = res.first;
      if (f >= N) continue;
      f += t;
      f >>= (k-1);
      int now = h[i] - f;
      if (dp[i] < now) {
        dp[i] = now;
        pre[i] = res.second;
      }
    }
    if (dp[i] >= 0)
      updmin(offset, dp[i], make_pair(h[i]-dp[i], i));
  }
  int last = 0, ans = dp[0];
  for (int i = 1; i <= n; ++i) {
    if (ans < dp[i])
      ans = dp[i], last = i;
  }
  vector<int> idx;
  while (last) idx.push_back(last), last = pre[last];
  printf("%d %d\n", ans, idx.size());
  reverse(idx.begin(), idx.end());
  for (int x : idx)
    printf("%d ", x);
  printf("\n");
  return 0;
}