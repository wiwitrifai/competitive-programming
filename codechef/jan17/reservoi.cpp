#include <bits/stdc++.h>

using namespace std;

const int N = 5050;

char s[N][N];
int n, m;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
      scanf("%s", s[i]+1);
      s[i][0] = s[i][m+1] = 'A';
    }
    for (int i = 0; i <= m+1; i++)
      s[n+1][i] = 'B';
    bool ans = true;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (s[i][j] == 'W') {
          if (s[i][j-1] == 'A' || s[i][j+1] == 'A' || s[i+1][j] == 'A') {
            ans = false;
            break;
          }
        }
        else if (s[i][j]  == 'B') {
          if (s[i+1][j] != 'B') {
            ans = false;
            break;
          }
        }
      }
    }
    puts(ans ? "yes" : "no");
  }
  return 0;
}