#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N], n, fi[N], la[N];
int add[N];
int dp[N];

int main() {
  scanf("%d", &n);
  fill(fi, fi+N, -1);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    la[a[i]] = i;
    if (fi[a[i]] == -1)
      fi[a[i]] = i;
    else
      a[i] = 0;
  }
  for (int i = 0; i < N; ++i) {
    if (fi[i] == -1) continue;
    ++add[fi[i]];
    --add[la[i]];
  }
  int now = 0, sum = 0;
  map<int, long long> mp;
  int cnt = 0;
  mp[0] = 0;
  dp[cnt++] = 0;
  for (int i = 0; i < n; ++i) {
    now ^= a[i];
    sum += add[i];
    if (sum == 0) {
      dp[cnt] = dp[cnt-1];
      auto it = mp.find(now);
      if (it != mp.end()) {
        dp[cnt] = max(dp[cnt], 1 + dp[it->second]);
      }
      mp[now] = cnt;
      ++cnt;
    }
  }
  printf("%d\n", dp[cnt-1]);
  return 0;
}