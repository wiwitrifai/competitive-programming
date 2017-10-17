#include <bits/stdc++.h>

using namespace std;

map<int, int> mp;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    mp[b] |= 1 << (a-1);
  }
  int last = 0, r = 0;
  bool ok = 1;
  for (auto it : mp) {
    int now = it.first, mask = it.second;
    r ^= (now-1-last) & 1;
    last = now-1;
    if (mask & (1 << r)) {
      ok = 0;
      break;
    }
    else
      if (mask == 0)
        r ^= 1;
    now = last;
  }
  puts(ok ? "Yes" : "No");
  return 0;
}