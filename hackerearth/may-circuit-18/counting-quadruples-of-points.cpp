#include <bits/stdc++.h>
 
using namespace std;
 
const long double eps = 1e-9;
 
typedef pair<int, int> point;
#define x first
#define y second
 
long double dist(point a, point b) {
  int dx = a.x - b.x, dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}
 
int dist2(point a, point b) {
  int dx = a.x - b.x, dy = a.y - b.y;
  return dx * dx + dy * dy;
}
 
const int N = 256;
 
point vp[N];
long double val[N];
 
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    vp[i] = {x, y};
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      int cnt = 0;
      for (int k = 0; k < n; ++k) {
        if (k == i || k == j) continue;
        val[cnt++] = dist(vp[k], vp[i]) - dist(vp[k], vp[j]);
      }
      sort(val, val+cnt);
      long double now = val[0];
      int cur = 0;
      for (int k = 0; k < cnt; ++k) {
        if (fabs(now - val[k]) > eps) {
          cur = 0;
          now = val[k];
        }
        ans += cur;
        ++cur;
      }
    }
  }
  printf("%lld\n", ans * 4);
  return 0;
}