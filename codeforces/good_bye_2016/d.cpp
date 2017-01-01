#include <bits/stdc++.h>

using namespace std;

const int N = 333, OFF = 152;

bool mark[N][N];
int t[N], n;
bool geser[N];
bool vis[N][N][8][OFF];
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
struct state {
  int x, y, dir;
  int pos;
  state(int x, int y, int dir, int pos) : x(x), y(y), dir(dir), pos(pos) {
  }
  void visit() {
    vis[OFF+x][OFF+y][dir][pos] = 1;
  }
  bool visited() {
    return vis[OFF+x][OFF+y][dir][pos];
  }
  void print() {
    cout << x << " " << y << " " << dir << " " << pos << endl;
  }
};

int main() {
  scanf("%d", &n);
  int now = 0;
  memset(geser, 0, sizeof geser);
  memset(vis, 0, sizeof vis);
  for (int i = 0; i < n; i++) {
    scanf("%d", t+i);
    now += t[i];
    geser[now-1] = 1;
  }
  state init(0, 0, 0, 0);
  queue < state > que;
  init.visit();
  que.push(init);
  memset(mark, 0, sizeof mark);
  now--;
  while (!que.empty()) {
    state cur = que.front();
    mark[OFF + cur.x][OFF+cur.y] = 1;
    que.pop();
    if (cur.pos == now)
      continue;
    if (geser[cur.pos]) {
      state a = cur, b = cur;
      a.dir--;
      if (a.dir < 0)
        a.dir = 7;
      a.pos++;
      a.x += dx[a.dir];
      a.y += dy[a.dir];
      if (!a.visited()) {
        que.push(a);
        a.visit();
      }
      b.dir++;
      if (b.dir > 7)
        b.dir = 0;
      b.pos++;
      b.x += dx[b.dir];
      b.y += dy[b.dir];
      if (!b.visited()) {
        b.visit();
        que.push(b);
      }
    }
    else {
      cur.x += dx[cur.dir];
      cur.y += dy[cur.dir];
      cur.pos++;
      if (!cur.visited()) {
        cur.visit();
        que.push(cur);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      ans += mark[i][j];
    }
  }
  printf("%d\n", ans);
  return 0;
}