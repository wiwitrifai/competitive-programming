#include <bits/stdc++.h>

using namespace std;

const int N = 1000;

int dp[N];

int f(int x) {
  if (dp[x] != -1)
    return dp[x];
  set<int> st;
  int now = 0;
  for (int i = 0; i < x; ++i) {
    st.insert(now);
    now ^= f(x-1-i);
  }
  dp[x] = 0;
  for (int v : st) {
    if (dp[x] != v) break;
    dp[x]++;
  }
  return dp[x];
}

int main() {
  memset(dp, -1, sizeof dp);
  dp[0] = 0;
  for (int i = 0; i < 15; ++i)
    cout << i << " " << f(i) << endl;
  return 0;
}