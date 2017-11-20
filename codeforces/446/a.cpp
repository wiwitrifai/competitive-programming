#include <bits/stdc++.h>

using namespace std;

const int N = 2017, inf = 1e9 + 7;

int dp[N][N];
int a[N], to[N];

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

void upd(int &le, int r) {
  le = min(le, r);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  for (int i = 0; i < n; i++) {
    to[i] = i;
    int now = a[i];
    while (now > 1 && to[i] < n) {
      to[i]++;
      if (to[i] < n)
        now = gcd(now, a[to[i]]);
    }
    cerr << i << " " << to[i] << endl;
  }
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      dp[i][j] = inf;
  for (int l = n-1; l >= 0; l--) {
    dp[l][to[l]] = to[l]-l;
    int cur = inf;
    for (int r = l; r < n; r++) {
      cur++;
      cur = min(cur, dp[l][r]);
      dp[l][r] = cur;
      if (dp[l][r] == inf) continue;
      if (r + 1 < n)
        upd(dp[l][to[r+1]], cur + to[r+1]-r+1); 
    }
  }
  if (dp[0][n-1] >= inf)
    dp[0][n-1] = -1;
  printf("%d\n", dp[0][n-1]);
  return 0;
}