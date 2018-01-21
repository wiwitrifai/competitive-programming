#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long k;
    int d0, d1;
    cin >> k >> d0 >> d1;
    int sum = 0;
    if (k == 2) {
      sum = d0 + d1;
      sum %= 3;
    }
    else {
      int now = (d0+d1) % 10;
      sum = d0 + d1 + now;
      sum %= 3;
      map<int, int> ans;
      map<pair<int, int>, int> mp;
      int st = -1, en = 3;
      while (en <= k) {
        pair<int, int> cur = {now, sum};
        if (mp.count(cur)) {
          st = mp[cur];
          break;
        }
        mp[cur] = en;
        ans[en] = sum;
        now = (now + now) % 10;
        sum = (sum + now) % 3;
        ++en;
      }
      if (en >= k)
        sum = ans[k];
      else {
        k -= st;
        k %= en-st;
        k += st;
        sum = ans[k];
      }
    }
    puts((sum % 3) == 0 ? "YES" : "NO");
  }
  return 0;
}