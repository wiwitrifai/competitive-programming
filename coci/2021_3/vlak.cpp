#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, K = 26;

bitset<N> mark[2];

int to[N][K];
int win[N];
int pos[N];
int nodes = 1;

char buffer[N];

void add(int len, int player) {
  int now = 1;
  for (int i = 0; i < len; ++i) {
    int c = buffer[i] - 'a';
    if (to[now][c] == 0) {
      to[now][c] = ++nodes;
      pos[nodes] = i;
    }
    now = to[now][c];
    mark[player][now] = 1;
  }
}

int dfs(int now) {
  if (now == 0)
    return -1;
  int player = (pos[now]+1) & 1;
  int other = !player;
  win[now] = other;
  for (int j = 0; j < K; ++j) {
    int nxt = to[now][j];
    if (nxt == 0 || !mark[player][nxt] || dfs(nxt) == other) continue;
    win[now] = player;
  }
  return win[now];
}

int main() {
  memset(pos, -1, sizeof pos);
  memset(win, -1, sizeof win);
  for (int i = 0; i < 2; ++i) {
    mark[i].reset();
    int n;
    scanf("%d", &n);
    for (int j = 0; j < n; ++j) {
      scanf("%s", buffer);
      int len = strlen(buffer);
      add(len, i);
    }
  }
  printf("%s\n", dfs(1) == 0 ? "Nina" : "Emilija");
  return 0;
}
