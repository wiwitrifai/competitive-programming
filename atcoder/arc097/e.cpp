#include <bits/stdc++.h>

using namespace std;

const int N = 4e3 + 4, inf = 1e9 + 7;
struct BIT {
  int n;
  int bit[N][N];
  BIT() : n(N-2) {
    memset(bit, 0, sizeof bit);
  }
  int get(int x, int y) {
    ++x, ++y;
    int yy = y, ret = 0;
    for (; x; x -= x&-x)
      for (y = yy; y <= n; y += y&-y)
        ret += bit[x][y];
    return ret;
  }
  void upd(int x, int y, int v) {
    ++x, ++y;
    int yy = y;
    for (; x <= n; x += x&-x)
      for (y = yy; y; y -= y&-y)
        bit[x][y] += v;    
  }
};

BIT fen[2];
int a[N];
int c[N];
int pos[2][N];
int dp[N][N];

void upd(int & var, int val) {
  if (var > val) var = val;
}

int main() {
  int n;
  scanf("%d", &n);
  fen[0].n = fen[1].n = 2 * n + 2;
  for (int i = 0; i < n * 2; ++i) {
    char col;
    scanf(" %c %d", &col, a+i); --a[i];
    c[i] = col == 'B';
    pos[c[i]][a[i]] = i;
    fen[c[i]].upd(i, a[i], +1);
  }
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j)
      dp[i][j] = inf;
  dp[0][0] = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (i < n) {
        int cost = fen[0].get(pos[0][i], i)-1+fen[1].get(pos[0][i], j);
        upd(dp[i+1][j], dp[i][j] + cost);
      }
      if (j < n) {
        int cost = fen[1].get(pos[1][j], j)-1+fen[0].get(pos[1][j], i);
        upd(dp[i][j+1], dp[i][j] + cost);
      }
    }
  }
  printf("%d\n", dp[n][n]);
  return 0;
}