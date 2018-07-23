#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> fac[N];
int n, a[N];
vector<pair<int, int> > dp[N];
map<int, int> last;

int main() {
  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j += i)
      fac[j].push_back(i);
  }
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += a[i] == 0;
  }
  if (a[0] != 0) ++ans;
  for (int i = 0; i < n; ++i) {
    int pos = abs(a[i]);
    for (int d : fac[pos]) {
      {
        int cnt = 1;
        int v = a[i] / d;
        auto itlast = last.find(v);
        if (itlast != last.end()) {
          int pre = itlast->second;
          auto it = lower_bound(dp[pre].begin(), dp[pre].end(), make_pair(d, -1));
          if (it != dp[pre].end() && it->first == d) {
            cnt = it->second + 1;
          }
          else
            cnt = 2;
        }
        dp[i].emplace_back(d, cnt);
        ans = max(ans, cnt);
      }
      d *= -1;
      {
        int cnt = 1;
        int v = a[i] / d;
        auto itlast = last.find(v);
        if (itlast != last.end()) {
          int pre = itlast->second;
          auto it = lower_bound(dp[pre].begin(), dp[pre].end(), make_pair(d, -1));
          if (it != dp[pre].end() && it->first == d) {
            cnt = it->second + 1;
          }
          else
            cnt = 2;
        }
        dp[i].emplace_back(d, cnt);
        ans = max(ans, cnt);
      }
    }
    sort(dp[i].begin(), dp[i].end());
    last[a[i]] = i;
  }
  printf("%d\n", ans);
  return 0;
}