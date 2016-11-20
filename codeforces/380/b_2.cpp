#include <bits/stdc++.h>

using namespace std;

int a[1024][1024];
int n, m;

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", a[i]+j);
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 0)
        ans += !!cnt;
      else
        cnt++;
    }
  }
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < m; j++) {
      if (a[i][m-1-j] == 0)
        ans += !!cnt;
      else
        cnt++;
    }
  }
  for (int i = 0; i < m; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (a[j][i] == 0)
        ans += !!cnt;
      else
        cnt++;
    }
  }
  for (int i = 0; i < m; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (a[n-1-j][i] == 0)
        ans += !!cnt;
      else
        cnt++;
    }
  }
  printf("%d\n", ans);
  return 0;
}