#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

struct fen {
  vector<int> bit;
  int get(int x) {
    int r = 0;
    for (; x; x-= x&-x)
      r = max(r, bit[x]);
    return r;
  }
  void upd(int x, int v) {
    for (; x < bit.size(); x += x&-x)
      bit[x] = max(bit[x], v);
  }
};

fen dp[N];
vector<int> val[N];
int a[N], b[N], w[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d %d", a+i, b+i, w+i);
    --a[i], --b[i];
    val[b[i]].push_back(w[i]);
  }
  for (int i = 0; i < n; ++i) {
    val[i].push_back(-1);
    sort(val[i].begin(), val[i].end());
    val[i].erase(unique(val[i].begin(), val[i].end()), val[i].end());
    dp[i].bit.assign(val[i].size()+1, 0);
  }
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    int u = a[i], v = b[i];
    int id = upper_bound(val[u].begin(), val[u].end(), w[i]) - val[u].begin();
    int p = dp[u].get(id);
    ans = max(ans, p+1);
    id = lower_bound(val[v].begin(), val[v].end(), w[i]) - val[v].begin();
    dp[v].upd(id+1, p+1);
  }
  printf("%d\n", ans);
  return 0;
}