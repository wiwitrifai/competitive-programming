#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int dp[N][N], len, mod;
char s[N];
int cek(int p, int d) {
  if (p >= len) {
    return d == 0;
  }
  int & ret = dp[p][d];
  if (ret != -1)
    return ret;
  d = d * 10 % mod;
  ret = 0;
  if (s[p] == '?') {
    for (int i = (p == 0); i < 10; ++i) {
      int dd = (d + i) % mod;
      int res = cek(p+1, dd);
      if (res) {
        return ret = 1;
      }
    }
  }
  else {
    d = (d + s[p] - '0') % mod;
    return ret = cek(p+1, d);
  }
  return ret;
}

void backtrack(int p, int d) {
  if (p == len) {
    printf("\n");
    return;
  }
  d = d * 10 % mod;
  if (s[p] == '?') {
    for (int i = (p == 0); i < 10; ++i) {
      int dd = (d + i) % mod;
      int res = cek(p+1, dd);
      if (res) {
        printf("%d", i);
        backtrack(p+1, dd);
        return;
      }
    }
  }
  else {
    printf("%c", s[p]);
    d = (d + s[p] - '0') % mod;
    backtrack(p+1, d);
  }
}

int main() {
  memset(dp, -1, sizeof dp);
  scanf("%s %d", s, &mod);
  len = strlen(s);
  if (!cek(0, 0))
    puts("*");
  else
    backtrack(0, 0);
  return 0;
}