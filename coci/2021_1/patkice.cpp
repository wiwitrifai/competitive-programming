#include <bits/stdc++.h>

using namespace std;

char dir[] = "NESW";
char current[] = "^>v<";
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int main() {
  int r, c;
  scanf("%d %d", &r, &c);
  vector<string> board(r);
  for (int i = 0; i < r; ++i) {
    cin >> board[i];
  }
  int rs = -1, cs = -1;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (board[i][j] == 'o') {
        rs = i;
        cs = j;
      }
    }
  }
  const int inf = 1e9 + 7;
  auto go = [&](int u, int v) {
    int ret = 0;
    while (board[u][v] != 'x') {
      ++ret;
      int d = -1;
      for (int j = 0; j < 4; ++j) {
        if (current[j] == board[u][v]) {
          d = j;
        }
      }
      if (d == -1)
        return inf;
      u += dr[d];
      v += dc[d];
    }
    return ret;
  };
  char ansdir = '?';
  int best = inf;
  for (int i = 0; i < 4; ++i) {
    int res = go(rs + dr[i], cs + dc[i]);
    if (res >= inf) continue;
    if (res == best) {
      ansdir = min(ansdir, dir[i]);
    } else if (res < best) {
      ansdir = dir[i];
      best = res;
    }
  }
  if (best >= inf) {
    puts(":(");
  } else {
    puts(":)");
    printf("%c\n", ansdir);
  }
  return 0;
}
