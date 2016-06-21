#include <bits/stdc++.h>

using namespace std;

char s[300];
char m[20][20], c[20][20];
int cnt[20][20];
char ans[10000];
void rotate(char x[20][20], int n) {
  char tmp[20][20];
  memcpy(tmp, x, sizeof tmp);
  for(int i = 0; i<n; i++) {
    for(int j = 0; j<n; j++)
      x[j][n-1-i] = tmp[i][j];
  }
}
int main() {
  freopen("sieve.in", "r", stdin);
  freopen("sieve.out", "w", stdout);
  int n;
  scanf("%s", s);
  scanf("%d", &n);
  int sz = strlen(s), id = 0;
  for(int i = 0; i<n; i++) {
    for(int j = 0; j<n; j++) {
      m[i][j] = id < sz ? s[id++] : '*';
    }
  }
  for(int i = 0; i<n; i++)
    scanf("%s", c[i]);
  int x = 0;
  bool ok = true;
  for(int t = 0; t < 4 && ok; t++) {
    for(int i = 0; i<n && ok; i++)
      for(int j = 0; j<n && ok; j++)
        if(c[i][j] == '+') {
          cnt[i][j]++;
          if(cnt[i][j] > 1)
            ok = false;
          ans[x++] = m[i][j];
        }
    rotate(c, n);
  }
  for(int i = 0; i<n; i++)
    for(int j = 0; j<n; j++)
      if(cnt[i][j] != 1)
        ok = false;
  ans[x] = '\0';
  if(ok)
    printf("%s\n", ans);
  else
    puts("No solution.");
  return 0;
}