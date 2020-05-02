#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5, LN = 19;
int n;
pair< int, int > st[N];
int dp[N][2];
int sp[LN][N];
int bit[N];
void upd(int x, int v) {
  for (; x; x -= x&(-x))
    bit[x] = min(bit[x], v);
}
int get(int x) {
  int ret = n;
  for (; x <= n; x += x&(-x))
    ret = min(ret, bit[x]);
  return ret;
}
int sp_get(int l, int r) {
  int len = r-l+1;
  int lg = 31 - __builtin_clz(len);
  return min(sp[lg][r], sp[lg][l+(1<<lg)-1]);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x, h;
    scanf("%d %d", &x, &h);
    st[i] = make_pair(x, h);
    dp[i][0] = dp[i][1] = n;
  }
  sort(st, st+n);
  for (int i = 0; i < LN; i++)
    for (int j = 0; j < n; j++)
      sp[i][j] = n;
  for (int i = 0; i <= n; i++)
    bit[i] = n;
  int left = 0, right = 0;
  for (int i = 0; i < n; i++) {
    int x = st[i].first, h = st[i].second, id;
    if (i == 0)
      dp[0][0] = dp[0][1] = left = right = 1;
    else {
      id = lower_bound(st, st+n, make_pair(x - h, -1)) - st;
      if (id <= i-1)
        dp[i][0] = min(dp[i][0], sp_get(id, i-1));
      if (id > 0) {
        id--;
        dp[i][0] = min(min(dp[id][0], dp[id][1]) + 1, dp[i][0]);
      }
      dp[i][1] = min(min(dp[i-1][0], dp[i-1][1]) + 1, get(i+1));
      int dist = x - st[i-1].first;
      int le = min(left + (dist > st[i].second), right + 1), ri = min(left + 1, right + (dist > st[i-1].second));
      left = le, right = ri;
    }
    sp[0][i] = dp[i][0];
    for (int j = 0; (1 << (j+1)) <= i+1; j++) {
      sp[j+1][i] = min(sp[j][i], sp[j][i - (1<<j)]);
    }
    id = lower_bound(st, st+n, make_pair(x + h + 1, -1)) - st;
    // cerr << i << " " << id << " " << dp[i][1] << " " << get(i+1) << endl;
    upd(id, dp[i][1]);
  }
  printf("%d\n", min(min(left, right), min(dp[n-1][0], dp[n-1][1])));
  return 0;
}