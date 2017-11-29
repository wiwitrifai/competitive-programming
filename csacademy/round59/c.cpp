#include <bits/stdc++.h>

using namespace std;

const int N = 3030;

char s[N][N];
char ans[N];
bool ok[N][N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    if (i == 0)
      ans[0] = s[0][0], ok[0][0] = 1;
    else {
      char best = 'z'+1;
      for (int j = 0; j <= i; j++) {
        bool cek = 0;
        if (j)
          cek |= ok[i-1][j-1];
        cek |= ok[i-1][j];
        if (cek)
          best = min(best, s[i][j]);
      }
      ans[i] = best;
      for (int j = 0; j <= i; j++) {
        bool cek = 0;
        if (j)
          cek |= ok[i-1][j-1];
        cek |= ok[i-1][j];
        if (cek && s[i][j] == best)
          ok[i][j] = 1;
      }
    }
  }
  ans[n] = 0;
  printf("%s\n", ans);
  return 0;
}