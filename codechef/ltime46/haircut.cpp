#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 6;
int n;
long long a, b, x[N];
int dp[N], val[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %lld %lld", &n, &a, &b);
    vector< long long > vx;
    for (int i = 0; i < n; i++) {
      scanf("%lld", x+i);
      vx.push_back(x[i]);
      vx.push_back(max(x[i]-a, 0LL));
      vx.push_back(max(x[i]-b, 0LL));
    }
    sort(vx.begin(), vx.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    for (int i = 0, j = 0; i < vx.size(); i++) {
      if (j < n && vx[i] == x[j]) {
        val[i] = 1;
        j++;
      }
      else
        val[i] = 0;
    }
    int ans = 0;
    int tail = 0, off = 0, l = vx.size()-1, r = l;
    deque< pair<int, int> > dq;
    int add = 0;
    for (int i = vx.size()-1; i >= 0; i--) {
      dp[i] = 0;
      while (l >= i && vx[i]+a <= vx[l]) {
        add += val[l];
        off -= val[l];
        if (vx[i] + b >= vx[l]) {
          int now = dp[l] + off;
          while (!dq.empty()) {
            if (dq.front().first <= now)
              dq.pop_front();
            else
              break;
          }
          dq.push_front(make_pair(now, l));
        }
        l--;
      }
      while (r > l && vx[i]+b < vx[r]) {
        tail = max(tail, dp[r]);
        add -= val[r--];
      }
      while (!dq.empty()) {
        if (vx[dq.back().second] > vx[i]+b) {
          dq.pop_back();
        }
        else
          break;
      }
      dp[i] = max(ans, tail + add);
      if (!dq.empty()) {
        dp[i] = max(dp[i], dq.back().first-off);
        // cerr << dq.back().first - off << " " << off << endl;
      }
      // cerr << vx[i] << " " << dp[i] << " " << ans << " " << tail << " " << l << " " << r << endl;
      ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}