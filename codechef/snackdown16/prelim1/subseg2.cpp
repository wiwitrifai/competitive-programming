#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, NLOG = 18;

int n, q, par[NLOG][N], dp[N];
pair< int, int > r[N], p[N];
int main() {
  scanf("%d%d", &n, &q);
  for(int i = 0; i<n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    r[i] = make_pair(x, y);
  }
  sort(r, r+n);
  int now = 0;
  p[now] = r[n-1];
  for(int i = n-2; i>=0; i--) {
    if(p[now].second > r[i].second)
      p[++now] = r[i];
  }
  now++;
  sort(p, p+now);
  dp[now] = 0;
  memset(par, -1, sizeof par);
  for(int i = now-1; i>=0; i--) {
    int x = upper_bound(p, p+now, make_pair(p[i].second+1, 0)) - p;
    par[0][i] = x >= now ? -1 : x;
    dp[i] = dp[x] + 1;
  }
  for(int i = 0; i+1<NLOG; i++)
    for(int j = 0; j<now; j++)
      if(par[i][j] != -1)
        par[i+1][j] = par[i][par[i][j]];
  while(q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    x = lower_bound(p, p+now, make_pair(x, 0)) - p;
    if(p[x].second > y || x >= now) {
      puts("0");
      continue;
    }
    int z = x;
    for(int i = NLOG-1; i>=0; i--) {
      // cerr << par[i][z] << " " << y << endl;
      if(par[i][z] != -1 && p[par[i][z]].second <= y)
        z = par[i][z];
    }
    int ans = max(0, dp[x] - dp[z] + 1);
    printf("%d\n", ans);
  }
  return 0;
}