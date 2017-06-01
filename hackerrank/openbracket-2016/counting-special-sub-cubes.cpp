#include <bits/stdc++.h>

using namespace std;

const int N = 53;

int a[N][N][N];


int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
          scanf("%d", a[i][j]+k);
    for (int len = 1; len <= n; len++) {
      int m = n - len + 1;
      int ans = 0;
      for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
          for (int k = 0; k < m; k++)
            if (a[i][j][k] == len)
              ans++;
      printf("%d ", ans);
      m--;
      for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
          for (int k = 0; k < m; k++)
            for (int z = 0; z < 8; z++) {
              int now = a[i+((z >> 2) & 1)][j + ((z >> 1) & 1)][k + (z & 1)];
              if (a[i][j][k] < now)
                a[i][j][k] = now;
            }
    }
    printf("\n");
  }
  return 0;
}