#include <bits/stdc++.h>

using namespace std;

const int N = 505, S = 5050;

int d[N][S];
pair<int, int> pre[N][S];

void print(int v, int w) {
  if (v == 0 && w == 0)
    return;
  print(pre[v][w].first, pre[v][w].second);
  printf("%d", w - pre[v][w].second);
}

int main() {
  int n, s;
  scanf("%d %d", &n, &s);
  memset(d, -1, sizeof d);
  d[0][0] = 0;
  queue<pair<int, int> > que;
  que.emplace(0, 0);
  while (!que.empty()) {
    pair<int, int> now = que.front();
    int v = now.first, w = now.second;
    int cur = d[v][w];
    que.pop();
    v = v * 10 % n;
    for (int i = 0; i < 10; ++i) {
      int u = (v + i) % n;
      int x = w + i;
      if (x > s) continue;
      if (d[u][x] != -1) continue;
      d[u][x] = cur + 1;
      pre[u][x] = now;
      que.emplace(u, x);
    }
  }
  if (d[0][s] == -1) {
    puts("-1");
    return 0;
  }
  print(0, s);
  printf("\n");
  return 0;
}