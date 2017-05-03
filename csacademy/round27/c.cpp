#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9+7;

int c[100500];

int main() {
  vector< pair< int, int > > ev;
  int n, m;
  scanf("%d %d",&n, &m);
  for (int i= 0; i < n; i++) {
    int l, r, a;
    scanf("%d %d %d", &l, &r, &a);
    ev.emplace_back(l, a);
    if (l > 1) {
      ev.emplace_back(1, inf);
      ev.emplace_back(l, -inf);
    }
    ev.emplace_back(r+1, -a);
    if (r+1 <= m)
      ev.emplace_back(r+1, inf);
  }
  sort(ev.begin(), ev.end());
  int ans, cnt;
  ans = cnt = 0;
  for (auto it : ev) {
    if (it.second > 0) {
      if (it.second >= inf) it.second = 0;
      if (c[it.second] == 0) cnt++;
      c[it.second]++;
    } else {
      it.second *= -1;
      if (it.second >= inf) it.second = 0;
      c[it.second]--;
      if (c[it.second] == 0) cnt--;
    }
    ans = max(ans, cnt);
  }
  printf("%d\n", ans);
  return 0;
}