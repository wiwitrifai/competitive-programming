#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int dp[N][N], n, m, k;

char a[N], b[N];

bool cap(char c) {
  return c >= 'A' && c <= 'Z';
}

char toCap(char c) {
  return c - 'a' + 'A';
}

int solve(int x, int y) {
  if (y == m) {
    return x > k;
  }
  if (x == n)
    return 0;
  if (dp[x][y] != -1)
    return dp[x][y];
  dp[x][y] = 0;
  if (cap(a[x])) {
    return dp[x][y] = (a[x] != b[y]) ? 0 : solve(x+1, y+1);
  }
  if (toCap(a[x]) == b[y])
    dp[x][y] |= solve(x+1, y+1);
  dp[x][y] |= solve(x+1, y);
  return dp[x][y];
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(dp, -1, sizeof dp);
    scanf("%s %s", a, b);
    n = strlen(a);
    m = strlen(b);
    k = n-1;
    while (k >= 0 && !cap(a[k])) k--;
    cerr << k << endl;
    puts(solve(0, 0) ? "YES" : "NO");
  }
  return 0;
}