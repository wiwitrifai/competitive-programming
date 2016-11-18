#include <bits/stdc++.h>

using namespace std;

const int N = 1100;

char s[N][N];

int main() {
  int n;
  scanf("%d", &n);
  int tc = 0;
  while (n) {
    for (int i = n-1; i >= 0; i--) {
      scanf("%s", s[i]);
      for (int j = 0; j <= i; j++)
        s[i][j] -= '0';
    }
    for (int i = 0; i+1 < n; i++) {
      for (int j = 0; j <= i; j++) {
        if (s[i][j]) {
          s[i][j] ^= 1;
          s[i+1][j] ^= 1;
          s[i+1][j+1] ^= 1;
        }
      }
    }
    for (int i = 0; i + 2 < n; i++)
      if (s[n-1][i]) {
        s[n-1][i] ^= 1;
        s[n-1][i+1] ^= 1;
        s[n-1][i+2] ^= 1;
      }
    bool ok = 1;
    for (int i = 0; i < n; i++)
      ok &= (s[n-1][i] == 0);
    if (ok)
      printf("Triangle %d can be filled.\n", ++tc);
    else
      printf("Triangle %d cannot be filled.\n", ++tc);
    scanf("%d", &n);
  }
  return 0;
}