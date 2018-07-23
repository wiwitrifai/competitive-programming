#include <bits/stdc++.h>

using namespace std;

const int N = 2048;

bitset<N> vis[10][10][10][10][10];

vector<tuple<int, int, int, int, int, int>> hapus[10][10][10][10][10];
vector<tuple<int, int, int, int, int, int>> tambah[10][10][10][10][10][10];

int a[N], b[N];
tuple<int, int, int, int, int, int> enc(int s, int u, int v, int w, int x, int pos) {
  // return pos * 100000 + x * 10000 + w * 1000 + v * 100 + u * 10 + s;
  return make_tuple(s, u, v, w, x, pos);
}
void deco(tuple<int, int, int, int, int, int> val, int & s, int & u, int & v, int & w, int & x, int & pos) {
  tie(s, u, v, w, x, pos) = val;
  // s = val % 10; val /= 10;
  // u = val % 10; val /= 10;
  // v = val % 10; val /= 10;
  // w = val % 10; val /= 10;
  // x = val % 10; val /= 10;
  // pos = val;
}

int main() {
  for (int s = 1; s <= 9; ++s) {
    for (int u = 0; u < 10; ++u) {
      for (int v = 0; v < 10; ++v) {
        for (int w = 0; w < 10; ++w) {
          for (int x = 0; x < 10; ++x) {
            if (s == u) {
              hapus[s][u][v][w][x].emplace_back(enc(s, 0, v, w, x, 0));
            }
            if (s == v) {
              hapus[s][u][v][w][x].emplace_back(enc(s, u, 0, w, x, 0));
            }
            if (s == w) {
              hapus[s][u][v][w][x].emplace_back(enc(s, u, v, 0, x, 0));
            }
            if (s == x) {
              hapus[s][u][v][w][x].emplace_back(enc(s, u, v, w, 0, 0));
            }
            for (int baru = 1; baru <= 9; ++baru) {
              if (0 == u)
                tambah[s][u][v][w][x][baru].emplace_back(enc(s, baru, v, w, x, 0));
              if (0 == v)
                tambah[s][u][v][w][x][baru].emplace_back(enc(s, u, baru, w, x, 0));
              if (0 == w)
                tambah[s][u][v][w][x][baru].emplace_back(enc(s, u, v, baru, x, 0));
              if (0 == x)
                tambah[s][u][v][w][x][baru].emplace_back(enc(s, u, v, w, baru, 0));
            }
          }
        }
      }
    }
  }
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d %d", a+i, b+i);
  queue<tuple<int, int, int, int, int, int>> one, zero;
  int now = 0;
  zero.push(enc(1, 0, 0, 0, 0, 0));
  vis[1][0][0][0][0][0] = 1;
  int done = n * 10000;
  bool found = 0;
  while (!found) {
    while (!zero.empty()) {
      auto it = zero.front(); zero.pop();
      one.push(it);
      int s, u, v, w, x, pos;
      deco(it, s, u, v, w, x, pos);
      if ((u + v + w + x) == 0 && pos == n) {
        found = 1;
        break;
      }
      for (auto nx : hapus[s][u][v][w][x]) {
        int ts, tu, tv, tw, tx, tpos;
        deco(nx, ts, tu, tv, tw, tx, tpos);
        tpos = pos;
        if (!vis[ts][tu][tv][tw][tx][tpos]) {
          zero.push(enc(ts, tu, tv, tw, tx, tpos));
          vis[ts][tu][tv][tw][tx][tpos] = 1;
        }
      }
      if (pos < n && s == a[pos]) {
        for (auto nx : tambah[s][u][v][w][x][b[pos]]) {
          int ts, tu, tv, tw, tx, tpos;
          deco(nx, ts, tu, tv, tw, tx, tpos);
          tpos = pos+1;
          if (!vis[ts][tu][tv][tw][tx][tpos]) {
            zero.push(enc(ts, tu, tv, tw, tx, tpos));
            vis[ts][tu][tv][tw][tx][tpos] = 1;
          }
        }
      }
    }
    if (found) break;
    ++now;
    while (!one.empty()) {
      auto it = one.front(); one.pop();
      int s, u, v, w, x, pos;
      deco(it, s, u, v, w, x, pos);
      if (s > 1) {
        if (!vis[s-1][u][v][w][x][pos]) {
          zero.push(enc(s-1, u, v, w, x, pos));
          vis[s-1][u][v][w][x][pos] = 1;
        }
      }
      if (s < 9) {
        if (!vis[s+1][u][v][w][x][pos]) {
          zero.push(enc(s+1, u, v, w, x, pos));
          vis[s+1][u][v][w][x][pos] = 1;
        }
      }
    }
  }
  printf("%d\n", now+2*n);
  return 0;
}