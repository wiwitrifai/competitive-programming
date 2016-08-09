#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

bool bx[N], by[N];

int nx, ny, n, m;

int main() {
  scanf("%d%d", &n, &m);
  nx = ny = n;
  while(m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    nx -= !bx[x];
    ny -= !by[y];
    bx[x] = 1;
    by[y] = 1;
    printf("%I64d ", 1LL* nx * ny);
  }
  printf("\n");
  return 0;
}