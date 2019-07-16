#include <bits/stdc++.h>

using namespace std;

const int N = 55, inf = 1e9 + 7;

char s[N];
int dp[N][N][2][2];
int v[N];

int solve(int l, int r, int x, int y) {
  if (l == r) {
    int now = s[l];
    now += y;
    if (now >= 10) {
      if (x) return 0;
      else return inf;
    }
    else {
      if (x) return 10-now;
      else return 0;
    }
  }
  else if (l+1 == r) {
    int a = s[l], b = s[r];
    b += y;
    if (b >= 10) b = 0, ++a;
    if (x) {

    }
  }
}

int main() {
  memset(dp, -1, sizeof dp);
  scanf("%s", s);
  int n = strlen(s);
  for (int i = 0; i < n; ++i)
    s[i] -= '0';
  int ret = min(solve(0, n-1, 0, 0), solve(0, n-1, 1, 0));
  return 0;
}