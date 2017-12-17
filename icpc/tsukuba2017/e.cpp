#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5, inf = 1e9 + 7;

int dp[N], n, k, val[N];
char s[N], t[N];

int main() {
  scanf("%d %d %s %s", &n, &k, s+1, t+1);
  t[0] = 0;
  // genap, ganjil
  deque<int> d1, d2;
  int val1 = 0, val2 = 0;
  int cnt = 0;
  d1.push_back(0);
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i] = inf;
    cnt += (t[i] != t[i-1]);
    if (t[i] != t[i-1] && i > 1) {
      if (cnt & 1)
        val2++;
      else
        val1++;
    }
    while (d1.size() > 0 && d1.front() < i-k) d1.pop_front();
    while (d2.size() > 0 && d2.front() < i-k) d2.pop_front();
    if (d1.size() > 0)
      dp[i] = min(dp[i], val[d1.front()]+val1+1);
    if (d2.size() > 0)
      dp[i] = min(dp[i], val[d2.front()]+val2+1);
    if (t[i] == s[i])
      dp[i] = min(dp[i], dp[i-1]);
    bool pilih1 = ((cnt & 1) && t[i] == t[i+1]) || (((cnt & 1) == 0) && t[i] != t[i+1]);
    if (pilih1) {
      val[i] = dp[i] - val1;
      while (d1.size() > 0) {
        if (val[d1.back()] >= val[i])
          d1.pop_back();
        else
          break;
      }
      d1.push_back(i);
    }
    else {
      val[i] = dp[i] - val2;
      while (d2.size() > 0) {
        if (val[d2.back()] >= val[i])
          d2.pop_back();
        else
          break;
      }
      d2.push_back(i);
    }
  }
  printf("%d\n", dp[n]);
  return 0;
}