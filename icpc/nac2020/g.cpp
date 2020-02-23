#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7;

int main() {
  int n, p, q, s;
  scanf("%d %d %d %d", &n, &p, &q, &s);
  vector<int> a(p), b(q);
  for (int i = 0; i < p; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < q; ++i) {
    scanf("%d", &b[i]);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int low = 0, hig = inf;
  while (low < hig) {
    int mid = (low + hig) >> 1;
    set<pair<int, int>> sa, sb;
    for (int i = 0; i < p; ++i) {
      sa.insert(make_pair(a[i], i));
    }
    for (int i = 0; i < q; ++i) {
      sb.insert(make_pair(b[i], i));
    }
    int cnt = 0;
    while (cnt < n && !sa.empty() && !sb.empty()) {
      auto ita = --sa.end();
      auto itb = --sb.end();
      if (ita->first > itb->first) {
        int now = ita->first;
        sa.erase(ita);
        auto itt = sb.lower_bound(make_pair(s-now+1, -1));
        if (itt != sb.begin()) {
          --itt;
          if (abs(now - itt->first) <= mid) {
            sb.erase(itt);
            ++cnt;
          }
        }
      }
      else {
        int now = itb->first;
        sb.erase(itb);
        auto itt = sa.lower_bound(make_pair(s-now+1, -1));
        if (itt != sa.begin()) {
          --itt;
          if (abs(now - itt->first) <= mid) {
            sa.erase(itt);
            ++cnt;
          }
        }
      }
    }
    if (cnt >= n)
      hig = mid;
    else
      low = mid + 1;
  }
  if (low >= inf)
    low = -1;
  printf("%d\n", low);
  return 0;
}
