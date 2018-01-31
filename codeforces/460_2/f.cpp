#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > state;
map<vector<int>, int> mp;
vector<int> cur(5);

void generate(int id = 0, int sisa = 8) {
  if (id == 5 && sisa == 0)
    mp[cur] = state.size(), state.push_back(cur);
  else if (id < 5) {
    for (cur[id] = 0; cur[id] <= sisa; ++cur[id]) {
      generate(id+1, sisa-cur[id]);
    }
  }
}
int tot = 495;
int dout[505][505];
vector<pair<int, int> > g[505][505];
int ans[505][505];

int main() {
  generate();
  tot = state.size();
  for (int i = 0; i < tot; ++i) {
    for (int j = 0; j < tot; ++j) {
      for (int k = 1; k < 5; ++k) {
        if (state[i][k] == 0) continue;
        for (int l = 1; l < 5; ++l) {
          if (state[j][l] == 0) continue;
          cur = state[i];
          --cur[k];
          ++cur[(k + l) % 5];
          int id = mp[cur];
          g[j][id].push_back(make_pair(i, j));
          dout[i][j]++;
        }
      }
    }
  }
  queue<pair<int, int> > que;
  memset(ans, -1, sizeof ans);
  for (int i = 0; i < tot; ++i)
    for (int j = 0; j < tot; ++j)
      if (dout[i][j] == 0) {
        int cnt =0;
        ans[i][j] = 0;
        que.emplace(i, j);
      }
  while (!que.empty()) {
    int a, b;
    tie(a, b) = que.front(); que.pop();
    int & res = ans[a][b];
    if (res < 0) res = 0;
    for (auto it : g[a][b]) {
      --dout[it.first][it.second];
      if (res == 0 && dout[it.first][it.second] >= 0) {
        ans[it.first][it.second] = 1;
        dout[it.first][it.second] = 0;
        que.push(it);
      }
      else if (dout[it.first][it.second] == 0) {
        que.push(it);
      }
    }
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b;
    int f;
    scanf("%d", &f);
    cur.assign(5, 0);
    for (int i = 0; i < 8; ++i) {
      int x;
      scanf("%d", &x);
      ++cur[x];
    }
    a = mp[cur];
    cur.assign(5, 0);
    for (int i = 0; i < 8; ++i) {
      int x;
      scanf("%d", &x);
      ++cur[x];
    }
    b = mp[cur];
    if (f == 0) {
      if (ans[a][b] == -1)
        puts("Deal");
      else if (ans[a][b] == 1)
        puts("Alice");
      else
        puts("Bob");
    }
    else {
      swap(a, b);
      if (ans[a][b] == -1)
        puts("Deal");
      else if (ans[a][b] == 0)
        puts("Alice");
      else
        puts("Bob");
    }
  }
  return 0;
}