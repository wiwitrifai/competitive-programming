#include <bits/stdc++.h>

using namespace std;

const int N = 5;
int n, m;
// int dx[] = {0, -1, 1, 0}, dy[] = {-1, 0, 0, 1};
int dx[] = {-1, -1, 1, 1}, dy[] = {-1, 1, -1, 1};
// map< long long, int > vis[N * N];

bool solve(int x, int y, long long mask) {
  // cerr << x << " " << y << " " << mask << endl;
  int now = x * m + y;
  // if (vis[now].count(mask))
  //   return vis[now][mask];
  // vis[now][mask] = 0;
  // int ret = 0;
  for (int i = 0; i < 4; i++) {
    int xx = x + dx[i], yy = y + dy[i];
    if (xx < 0 || xx >= n || yy < 0 || yy >= m)
      continue;
    int cur = xx * m + yy;
    if (mask & (1LL<< cur))
      continue;
    long long nmask = mask | (1LL<< cur);
    if (!solve(xx, yy, nmask)) {
      // vis[now][mask] = 1;
      return 1;
    }
  }
  return 0;
}


int main() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      // if (i * j > 16)
      //   break;
      n = i; m = j;
      // for (int k = 0; k < N * N; k++)
      //   vis[k].clear();
      // scanf("%d %d", &n, &m);
      printf("%d ", solve(0, 0, 1));
    }
    printf(" | %d\n", i);
  }
    
  return 0;
}