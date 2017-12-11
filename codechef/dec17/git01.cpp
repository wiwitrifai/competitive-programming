#include <bits/stdc++.h>

using namespace std;

const int N = 111;

char s[N][N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
      scanf("%s", s[i]);
    int ans = 0, other = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if ((i + j) & 1) {
          if (s[i][j] == 'R')
            ans += 5;
          else
            other += 3;
        }
        else {
          if (s[i][j] == 'R')
            other += 5;
          else
            ans += 3;
        }
      }
    }
    printf("%d\n", min(ans, other));
  }
  return 0;
}
