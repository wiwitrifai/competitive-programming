#include <bits/stdc++.h>

using namespace std;

const string NAME = "generators";

const int N = 1e4 + 5, M = 1024, inf = 1e9 + 7;

int pos[N][M], c[N];
int ans[N];
int main() {
  freopen((NAME + ".in").c_str(), "r", stdin);
  freopen((NAME + ".out").c_str(), "w", stdout);
  int n, k;
  scanf("%d %d", &n, &k);
  int tot = 0;
  for (int i = 0; i < n; ++i) {
    int x, a, b;
    scanf("%d %d %d %d", &x, &a, &b, c+i);
    memset(pos[i], -1, sizeof pos[i]);
    for (int j = 0; pos[i][x] == -1; ++j, x = (x * a + b) % c[i]) {
      pos[i][x] = j;
    }
    for (int j = c[i]-1; j >= 0; --j) if (pos[i][j] != -1) {
      ans[i] = j;
      tot += j;
      break;
    }
  }
  if (tot % k) {
    printf("%d\n", tot);
    for (int i = 0; i < n; ++i) {
      printf("%d%c", pos[i][ans[i]], (i == n-1) ? '\n' : ' ');
    }
    return 0;
  }
  int sel = -1, best = inf, to;
  for (int i = 0; i < n; ++i) {
    int cur = ans[i];
    int g = -1;
    for (int j = cur-1; j >= 0; --j) if (pos[i][j] != -1) {
      if ((cur - j) % k) {
        g = j;
        break;
      }
    }
    if (g != -1) {
      if (best > cur - g) {
        best = cur - g;
        sel = i;
        to = g;
      }
    }
  }
  if (sel == -1)
    puts("-1");
  else {
    tot -= best;
    ans[sel] = to;
    printf("%d\n", tot);
    for (int i = 0; i < n; ++i) {
      printf("%d%c", pos[i][ans[i]], (i == n-1) ? '\n' : ' ');
    }
  }
  return 0;
}