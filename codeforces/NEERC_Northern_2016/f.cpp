#include <bits/stdc++.h>

using namespace std;

int a, b, c, d;

int main() {
  freopen("folding.in", "r", stdin);
  freopen("folding.out", "w", stdout);
  cin >> a >> b >> c >> d;
  if (a > b)
    swap(a, b);
  if (c > d)
    swap(c, d);
  if (a < c || b < d)
    puts("-1");
  else {
    int ans = 0;
    int cc, dd;
    cc = d; dd = c;
    while (a > c) {
      c <<= 1;
      ans++;
    }
    while (b > d) {
      d <<= 1;
      ans++;
    }
    if (cc <= a && dd <= b) {
      int tmp = 0;
      while (cc < a) cc <<= 1, tmp++;
      while (dd < b) dd <<= 1, tmp++;
      ans = min(ans, tmp);
    }
    cout << ans << endl;
  }

  return 0;
}