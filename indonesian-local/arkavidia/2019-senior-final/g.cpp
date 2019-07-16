#include <bits/stdc++.h>

using namespace std;

const int N = 102, M = N * N * 5, inf = 1e9 + 8;
#define ALONE 0
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};
char grid[N][N];

int encode(int x, int y, int z) {
  if (grid[x][y] == '#' || grid[x+dx[z]][y+dy[z]] == '#')
    return -1;
  return (x * 101 + y) * 5 + z;
}


vector<pair<int, int> > g[M];


void add_edge(int u, int v, int w) {
  if (u < 0 || v < 0) return;
  g[u].emplace_back(v, w);
  g[v].emplace_back(u, w);
}

int d[M];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int r, c;
    scanf("%d %d", &r, &c);
    vector<pair<int, int> > b;
    int start, end;
    for (int i = 0; i < r; ++i) {
      scanf("%s", grid[i]);
      for (int j = 0; j < c; ++j) {
        if (grid[i][j] == 'B')
          b.emplace_back(i, j);
        else if (grid[i][j] == 'F')
          end = encode(i, j, ALONE);
      }
    }
    if (b.size() == 1)
      start = encode(b[0].first, b[0].second, ALONE);
    else {
      if (b[0].first == b[1].first)
        start = encode(b[0].first, b[0].second, RIGHT);
      else
        start = encode(b[0].first, b[0].second, DOWN);
    }
    for (int i = 0; i < M; ++i)
      g[i].clear();
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (i+1 < r) {
          add_edge(encode(i, j, DOWN), encode(i+1, j, UP), 0);
          if (i+2 < r) {
            add_edge(encode(i+1, j, DOWN), encode(i, j, ALONE), 1);
            add_edge(encode(i+2, j, ALONE), encode(i+1, j, UP), 1);
          }
        }
        if (j+1 < c) {
          add_edge(encode(i, j, RIGHT), encode(i, j+1, LEFT), 0);
          if (j+2 < c) {
            add_edge(encode(i, j+1, RIGHT), encode(i, j, ALONE), 1);
            add_edge(encode(i, j+2, ALONE), encode(i, j+1, LEFT), 1);
          }
        }
        if (i+1 < r && j+1 < c) {
          add_edge(encode(i, j, RIGHT), encode(i+1, j, RIGHT), 1);
          add_edge(encode(i, j+1, LEFT), encode(i+1, j+1, LEFT), 1);
          add_edge(encode(i, j, DOWN), encode(i, j+1, DOWN), 1);
          add_edge(encode(i+1, j, UP), encode(i+1, j+1, UP), 1);
        }
      }
    }
    fill(d, d+M, inf);
    priority_queue<pair<int, int> > pq;
    pq.emplace(0, start);
    d[start] = 0;
    while (!pq.empty()) {
      auto now = pq.top(); pq.pop();
      int v = now.second;
      if (-now.first != d[v]) continue;
      if (v == end) break;
      for (auto nxt : g[v]) {
        int u = nxt.first, w = nxt.second;
        if (d[u] > d[v] + w) {
          d[u] = d[v] + w;
          pq.emplace(-d[u], u);
        }
      }
    }
    if (d[end] >= inf) d[end] = -1;
    printf("%d\n", d[end]);
  }
  return 0;
}