#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int a[N];

int dp[N][N];
int last[N];
bool used[N];
vector<int> id[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int n;
    scanf("%d", &n);
    vector<int> va;
    for (int i = 0; i < n; i++) {
      scanf("%d", a+i);
      va.push_back(a[i]);
    }
    sort(va.begin(), va.end());
    va.erase(unique(va.begin(), va.end()), va.end());
    for (int i = 0; i < n; i++) {
      a[i] = lower_bound(va.begin(), va.end(), a[i]) - va.begin();
    }
    for (int i = 0; i < n; i++)
      id[i].clear();
    for (int i = 0; i < n; i++)
      id[a[i]].push_back(i);
    memset(last, -1, sizeof last);
    for (int i = 0, l = -1; i < n; i++) {
      l = max(last[a[i]], l);
      last[a[i]] = i;
      for (int j = 0; j <= l; j++)
        dp[j][i] = i-l;
      for (int j = l+1; j <= i; j++)
        dp[j][i] = i-j+1;
    }
    for (int len = 1; len <= n; len++) {
      for (int i = 0; i + len <= n; i++) {
        int r = i+len-1;
        if (i > 0)
          dp[i-1][r] = max(dp[i][r], dp[i-1][r]);
        if (r+1 < n)
          dp[i][r+1] = max(dp[i][r+1], dp[i][r]);
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      set<pair<int, pair<int, int> > > val;
      set<pair<int, int> > range;
      range.insert(make_pair(0, n-1));
      val.insert(make_pair(dp[0][n-1], make_pair(0, n-1)));
      memset(used, 0, sizeof used);
      for (int j = i; j < n; j++) {
        if (used[a[j]]) break;
        used[a[j]] = 1;
        int now = a[j];
        for (int x : id[now]) {
          auto it = range.lower_bound(make_pair(x+1,-1));
          if (it != range.begin()) {
            it--;
            if (x < it->first || x > it->second) continue;
            int l = it->first, r = it->second;
            val.erase(make_pair(dp[l][r], *it));
            range.erase(it);
            if (l < x) {
              val.insert(make_pair(dp[l][x-1], make_pair(l, x-1)));
              range.insert(make_pair(l, x-1));
            }
            if (x < r) {
              val.insert(make_pair(dp[x+1][r], make_pair(x+1, r)));
              range.insert(make_pair(x+1, r));
            }
          }
        }
        int cur = j - i + 1;
        if (!val.empty()) {
          cur += val.rbegin()->first;
        }
        ans = max(ans, cur);
      }
    }
    printf("Case #%d: %d\n", tc, ans);
  }
  return 0;
}