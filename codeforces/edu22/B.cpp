#include <bits/stdc++.h>

using namespace std;

int main() {
  set< long long > st;
  long long x, y, l, r;
  cin >> x >> y >> l >> r;
  for (long long xx = 1; xx <= r; xx *= x) {
    for (long long yy = 1; xx+yy <= r; yy *= y) {
      if (xx + yy >= l)
        st.insert(xx+yy);
      if (yy > (r-xx)/y) break;
    }
    if (xx > r/x)
      break;
  }
  long long ans = 0, last = l;
  st.insert(r+1);
  for (auto it : st)
    ans = max(ans, it-last), last = it+1;
  cout << ans << endl;
  return 0;
}