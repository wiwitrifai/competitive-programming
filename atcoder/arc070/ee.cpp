#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int dp[N + N][N + N];
int l[N], r[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d %d", l+i, r+i);
  for (int i = 0; i < N; i++) {
    dp[0][i] = abs(i-l[0]);
    // if (i < 20)
    //   cerr << i << " ";
  }
  // cerr << endl;
  for (int i = 0; i + 1 < n; i++) {
    int sbef = r[i]-l[i], snow = r[i+1]-l[i+1];
    deque< int > dq;
    for (int j = 0; j < min(snow, N); j++) {
      while (!dq.empty()) {
        if (dq.front() > dp[i][j])
          dq.pop_front();
        else
          break;
      }
      dq.push_front(dp[i][j]);
    }
    for (int j = 0; j < N; j++) {
      if (j + snow < N) {
        while (!dq.empty()) {
          if (dq.front() > dp[i][j+snow])
            dq.pop_front();
          else
            break;
        }
        dq.push_front(dp[i][j+snow]);
      }
      if (dq.empty()) continue;
      dp[i+1][j] = abs(l[i+1]-j) + dq.back();
      if (j-sbef >= 0 && dq.back() == dp[i][j-sbef])
        dq.pop_back();
      // if (j < 20)
      //   cerr << dp[i+1][j] << " ";
    }
    // cerr << i+ 1<< endl;
  }
  int ans = dp[n-1][0];
  for (int i = 0; i < 444; i++)
    ans = min(ans, dp[n-1][i]);
  cout << ans << endl;
  return 0;
}