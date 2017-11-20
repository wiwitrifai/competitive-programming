#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const long double inf = 1e18, eps = 1e-9;
const int iter = 400;

double dp[N][N * 100];
bool vis[N][N * 100];

int n, r, f[N], s[N], p[N];
double st;
double solve(int lv, int now) {
  if (now > r)
    return st;
  if (lv == n)
    return 0;
  if (vis[lv][now]) return dp[lv][now];
  vis[lv][now] = 1;
  double & ret = dp[lv][now];
  double pp = (double)p[lv]/100.0;
  ret = pp * (f[lv] + solve(lv+1, now + f[lv])) + (1.0 - pp) * (s[lv] + solve(lv+1, now + s[lv]));
  if (lv || now)
    ret = min(ret, st);
  return ret;
}

int main() {
  scanf("%d %d", &n, &r);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", f+i, s+i, p+i);
  }
  memset(vis, 0, sizeof vis);
  double lo = 0, hi = inf;
  st = inf;
  double cur = solve(0, 0);
  while (cur > hi) {
    hi *= 2;
    memset(vis, 0, sizeof vis);
    double cur = solve(0, 0);  
  }
  for (int it = 0; it < iter; it++) {
    st = (lo + hi) / 2.0;
    memset(vis, 0, sizeof vis);
    double res = solve(0, 0);
    if (res < st)
      hi = st;
    else
      lo = st;
  }
  printf("%.20lf\n", lo);
  return 0;
}