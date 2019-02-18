#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[3][N];
char t[N], ans[N];

int main() {
  scanf("%s", t);
  int n = strlen(t);
  for (int i = 0; i < n; ++i) {
    int now = i;
    for (int j = 0; j < 3; ++j) {
      s[j][i] = (now % 26) + 'a';
      now /= 26;
    }
    assert(now == 0);
  }
  for (int j = 0; j < 3; ++j) {
    s[j][n] = 0;
    printf("? %s\n", s[j]);
    fflush(stdout);
    scanf("%s", s[j]);
  }
  for (int i = 0; i < n; ++i) {
    int now = 0;
    for (int j = 2; j >= 0; --j) {
      now = now * 26 + (s[j][i] - 'a');
    }
    ans[now] = t[i];
  }
  ans[n] = 0;
  printf("! %s\n", ans);
  fflush(stdout);
  return 0;
}