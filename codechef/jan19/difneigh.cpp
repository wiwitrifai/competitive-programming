#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int ans[N][N], tmp[N][N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    bool revs = 0;
    if (n > m)
      swap(n, m), revs = 1;
    if (n == 1) {
      if (m == 1) {
        puts("1\n1");
        continue;
      }
      else if (m == 2) {
        puts("1\n1 1");
        continue;
      }
      puts("2");
      for (int i = 0; i < m; ++i)
        ans[0][i] = ((i % 4) / 2) + 1;
    }
    else if (n == 2) {
      if (m == 2)
        puts("2");
      else
        puts("3");
      for (int i = 0; i < m; ++i) {
        ans[0][i] = ans[1][i] = (i % 3) + 1;
      }
    }
    else {
      puts("4");
      for (int i = 0; i < n; ++i) {
        ans[i][0] = (i % 4) + 1;
        ans[i][1] = ((i + 2) % 4) + 1;
      }
      for (int j = 2; j < m; ++j) {
        if (j & 1) {
          for (int i = 0; i < n; ++i)
            ans[i][j] = ans[i][j-3];
        }
        else {
          for (int i = 0; i < n; ++i)
            ans[i][j] = ans[i][j-1];
        }
      }
    }
    if (revs) {
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
          tmp[j][i] = ans[i][j];
      swap(n, m);
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
          ans[i][j] = tmp[i][j];
    }
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        printf("%d%c", ans[i][j], j == m-1 ? '\n' : ' ');
  }


  return 0;
}