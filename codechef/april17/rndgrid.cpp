#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int n, l;
char s[5 * N];
char b[N][N];
int ans[N][N];
int tmp[2 * N][2 * N];
vector< pair< pair< int, int >, int > > mov;

int solve1() {
  cerr << "solve1" << endl;
  memset(tmp, -1, sizeof tmp);
  int x = N, y = N;
  tmp[x][y] = 0;
  for (int i = 0; i < l; i++) {
    switch (s[i]) {
      case 'U':
        x--; break;
      case 'D':
        x++; break;
      case 'L':
        y--; break;
      case 'R':
        y++; break;
    }
    assert(x >= 0 && x < 2 * N && y >= 0 && y < 2 * N);
    if (tmp[x][y] == -1) {
      tmp[x][y] = i;
      mov.push_back({{x-N, y-N}, i});
      // cerr << " move " << (x-N) << " " << (y-N) << " " << i << endl;
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (b[i][j] == '#')
        ans[i][j] = 0;
      else
        ans[i][j] = l;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (b[i][j] != '#') continue;
      for (auto it : mov) {
        x = i-it.first.first, y = j-it.first.second;
        if (x < 0 || x >= n || y < 0 || y >= n) continue;
        ans[x][y] = min(ans[x][y], it.second);
      }
    }
  }
  int ret = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      ret ^= ans[i][j];
  return ret;
}
int solve2() {
  cerr << "solve2" << endl;
  memset(tmp, -1, sizeof tmp);
  int x = N, y = N;
  for (int i = 0; i < l; i++) {
    switch (s[i]) {
      case 'U':
        x--; break;
      case 'D':
        x++; break;
      case 'L':
        y--; break;
      case 'R':
        y++; break;
    }
    assert(x >= 0 && x < 2 * N && y >= 0 && y < 2 * N);
    if (tmp[x][y] == -1) {
      tmp[x][y] = i;
      mov.push_back({{x-N, y-N}, i});
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j< n; j++) {
      ans[i][j] = 0;
      if (b[i][j] == '#') continue;
      ans[i][j] = l;
      for (auto it : mov) {
        int x = i + it.first.first, y = j + it.first.second;
        if (b[x][y] == '#') {
          ans[i][j] = it.second;
          break;
        }
      }
    }
  int ret = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      ret ^= ans[i][j];
  // for (int i = 0; i < n; i++) {
  //   b[i][n] = 0;
  //   printf("%s\n", b[i]);
  // }
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++)
  //     cerr << ans[i][j] << " ";
  //   cerr << endl;
  // }

  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &l, &n);
    scanf("%s", s);
    for (int i = 1; i <= n; i++) {
      scanf("%s", b[i]+1);
    }
    for (int i = 0; i <= n+1; i++) {
      b[i][0] = b[i][n+1] = b[0][i] = b[n+1][i] = '#';
    }
    n += 2;
    int block = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        block += b[i][j] == '#';
    }
    int emp = n * n - block;
    int ans = 0;
    mov.clear();
    if (block < emp)
      ans = solve1();
    else
      ans = solve2();
    printf("%d\n", ans);
  }
  return 0;
}