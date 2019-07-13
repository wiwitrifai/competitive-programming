#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;


void win() {
  puts("tokitsukaze");
  exit(0);
}

void lose() {
  puts("quailty");
  exit(0);
}

void draw() {
  puts("once again");
  exit(0);
}

char s[N];
vector<int> pos[2];

int main() {
  int n, k;
  scanf("%d %d %s", &n, &k, s);
  for (int i = 0; i < n; ++i) {
    pos[s[i] - '0'].push_back(i);
  }
  if (pos[0].empty() || pos[1].empty()) {
    win();
  }
  if (pos[0].back() - pos[0][0] < k || pos[1].back() - pos[1][0] < k)
    win();
  for (int l = 0; l+k <= n; ++l) {
    int r = l+k-1;
    for (int x = 0; x < 2; ++x) {
      int y = x^1;
      int lx = min(pos[x][0], l), rx = max(pos[x].back(), l+k-1);
      int ly = pos[y][0], ry = pos[y].back();
      if (ly >= l && ly <= r) {
        ly = lower_bound(pos[y].begin(), pos[y].end(), r+1) - pos[y].begin();
        if (ly >= (int)pos[y].size())
          draw();
        ly = pos[y][ly];
      }
      if (ry >= l && ry <= r) {
        ry = lower_bound(pos[y].begin(), pos[y].end(), l) - pos[y].begin() - 1;
        if (ry < 0)
          draw();
        ry = pos[y][ry];
      }
      if ((ry -ly) >= k && (rx - lx) >= k) {
        draw();
      }
    }
  }
  lose();
  return 0;
}
