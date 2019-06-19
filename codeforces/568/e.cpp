#include <bits/stdc++.h>

using namespace std;

const int N = 2048;

char s[N][N], board[N][N];
int ra[30], rb[30];
int ca[30], cb[30];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
      scanf("%s", s[i]);
    fill(ra, ra+30, n);
    fill(rb, rb+30, -1);
    fill(ca, ca+30, m);
    fill(cb, cb+30, -1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == '.') continue;
        int c = s[i][j] - 'a';
        ra[c] = min(ra[c], i);
        rb[c] = max(rb[c], i);
        ca[c] = min(ca[c], j);
        cb[c] = max(cb[c], j);
      }
    }
    bool ok = 1;
    int k = 0;
    for (int i = 0; i < 26; ++i) {
      if (rb[i] == -1) continue;
      k = i+1;
    }
    for (int i = 0; i < k; ++i) {
      if (rb[i] == -1) {
        ra[i] = rb[i] = ra[k-1];
        ca[i] = cb[i] = ca[k-1];
        continue;
      }
      if (ra[i] != rb[i] && ca[i] != cb[i]) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      for (int i = 0; i < n; ++i)
        fill(board[i], board[i]+m, '.');
      for (int c = 0; c < k; ++c) {
        char now = 'a' + c;
        for (int i = ra[c]; i <= rb[c]; ++i) {
          for (int j = ca[c]; j <= cb[c]; ++j)
            board[i][j] = now;
        }
      }
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (s[i][j] != board[i][j]) {
            ok = 0;
            break;
          }
        }
      }
    }
    if (ok) {
      puts("YES");
      printf("%d\n", k);
      for (int i = 0; i < k; ++i) {
        printf("%d %d %d %d\n", ra[i]+1, ca[i]+1, rb[i]+1, cb[i]+1);
      }
    }
    else
      puts("NO");
  }
  return 0;
}
