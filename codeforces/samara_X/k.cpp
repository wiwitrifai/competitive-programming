#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N], b[N], c[N];
vector< int > vv;
vector< int > id[N];
pair<long long, long long > dp[N];
long long dur[N];
int use[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", a+i, b+i, c+i);
    vv.push_back(a[i]);
    vv.push_back(b[i]);
    dur[i] = b[i]-a[i];
  }
  sort(vv.begin(), vv.end());
  vv.erase(unique(vv.begin(), vv.end()), vv.end());
  int m = vv.size();
  for (int i = 0; i < n; i++) {
    a[i] = lower_bound(vv.begin(), vv.end(), a[i]) - vv.begin() + 1;
    b[i] = lower_bound(vv.begin(), vv.end(), b[i]) - vv.begin() + 1;
    id[b[i]].push_back(i);
  }
  dp[0] = {0, 0};
  use[0] = -1;
  for (int i = 1; i <= m; i++) {
    dp[i] = dp[i-1];
    use[i] = use[i-1];
    for (int x : id[i]) {
      pair< long long, long long > cur = dp[a[x]];
      cur.first += c[x];
      cur.second -= dur[x];
      if (dp[i] < cur) {
        dp[i] = cur;
        use[i] = x;
      }
    }
  }
  vector< int > ans;
  int now = use[m];
  while (now >= 0) {
    ans.push_back(now);
    now = use[a[now]];
  }
  sort(ans.begin(), ans.end());
  printf("%d %I64d %I64d\n", ans.size(), dp[m].first, -dp[m].second);
  for (int i = 0; i < ans.size(); i++) {
    if (i)
      printf(" ");
    printf("%d", ans[i]+1);
  }
  printf("\n");
  return 0;
}