#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;
  int inf = 1e9 + 7;
  int pre = inf, suf = inf;
  int cnta = 0, cntb = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == '1') {
      ++cnta;
      pre = min(pre, i);
      suf = min(suf, n-1-i);
    }
  }
  for (int i = 0; i < m; ++i) {
    if (b[i] == '1') {
      ++cntb;
      pre = min(pre, i);
      suf = min(suf, m-1-i);
    }
  }
  int ans = n + m - 1 - suf - pre;
  if (cnta + cntb == 0)
    ans = 0;
  else if (cnta == 0)
    ans = cntb + n - 1;
  else if (cntb == 0)
    ans = cnta + m - 1;
  cout << ans << endl;
  return 0;
}
