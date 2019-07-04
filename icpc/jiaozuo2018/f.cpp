#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

vector<int> g[N];
string buff;
int r, c;
int enc(int x, int y) {
  if (x < 0 || x >= r || y < 0 || y >= c)
    return -1;
  return x * c + y;
}

int dist[N];

void solve() {
  int s = -1, t = -1;
  cin >> r >> c;
  int nodes = r * c;
  for (int i = 0; i < nodes; ++i) {
    g[i].clear();
  }
  getline(cin, buff);
  for (int i = 0; i < 4 * r + 3; ++i) {
    getline(cin, buff);
    if ((i % 4) == 0) {
      for (int j = 0; j < c; j += 2) {
        if (buff[4 + j * 6] == ' ') {
          int x = i / 4;
          int u = enc(x-1, j), v = enc(x, j);
          if (u == -1 || v == -1)
            continue;
          g[u].push_back(v);
          g[v].push_back(u);
        }
      }
      for (int j = 1; j < c; j += 2) {
        if (buff[4 + j * 6] == 'S') {
          s = enc(i/4 - 1, j);
        }
        else if (buff[4 + j * 6] == 'T') {
          t = enc(i/4 - 1, j);
        }
      }
    }
    else if ((i % 4) == 1) {
      for (int j = 0; j < c; ++j) {
        if (buff[1 + j * 6] == ' ') {
          int x = i / 4;
          int u, v;
          if (j & 1)
            u = enc(x, j-1), v = enc(x-1, j);
          else
            u = enc(x-1, j-1), v = enc(x, j);
          if (u == -1 || v == -1) continue;
          g[u].push_back(v);
          g[v].push_back(u);
        }
      }
    }
    else if ((i % 4) == 2) {
      for (int j = 1; j < c; j += 2) {
        if (buff[4 + j * 6] == ' ') {
          int x = i / 4;
          int u = enc(x-1, j), v = enc(x, j);
          if (u == -1 || v == -1) continue;
          g[u].push_back(v);
          g[v].push_back(u);
        }
      }
      for (int j = 0; j < c; j += 2) {
        if (buff[4 + j * 6] == 'S') {
          s = enc(i/4, j);
        }
        else if (buff[4 + j * 6] == 'T') {
          t = enc(i/4, j);
        }
      }
    }
    else {
      for (int j = 0; j < c; ++j) {
        if (buff[1 + j * 6] == ' ') {
          int x = i / 4;
          int u, v;
          u = enc(x, j-1), v = enc(x, j);
          if (u == -1 || v == -1) continue;
          g[u].push_back(v);
          g[v].push_back(u);
        }
      }
    }
  }
  assert(s != -1 && t != -1);
  fill(dist, dist+nodes, -1);
  dist[s] = 1;
  queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int v = que.front(); que.pop();
    for (int u : g[v]) {
      if (dist[u] != -1) continue;
      dist[u] = dist[v] + 1;
      que.push(u);
    }
  }
  cout << dist[t] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
