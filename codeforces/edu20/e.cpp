#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

char v[N][N + N]; 
char s[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  scanf("%s", s);
  v[0][N] = '#';
  for (int i = 0; i < n; i++) {
    for (int j = -k+1; j < k; j++) {
      if (!v[i][j+N]) continue;
      if (s[i] == 'W')
        v[i+1][j+N+1] = 'W';
      else if (s[i] == 'L')
        v[i+1][j+N-1] = 'L';
      else if (s[i] == 'D')
        v[i+1][j+N] = 'D';
      else {
        v[i+1][j+N+1] = 'W';
        v[i+1][j+N] = 'D';
        v[i+1][j+N-1] = 'L';
      }
    } 
  }
  if (!v[n][N+k] && !v[n][N-k])
    puts("NO");
  else {
    int now = v[n][N+k] ? N+k : N-k;
    for (int i = n; i > 0; i--) {
      char c = s[i-1] = v[i][now];
      if (c == 'W')
        now--;
      else if (c == 'L')
        now++;
    }
    s[n] = 0;
    printf("%s\n", s);
  }
  return 0;
}