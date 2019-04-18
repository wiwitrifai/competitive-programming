#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

char s[N];
char p[] = "ACTG";

int main() {
  int n;
  scanf("%d %s", &n, s);
  int ans = 1e9;
  for (int i = 0; i + 4 <= n; ++i) {
    int w = 0;
    for (int j = 0; j < 4; ++j) {
      int d = abs(s[i+j] - p[j]);
      w += min(d, 26 - d);
    }
    ans = min(ans, w);
  }
  printf("%d\n", ans);
  return 0;
}
