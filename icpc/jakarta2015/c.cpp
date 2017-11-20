#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int a[N], b[N];
vector<int> id[N];
map<int, int > ans[N];
int n, q;

int solve(int x, int y) {
  auto it = ans[x].find(y);
  if (it != ans[x].end())
    return it->second;
  int cur = 0, last = -1, now = 0;
  while (last < n-1) {
    now += y;
    while (now <= id[x].size() && id[x][now-1] - last < b[y-1]) now++;
    if (now > id[x].size()) break;
    last = id[x][now-1];
    cur++;
  }
  cur += last < n-1;
  return ans[x][y] = cur;
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++ ) {
    printf("Case #%d:\n", tc);
    scanf("%d %d", &n, &q);
    vector<int> val;
    for (int i = 0; i < n; i++)
      scanf("%d", a+i), val.push_back(a[i]);
    for (int i = 0; i < n; i++)
      scanf("%d", b+i);
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    for (int i = 0; i < val.size(); i++)
      id[i].clear(), ans[i].clear();
    for (int i = 0; i < n; i++) {
      int x = lower_bound(val.begin(),val.end(), a[i]) - val.begin();
      id[x].push_back(i);
    }
    while (q--) {
      int x, y;
      scanf("%d %d", &x, &y);
      int ix = lower_bound(val.begin(), val.end(), x) - val.begin();
      if (ix == val.size() || val[ix] != x) {
        puts("1");
        continue;
      }
      printf("%d\n", solve(ix, y));
    }
  }
  return 0;
}