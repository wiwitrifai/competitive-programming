#include <bits/stdc++.h>

using namespace std;


int main() {

  map<int, long long> ev;
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < q; ++i) {
    int t, a, b;
    scanf("%d %d %d", &t, &a, &b);
    if (t == 1) {
      ev[1] += b;
      if (a+1 <= n)
        ev[a+1] -= b;
    }
    else {
      a = n-a+1;
      ev[a] -= b;
    }
  }
  long long ans = 0;
  long long now = 0;
  for (auto it : ev) {
    if (it.first > n) break;
    now += it.second;
    // cerr << it.first << " " << now << endl;
    ans = max(ans, abs(now));
  }
  printf("%lld\n", ans);
  return 0;
}