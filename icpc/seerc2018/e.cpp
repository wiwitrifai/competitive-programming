#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int sum[N], ans[N];
vector<pair<int, int> > vx;
int x[N], y[N];

int main() {
  int n, m, l;
  scanf("%d %d %d", &n, &m, &l);
  for (int i = 0; i < n; ++i)
    scanf("%d %d", x+i, y+i);
  for (int i = 0; i < m; ++i) {
    int a;
    scanf("%d", &a);
    vx.emplace_back(a, i);
  }
  sort(vx.begin(), vx.end());
  for (int i = 0; i < n; ++i) {
    if (y[i] > l) continue;
    int le = x[i] - (l - y[i]), ri = x[i] + (l - y[i]);
    le = lower_bound(vx.begin(), vx.end(), make_pair(le, -1)) - vx.begin();
    ri = lower_bound(vx.begin(), vx.end(), make_pair(ri+1, -1)) - vx.begin();
    ++sum[le];
    --sum[ri];
  }
  for (int i = 0; i < m; ++i) {
    sum[i+1] += sum[i];
  }
  for (int i = 0; i < m; ++i) {
    ans[vx[i].second] = sum[i];
  }
  for (int i = 0; i < m; ++i)
    printf("%d\n", ans[i]);
  return 0;
}