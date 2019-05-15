#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long double PI = acos(-1);

int a[N];

int main() {
  int n, d;
  scanf("%d %d", &n, &d);
  vector<int> batas;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    batas.push_back(a[i]);
    batas.push_back(a[i]+1);
  }
  sort(batas.begin(), batas.end());
  batas.erase(unique(batas.begin(), batas.end()), batas.end());
  int m;
  scanf("%d", &m);
  while (m--) {
    int x;
    scanf("%d", &x);
    int p = lower_bound(a, a+n, x) - a;
    if (p == n) {
      printf("%.15lf\n", (double)atan2(1, x-a[p-1]-1));
      continue;
    }
    if (p > 0 && a[p-1] + 1 == x && a[p] == x) {
      printf("%.15lf\n", (double)PI);
      continue;
    }
    double ans = atan2(1, a[p]-x);
    if (p > 0) {
      ans = max(ans, atan2(1, x-a[p-1]-1));
    }
    int r = lower_bound(batas.begin(), batas.end(), x) - batas.begin();
    int l = r-1;
    if (batas[r] == x)
      ++r;
    int upper = cos(ans/2)/sin(ans/2) + 5;
    while (l >= 0 && r < batas.size()) {
      int lef = x - batas[l], rig = batas[r] - x;
      if (max(lef, rig) > upper) break;
      if (lef == rig) {
        double cur = 2 * atan2(1, lef);
        ans = max(ans, cur);
        break;
      }
      else if (lef < rig)
        --l;
      else
        ++r;
    }
    printf("%.15lf\n", (double)ans);
  }
  return 0;
}
