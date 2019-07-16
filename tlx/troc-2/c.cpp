#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;

int n, p, t, v, d;
int x[N], h[N];

int main() {
  scanf("%d %d %d %d %d", &n, &p, &t, &v, &d);
  for (int i = 0; i < n; ++i)
    scanf("%d", x+i);
  for (int i = 0; i < n; ++i)
    scanf("%d", h+i);
  vector<int> vx;
  for (int i = 0; i < n; ++i) {
    vx.push_back(x[i]);
    vx.push_back(x[i]+p);
  }
  sort(vx.begin(), vx.end());
  vx.erase(unique(vx.begin(), vx.end()), vx.end());
  vector<int> mins;
  mins.assign(vx.size(), t);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j + 1 < vx.size(); ++j)
      if (x[i] <= vx[j] && vx[j+1] <= x[i] + p)
        mins[j] = min(mins[j], h[i]); 
  }
  double ans = 0;
  for (int i = 0; i + 1 < vx.size(); ++i) {
    ans += (double)(t - mins[i]) * (vx[i+1] - vx[i]);
  }
  ans *= (double)d/v;
  printf("%6lf\n", ans);
  return 0;
}