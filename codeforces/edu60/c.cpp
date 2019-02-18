#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;

char s[N];
int idx[256];
int dx[] = {0, 0, -1, 1};
int dy[] = {+1, -1, 0, 0};
int xa, ya, xb, yb;
int n;
int xx[N], yy[N];

long long calc(long long t, long long cx, long long dy) {
  long long d = t / n, r = t - d * n;
  long long x = xx[r] + d * cx, y = yy[r] + d * dy;
  return abs(x) + abs(y) - t;
}

int main() {
  idx['U'] = 0;
  idx['D'] = 1;
  idx['L'] = 2;
  idx['R'] = 3;
  scanf("%d %d %d %d %d", &xa, &ya, &xb, &yb, &n);
  scanf("%s", s);
  int cx = 0, cy = 0;
  for (int i = 0; i < n; ++i) {
    xx[i] = xa + cx - xb;
    yy[i] = ya + cy - yb;
    int c = idx[s[i]];
    cx += dx[c];
    cy += dy[c];
  }
  long long l = 0, r = inf;
  while (l < r) {
    long long mid = (l + r) >> 1;
    if (calc(mid, cx, cy) <= 0)
      r = mid;
    else
      l = mid + 1; 
  }
  long long ans = l >= inf ? -1 : l;
  printf("%lld\n", ans);
  return 0;
}