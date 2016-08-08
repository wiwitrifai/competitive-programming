#include <bits/stdc++.h>

using namespace std;

int ori[4][4], board[4][4], dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
bool vis[4][4], ada[9];
int tx[9], ty[9], sx[9], sy[9];

bool check(int x, int y) {
  vis[x][y] = true;
  int col = board[x][y];
  if(x == tx[col] && y == ty[col])
    return true;
  for(int i = 0; i<4; i++) {
    int xx = x + dx[i], yy = y + dy[i];
    if(min(xx, yy) >=0 && max(xx, yy) < 4 && !vis[xx][yy] && board[xx][yy] == col)
      if(check(xx, yy))
        return true;
  }
  return false;
}

bool backtrack(int x, int y) {
  if(x >= 4) {
    memset(vis, 0, sizeof vis);
    bool ok = true;
    for(int i = 1; i<=8; i++)
      if(ada[i])
        ok &= check(sx[i], sy[i]);
    return ok;
  }
  else {
    int xx = x, yy = y+1;
    if(yy == 4) {
      yy = 0;
      xx++;
    }
    if(ori[x][y])
      return backtrack(xx, yy);
    else {
      for(int i = 1; i<=8; i++) if(ada[i]) {
        board[x][y] = i;
        if(backtrack(xx, yy))
          return true;
      }
    }
  }
  return false;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    memset(ada, 0, sizeof ada);
    for(int i = 0; i<4; i++)
      for(int j = 0; j<4; j++) {
        int col;
        scanf("%d", &col);
        board[i][j] = ori[i][j] = col;
        if(ada[col]) {
          tx[col] = i, ty[col] = j;
        }
        else {
          sx[col] = i, sy[col] = j;
        }
        ada[col] = true;
      }
    puts(backtrack(0, 0) ? "SOLVABLE" : "UNSOLVABLE");
  }
  return 0;
}