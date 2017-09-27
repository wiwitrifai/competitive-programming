#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int a[N][N], n, m;

pair<long long, int> get(int h) {
  int cnt = 0;
  long long v = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) if (a[i][j] <= h) {
      v += h - a[i][j];
      cnt++;
    }
  }
  return make_pair(v, cnt);
}

int main() {
  int v;
  scanf("%d %d %d", &n, &m, &v);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", a[i]+j);
    }
  }
  int low = 0, hi = 2e6;
  while (low < hi) {
    int mid = (low + hi + 1) / 2;
    if (get(mid).first > v)
      hi = mid-1;
    else
      low = mid;
  }
  pair<long long, int > res = get(low);
  double ans = low + (double)(v - res.first) / res.second;
  printf("%.3lf\n", ans);
  return 0;
}