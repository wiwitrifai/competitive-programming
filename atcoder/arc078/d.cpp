#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

vector< int > g[N];

int c[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  queue< int > que;
  c[0] = 1;
  c[n-1] = 2;
  que.push(0);
  que.push(n-1);
  int black = 0, white = 0;
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    if (c[v] == 1) black++;
    else white++;
    for (int u : g[v]) if (!c[u]) {
      c[u] = c[v];
      que.push(u);
    }
  }
  puts(black > white ? "Fennec" : "Snuke");

  return 0;
}