#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  vector<int> ans(1, 0);
  map<int, int> last;
  int offset = 0, period = 1;
  while (true) {
    int id = ans.size();
    int res = 0;
    for (int x : a) {
      if (x > id) continue;
      res |= ans[id-x] == 0;
    }
    ans.push_back(res);
    if (id >= 20) {
      int mask = 0;
      for (int i = 0; i < 20; ++i) {
        mask |= (ans[id - i] << i);
      }
      auto it = last.find(mask);
      if (it == last.end()) {
        last[mask] = id;
      } else {
        period = id - it->second;
        offset = it->second;
        break;
      }
    }
  }
  while (q--) {
    long long m;
    scanf("%lld", &m);
    if (m > offset) {
      m -= offset;
      m %= period;
      m += offset;
    }
    puts(ans[m] ? "Elon" : "Melvin");
  }
  return 0;
}
