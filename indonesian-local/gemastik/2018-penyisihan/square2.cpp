#include <bits/stdc++.h>

using namespace std;

int t, d;
int f(int n, int m) {
  if (n <= 0 || m <= 0)
    return 0;
  return (n * m + 1) / 2;
}
int g(int xa, int xb, int ya, int yb) {
  return f(xb+1, yb+1) - f(xa, yb+1) - f(xb+1, ya) + f(xa, ya);
}
long long calc(int ox, int oy, int n, int m) {
  long long ans = 0;
  int ax0 = 0, ax1 = -1, bx = 0, cx = 0;
  int ay0 = 0, ay1 = -1, by = 0, cy = 0;
  if (ox > d) {
    int w = ox-d;
    ax0 = t-w;
    ax1 = t-1;
    int hapus = max(0, w-n);
    ax1 = max(ax0-1, ax1-hapus);
  }
  n = max(n-ox, 0);
  bx = (n + d) / (t+d);
  n = max(n - bx * (t+d), 0);
  cx = n;
  if (oy > d) {
    int w = oy-d;
    ay0 = t-w;
    ay1 = t-1;
    int hapus = max(0, w-m);
    ay1 = max(ay0-1, ay1-hapus);
  }
  m = max(m-oy, 0);
  by = (m + d) / (t+d);
  m = max(m - by * (t+d), 0);
  cy = m;
  ans = 1LL * bx * by * f(t,t);
  ans = ans + g(ax0, ax1, ay0, ay1) + g(ax0, ax1, 0, cy-1) + g(0, cx-1, ay0, ay1) + f(cx, cy);
  ans += 1LL * bx * (g(0, t-1, ay0, ay1) + f(t, cy)); 
  ans += 1LL * by * (g(0, t-1, ax0, ax1) + f(t, cx)); 
  return ans;
}

const int N = 111;

int xa[N], ya[N], xb[N], yb[N];

int main() {
  int n, m, l;
  scanf("%d %d %d %d", &n, &m, &t, &d);
  scanf("%d", &l);
  for (int i = 0; i < l; ++i)
    scanf("%d %d %d %d", xa+i, ya+i, xb+i, yb+i);
  long long ans = 0;
  int s = t+d;
  for (int i = 0; i < s; ++i) {
    for (int j = 0; j < s; ++j) {
      int x0 = (s-i) % s, y0 = (s-j) % s;
      long long now = calc(i, j, n, m);
      for (int k = 0; k < l; ++k) {
        int dn = xb[k] - xa[k] + 1, dm = yb[k] - ya[k] + 1;
        int ofx = (i-xa[k]) % s, ofy = (j-ya[k]) % s;
        if (ofx < 0) ofx += s;
        if (ofy < 0) ofy += s;
        long long cur = calc(ofx, ofy, dn, dm);
        now -= cur;
      }
      ans = max(ans, now);
    }
  }
  printf("%lld\n", ans);
  return 0;
}