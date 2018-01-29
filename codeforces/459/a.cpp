#include <bits/stdc++.h>

using namespace std;

const int N = 5050;

char s[N];
int cntl[N][N];
int cntr[N][N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int ans = 0;
  for (int l = 0; l < n; ++l) {
    int now = 0;
    for (int r = l; r < n; ++r) {
      if (s[r] == '(') ++now;
      else if (s[r] == ')') --now;
      else break;
      if (now == 0)
        ++ans;
      else if (now < 0) break;
    }
  }
  for (int l = 0; l < n; ++l) {
    int now = 0;
    for (int r = l; r < n; ++r) {
      if (s[r] == '(') ++now;
      else if (s[r] == ')') --now;
      else {
        ++now;
        ++cntl[r][now];
      }
      if (now < 0) break;
    }
  }
  for (int r = n-1; r >= 0; --r) {
    int now = 0;
    for (int l = r; l >= 0; --l) {
      if (s[l] == ')') ++now;
      else if (s[l] == '(') --now;
      else {
        ++now;
        ++cntr[l][now];
      }
      if (now < 0) break;
    }
  }
  for (int l = 0; l < n; ++l) {
    int now = 0;
    for (int r = l; r < n; ++r) {
      if (s[r] == '(') ++now;
      else if (s[r] == ')') --now;
      else {
        ++now;
      }
      if (now < 0) break;
      if (r+1 < n)
        ans += cntr[r+1][now];
    }
  }
  for (int r = n-1; r >= 0; --r) {
    int now = 0;
    for (int l = r; l >= 0; --l) {
      if (s[l] == ')') ++now;
      else if (s[l] == '(') --now;
      else
        break;
      if (now < 0) break;
      if (l-1 >= 0)
        ans += cntl[l-1][now];
    }
  }
  printf("%d\n", ans);
  return 0;
}