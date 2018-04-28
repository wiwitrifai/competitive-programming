#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 4;

struct point {
  int x, y;
  point(int x = 0, int y = 0) : x(x), y(y) {};
};
long long dist(point a, point b) {
  long long dx = a.x - b.x, dy = a.y - b.y;
  return dx * dx + dy * dy;
}

point vp[N];
long long dp[N][N];

int main() {
  int n, q;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    vp[i] = point(x, y);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j)
      dp[i][j] = dist(vp[i], vp[j]);
  }
  for (int len = 0; len < n; ++len) {
    for (int i = 0; i + len+1 < n; ++i) {
      dp[i][i+len+1] = max(dp[i][i+len+1], max(dp[i][i+len], dp[i+1][i+len+1]));
    }
  }
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l;
    --r;
    printf("%lld\n", dp[l][r]);
  }
  return 0;
}