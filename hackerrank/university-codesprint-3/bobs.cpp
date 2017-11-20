#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int g[N][N];
char s[N][N];

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%s", s[i]);
    }
    int cur = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        g[i][j] = 0;
        if (s[i][j] == 'X') continue;
        set< int> st;
        if (i && s[i-1][j] != 'X')
          st.insert(g[i-1][j]);
        if (j && s[i][j-1] != 'X')
          st.insert(g[i][j-1]);
        if (i && j && s[i-1][j-1] != 'X')
          st.insert(g[i-1][j-1]);
        for (int x : st)
          g[i][j] += g[i][j] == x;
        if (s[i][j] == 'K')
          cur ^= g[i][j];
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (s[i][j] != 'K') continue;
        int now = cur ^ g[i][j];
        if (i && s[i-1][j] != 'X')
          ans += (now ^ g[i-1][j]) == 0;
        if (j && s[i][j-1] != 'X')
          ans += (now ^ g[i][j-1]) == 0;
        if (i && j && s[i-1][j-1] != 'X')
          ans += (now ^ g[i-1][j-1]) == 0;
      }
    }
    if (ans == 0)
      printf("LOSE\n");
    else
      printf("WIN %d\n", ans);
  }
  return 0;
}