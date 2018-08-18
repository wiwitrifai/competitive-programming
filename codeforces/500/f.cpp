#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int arr[N], dp[N], s[N], pre[N], pos[N];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }
  int m = 0;
  for (int i = 1; i <= n; ++i) {
    int id = lower_bound(s+1, s+m+1, arr[i]) - s;
    pre[i] = pos[id-1];
    dp[i] = dp[pre[i]] + 1;
    s[dp[i]] = arr[i];
    pos[dp[i]] = i;
    m = max(m, id); 
  }
  return 0;
}