#include <bits/stdc++.h>

using namespace std;

const int N = 606;

int b[N][N];
int a[N][N];

int main() {
  int h, w, x, y;
  scanf("%d %d %d %d", &h, &w, &x, &y);
  for (int i = 0; i < h+x; ++i) {
    for (int j = 0; j < w+y; ++j) {
      scanf("%d", b[i]+j);
    }
  }
  for (int i = h-1; i >= 0; --i) {
    for (int j = 0; j < w; ++j) {
      a[i][j] = b[i+x][j+y];
    }
    for (int j = 0; j < w; ++j) {
      b[i+x][j+y] -= a[i][j];
      b[i][j] -= a[i][j];
    }
  }
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      printf("%d%c", a[i][j], j == w-1 ? '\n' : ' ');
    }
  }
    
  return 0;
}
