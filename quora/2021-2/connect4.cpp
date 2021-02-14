#include <bits/stdc++.h>

using namespace std;

int mat[8][8], h[8];

int main() {
  memset(mat, -1, sizeof mat);
  for (int turn = 1; turn <= 42; ++turn) {
    int c;
    scanf("%d", &c);
    --c;
    int now = turn & 1;
    int r = 0;
    while (mat[r][c] != -1) ++r;
    mat[r][c] = now;
    bool found = false;
    for (int i = 0; i < 6; ++i) {
      for (int j = 0; j < 7; ++j) {
        if (mat[i][j] == -1) continue;
        if (i + 4 <= 6) {
          bool ok = true;
          for (int k = 0; k < 4 && ok; ++k) {
            ok &= mat[i+k][j] == mat[i][j];
          }
          found |= ok;
        }
        if (j + 4 <= 7) {
          bool ok = true;
          for (int k = 0; k < 4 && ok; ++k) {
            ok &= mat[i][j+k] == mat[i][j];
          }
          found |= ok;
        }
        if (i + 4 <= 6 && j + 4 <= 7) {
          bool ok = true;
          for (int k = 0; k < 4 && ok; ++k) {
            ok &= mat[i+k][j+k] == mat[i][j];
          }
          found |= ok;
        }
        if (i + 4 <= 6 && j-3 >= 0) {
          bool ok = true;
          for (int k = 0; k < 4 && ok; ++k) {
            ok &= mat[i+k][j-k] == mat[i][j];
          }
          found |= ok;
        }
      }
    }
    if (found) {
      printf("%s %d\n", now ? "RED" : "YELLOW", turn);
      return 0;
    }
  }
  puts("DRAW");
  return 0;
}
