#include <bits/stdc++.h>

using namespace std;

void solve() {
  string a, b;
  cin >> a >> b;
  int d = __gcd(a.size(), b.size());
  string c = a + b;
  bool ok = true;
  for (int s = 0; s < (int)c.size(); s += d) {
    for (int i = 0; i < d; ++i) {
      if (c[i] != c[i+s]) {
        ok = false;
      }
    }
  }
  if (ok) {
    string ans = "";
    int cnt = (int)b.size() / d;
    for (int i = 0; i < cnt; ++i)
      ans += a;
    cout << ans << "\n";
  } else {
    cout << -1 << "\n";
  }

}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
