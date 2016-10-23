/**
  IEEExtreme Programming Contest 10
  Problem : Checkers Challange
  Solver  : Wiwit Rifa'i
  Status  : Still Wrong Answer :"(
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 16;
char s[8][8];
// pos x bitmask x king ? x direction
long long dp[64][1 << 16][2][4];
bool vis[64][1 << 16][2][4];

int id[8][8], dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
bool valid(int a, int b) {
  return a >= 0 && b >= 0 && a < 8 && b < 8;
}

struct state {
  int pos, mask, king, dir;
  state() : pos(-1) {
  }
  state(int pos, int mask, int king, int dir) : pos(pos), mask(mask), king(king), dir(dir) {
  }
  void update(long long val) {
    dp[pos][mask][king][dir] += val;
  }
  long long get() {
    return dp[pos][mask][king][dir];
  }
  state find() {
    int a = (pos / 8) + dx[dir], b = pos % 8 + dy[dir];
    while (valid(a, b)) {
      if (id[a][b] >= 0 && (mask & (1<<id[a][b]))) {
        break;
      }
      a += dx[dir];
      b += dy[dir];
    }
    if (!valid(a, b))
      return state();
    assert(mask & (1<<id[a][b]));
    return state(a * 8 + b, mask ^ (1<<id[a][b]), king, dir);
  }
  void go() {
    if (pos < 0)
      return;
    int a = pos / 8, b = pos % 8;
    a += dx[dir];
    b += dy[dir];
    if (!valid(a, b))
      pos = -1;
    else
      pos = a * 8 + b;
    if (a <= 0)
      king = 1;
  }
  bool black() {
    if (pos < 0)
      return false;
    int a = pos / 8, b = pos % 8;
    if (id[a][b] < 0)
      return false;
    return (1<< id[a][b]) & mask;
  }
  void remove() {
    int a = pos / 8, b = pos % 8;
    if (id[a][b] >= 0 && (mask & (1<<id[a][b])))
      mask ^= 1<<id[a][b];
  }
  void debug() {
    cerr << pos/8 << "," << pos % 8 << " " << mask << " " << king << " " << dir << " " << dp[pos][mask][king][dir] << endl;;
  }
  bool isvisit() {
    return vis[pos][mask][king][dir];
  }
  void visit() {
    vis[pos][mask][king][dir] = true;
  }
};

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < 8; i++) {
      scanf("%s", s[i]);
    }
    memset(dp, 0, sizeof dp);
    int cnt = 0, start = -1;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j  < 8; j++) {
        id[i][j] = -1;
        if (s[i][j] == 'o')
          start = i * 8 + j;
        else if (s[i][j] == 'x') {
          id[i][j] = cnt++;
        }
      }
    }
    memset(vis, 0, sizeof vis);
    queue< state > que;
    for (int i = 0; i < 4; i++) {
      int king = start < 8;
      state tmp = state(start, (1<<cnt)-1, king, i);
      // tmp.debug();
      if (king) {
        state nx = tmp.find();
        nx.go();
        while (!nx.black() && nx.pos >= 0) {
          nx.update(1);
          // nx.visit();
          if (!nx.isvisit()) {
            que.push(nx);
            nx.visit();
          }
          nx.go();
        }
      }
      else {
        if (i == 0)
          continue;
        tmp.go();
        if (tmp.pos < 0)
          continue;
        if (!tmp.black())
          continue;
        tmp.go();
        tmp.remove();
        if (tmp.pos < 0)
          continue;
        if (tmp.black())
          continue;
        tmp.update(1);
        if (!tmp.isvisit()) {
          que.push(tmp);
          tmp.visit();
        }
      }
    }
    while (!que.empty()) {
      state tmp = que.front();
      que.pop();
      // tmp.debug();
      int dir = tmp.dir;
      long long cost = tmp.get();
      bool king = tmp.king;
      for (int i = 0; i < 4; i++) {
        if (i + dir == 3)
          continue;
        if (!king && i == 0)
          continue;
        tmp.dir = i;
        if (king) {
          state nx = tmp.find();
          nx.go();
          while (!nx.black() && nx.pos >= 0) {
            nx.update(cost);
            if (!nx.isvisit()) {
              que.push(nx);
              nx.visit();
            }
            nx.go();
          }
        }
        else {
          state nx = tmp;
          nx.go();
          if (nx.pos < 0)
            continue;
          if (!nx.black())
            continue;
          nx.go();
          nx.remove();
          if (nx.pos < 0)
            continue;
          if (nx.black())
            continue;
          if (!nx.isvisit()) {
            que.push(nx);
            nx.visit();
          }
          nx.update(cost);
        }
      }
    }
    long long ans = 0;
    for (int i = 0; i < 64; i++) {
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 4; k++) {
          ans += dp[i][0][j][k];
        }
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
