#include <bits/stdc++.h>

using namespace std;

int r[4], c[4];

char dir[] = "UDLR";
int dr[] = {-1, +1, 0, 0};
int dc[] = {0, 0, -1, +1};

void move(int x, char ch) {
  for (int i = 0; i < 4; ++i) {
    if (dir[i] != ch) continue;
    r[x] += dr[i];
    c[x] += dc[i];
  }
}

char find(int rr, int cc) {
  for (int i = 0; i < 4; ++i) {
    if (r[3] + dr[i] == rr && c[3] + dc[i] == cc) {
      return dir[i];
    }
  }
  assert(false);
}

char buffer[10];

int main() {
  scanf("%s", buffer);
  while (buffer[0] != 'S') {
    vector<int> plus, minus;
    for (int i = 0; i < 3; ++i) {
      move(i, buffer[i]);
      plus.push_back(r[i]+c[i]);
      minus.push_back(r[i]-c[i]);
    }
    sort(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());
    int rr = (plus[1] + minus[1]) / 2, cc = (plus[1] - minus[1]) / 2;
    char ans = find(rr, cc);
    move(3, ans);
    printf("%c\n", ans);
    fflush(stdout);
    scanf("%s", buffer);
  }
  return 0;
}
