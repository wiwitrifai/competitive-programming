#include <bits/stdc++.h>

using namespace std;

int main() {
  int r, c;
  int x, y;
  scanf("%d %d %d %d", &r, &c, &x, &y);
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      int dr = abs(i - x), dc = abs(j - y);
      printf("%d%c", max(dr, dc), j == c-1 ? '\n' : ' ');
    }
  }
  return 0;
}
