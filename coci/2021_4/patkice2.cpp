#include <bits/stdc++.h>

using namespace std;

char dir[] = "^>v<";
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

const int inf = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> board(n);
  for (int i = 0; i < n; ++i) {
    cin >> board[i];
  }
  auto enc = [&](int r, int c) {
    return r * m + c;
  };
  vector<int> pre(n * m, -1), dist(n * m, inf);
  int s = 0, t = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (board[i][j] == 'o')
        s = enc(i, j);
      else if (board[i][j] == 'x')
        t = enc(i, j);
    }
  }
  priority_queue<pair<int, int>> pq;
  pq.emplace(0, s);
  dist[s] = 0;
  while (!pq.empty()) {
    int d, v;
    tie(d, v) = pq.top();
    pq.pop();
    d = -d;
    if (dist[v] != d) continue;
    int r = v / m, c = v % m;
    for (int i = 0; i < 4; ++i) {
      int rr = r + dr[i], cc = c + dc[i];
      if (rr < 0 || rr >= n || cc < 0 || cc >= m) continue;
      int u = enc(rr, cc);
      int cost = (board[r][c] != 'o' && board[r][c] != 'x' && board[r][c] != dir[i]);
      int newdist = d + cost;
      if (newdist < dist[u]) {
        dist[u] = newdist;
        pre[u] = v;
        pq.emplace(-newdist, u);
      }
    }
  }
  cout << dist[t] << '\n';
  while (t != s && s != pre[t]) {
    int v = pre[t];
    int rv = v / m, cv = v % m;
    int rt = t / m, ct = t % m;
    for (int i = 0; i < 4; ++i) {
      if (rv + dr[i] == rt && cv + dc[i] == ct) {
        board[rv][cv] = dir[i];
      }
    }
    t = v;
  }
  for (int i = 0; i < n; ++i)
    cout << board[i] << '\n';
  return 0;
}
