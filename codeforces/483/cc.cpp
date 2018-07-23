#include <bits/stdc++.h>

using namespace std;

const int N = 2048;

bitset<N * 100000> vis;

vector<int> hapus[10][10][10][10][10];
vector<int> tambah[10][10][10][10][10][10];
int to[1000000];

int a[N], b[N];
int sorted[4];
int enc(int s, int u, int v, int w, int x, int pos) {
  sorted[0] = u;
  sorted[1] = v;
  sorted[2] = w;
  sorted[3] = x;
  sort(sorted, sorted+4);
  u = sorted[0], v = sorted[1], w = sorted[2], x = sorted[3];
  return pos * 100000 + x * 10000 + w * 1000 + v * 100 + u * 10 + s;
}
void deco(int val, int & s, int & u, int & v, int & w, int & x, int & pos) {
  s = val % 10; val /= 10;
  u = val % 10; val /= 10;
  v = val % 10; val /= 10;
  w = val % 10; val /= 10;
  x = val % 10; val /= 10;
  pos = val;
}

void unique(vector<int> & v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}

int main() {
  for (int s = 1; s <= 9; ++s) {
    for (int u = 0; u < 10; ++u) {
      for (int v = 0; v < 10; ++v) {
        for (int w = 0; w < 10; ++w) {
          for (int x = 0; x < 10; ++x) {
            if (s == u) {
              hapus[s][u][v][w][x].push_back(enc(s, 0, v, w, x, 0));
            }
            if (s == v) {
              hapus[s][u][v][w][x].push_back(enc(s, u, 0, w, x, 0));
            }
            if (s == w) {
              hapus[s][u][v][w][x].push_back(enc(s, u, v, 0, x, 0));
            }
            if (s == x) {
              hapus[s][u][v][w][x].push_back(enc(s, u, v, w, 0, 0));
            }
            unique(hapus[s][u][v][w][x]);
            for (int baru = 1; baru <= 9; ++baru) {
              if (0 == u)
                tambah[s][u][v][w][x][baru].push_back(enc(s, baru, v, w, x, 0));
              if (0 == v)
                tambah[s][u][v][w][x][baru].push_back(enc(s, u, baru, w, x, 0));
              if (0 == w)
                tambah[s][u][v][w][x][baru].push_back(enc(s, u, v, baru, x, 0));
              if (0 == x)
                tambah[s][u][v][w][x][baru].push_back(enc(s, u, v, w, baru, 0));
              unique(tambah[s][u][v][w][x][baru]);
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
  queue<int> one, zero;
  int now = 0;
  zero.push(enc(1, 0, 0, 0, 0, 0));
  vis[zero.front()] = 1;
  int done = n * 10000;
  bool found = 0;
  while (!found) {
    while (!zero.empty()) {
      auto it = zero.front(); zero.pop();
      one.push(it);
      if (it/10 == done) {
        found = 1;
        break;
      }
      int s, u, v, w, x, pos;
      deco(it, s, u, v, w, x, pos);
      for (int nx : hapus[s][u][v][w][x]) {
        int id = nx + pos * 100000;
        if (!vis[id]) {
          zero.push(id);
          vis[id] = 1;
        }
      }
      if (pos < n && s == a[pos]) {
        for (int nx : tambah[s][u][v][w][x][b[pos]]) {
          int id = nx + (pos+1) * 100000;
          if (!vis[id]) {
            zero.push(id);
            vis[id] = 1;
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
        int nx = enc(s-1, u, v, w, x, pos);
        if (!vis[nx]) {
          zero.push(nx);
          vis[nx] = 1;
        }
      }
      if (s < 9) {
        int nx = enc(s+1, u, v, w, x, pos);
        if (!vis[nx]) {
          zero.push(nx);
          vis[nx] = 1;
        }
      }
    }
  }
  printf("%d\n", now+2*n);
  return 0;
}