#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> d(n);
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &d[i]);
    sum += d[i];
  }
  vector<long long> fact;
  for (long long i = 1; i <= n && i * i <= sum; ++i) {
    if (sum % i) continue;
    fact.push_back(i);
    long long y = sum / i;
    if (y != i)
      fact.push_back(y);
  }
  int ans = n+1;
  vector<long long> rem(n);
  for (long long x : fact) {
    long long cnt = sum / x;
    if (cnt > n || cnt < 3) continue;
    long long cur = 0;
    for (int i = 0; i < n; ++i) {
      rem[i] = cur;
      cur = (cur + d[i]) % x;
    }
    sort(rem.begin(), rem.end());
    bool ok = false;
    for (int i = 0; i + cnt <= n; ++i) {
      if (rem[i] == rem[i+cnt-1]) {
        ok = true;
        break;
      }
    }
    if (ok)
      ans = min(ans, n - (int)cnt);
  }
  if (ans > n)
    ans = -1;
  printf("%d\n", ans);
  return 0;
}
