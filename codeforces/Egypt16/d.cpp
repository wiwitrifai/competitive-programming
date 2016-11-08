#include <bits/stdc++.h>

using namespace std;

int C[50][50];

int main() {
  freopen("popcorn.in", "r", stdin);
  for (int i = 0; i < 50; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++)
      C[i][j] = C[i-1][j-1] + C[i-1][j];
  } 
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d\n", C[n][m]);
  }

  return 0;
}