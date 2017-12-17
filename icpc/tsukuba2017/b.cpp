
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> point;
#define x first
#define y second

int n;
vector<point> vp;

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}
int tmp[1 << 16];
void process(vector<point> idx) {
  int nmask = 1 << n;
  for (int i = 0; i < nmask; ++i)
    tmp[i] = 0;
  tmp[0] = 1;
  for (int i = 0; i < nmask; ++i) {
    if (!tmp[i]) continue;
    for (auto it : idx) {
      int cur = (1 << it.first) | (1 << it.second);
      if (cur & i) continue;
      cur |= i;
      tmp[cur] = 1;
    }
  }
}

int tra[1 << 16], dp[1 << 16];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    vp.emplace_back(x, y);
  }
  vector<pair<point, point> > sorted;
  for (int i = 0; i < n; ++i)
    for (int j = i+1; j < n; ++j) {
      int dx = vp[i].x - vp[j].x, dy = vp[i].y - vp[j].y;
      if (dx < 0)
        dx *= -1, dy *= -1;
      int gd = gcd(dx, dy);
      if (gd)
        dx /= gd, dy /= gd;
      sorted.emplace_back(point(dx, dy), point(i, j));
    }
  sort(sorted.begin(), sorted.end());
  int nmask = 1 << n;
  for (int i = 0; i < sorted.size(); ) {
    vector<point> cur;
    point val = sorted[i].x;
    for (; i < sorted.size() && sorted[i].first == val; ++i)
      cur.push_back(sorted[i].y);
    process(cur);
    for (int j = 0; j < nmask; ++j)
      tra[j] |= tmp[j];
  }
  int ans = 0;
  for (int i = 0; i < nmask; ++i) {
    dp[i] = 0;
    if (tra[i]) {
      int cnt = __builtin_popcount(i)/2;
      dp[i] = cnt * (cnt-1)/2;
    }
    for (int j = (i-1) & i; j > 0; j = (j-1) & i) {
      if (tra[j]) {
        int cnt = __builtin_popcount(j)/2;
        dp[i] = max(dp[i], dp[i^j] + cnt * (cnt-1) / 2);
      }
    }
    ans = max(ans, dp[i]);
  }
  printf("%d\n", ans);
  return 0;
}