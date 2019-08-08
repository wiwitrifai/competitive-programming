#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 6, D = 10, inf = 1e8 + 7;

int cnt[10][10];

char s[N];
int ans[10][10];
int go[10][10];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  for (int i = 0; i + 1 < n; ++i) {
    ++cnt[s[i]-'0'][s[i+1]-'0'];
  }
  memset(ans, -1, sizeof ans);
  for (int x = 0; x < 10; ++x) {
    for (int y = x; y < 10; ++y) {
      for (int i = 0; i < D; ++i) {
        for (int j = 0; j < D; ++j)
          go[i][j] = inf;
        go[i][(i+x) % 10] = 1;
        go[i][(i+y) % 10] = 1;
      }
      for (int k = 0; k < D; ++k) {
        for (int i = 0; i < D; ++i) {
          for (int j = 0; j < D; ++j) {
            go[i][j] = min(go[i][k] + go[k][j], go[i][j]);
          }
        }
      }
      int res = 0;
      for (int i = 0; i < D && res >= 0; ++i) {
        for (int j = 0; j < D && res >= 0; ++j) {
          if (cnt[i][j] == 0) continue;
          if (go[i][j] >= inf) {
            res = -1;
            break;
          }
          res += cnt[i][j] * (go[i][j]-1);
        }
      }
      ans[x][y] = ans[y][x] = res;
    }
  }
  for (int i = 0; i < D; ++i) {
    for (int j = 0; j < D; ++j)
      printf("%d%c", ans[i][j], j == D-1 ? '\n' : ' ');
  }
  return 0;
}
