#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

bool ok[204][204];
char s[204][204];

int main() {
  int k, n = 200-2, m = n+1, kk;
  // scanf("%d", &k);
  srand(time(0));
  k = 1 + (1LL * rand() * rand() % inf);
  kk = k;
  ok[0][0] = 1;
  for (int i = 0; i < n; i+= 4) {
    for (int j = 0; j < m; j++)
      ok[i][j] = 1;
  }
  for (int i = 0; i < n; i++)
    ok[i][m-1] = 1;
  k--;
  int c = m-3;
  for (int i = 4; i < n; i += 4) {
    if (k == 0) break;
    long long cur = 1;
    int to = 0;
    for (int j = 0; j <= c; j++) {
      ok[i-3][j] = 1;
      ok[i-2][j] = 1;
      ok[i-1][j] = 1;
      to = max(to, j);
      long long nx = cur * (i+j+1)/(j+1);
      if (k < nx) break;
      cur = nx;
    }
    k -= cur;
    c = to;
  }
  printf("%d %d\n", n, m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      if (ok[i][j])
        s[i][j] = ((i+j) & 1) ? ')' : '(';
      else
        s[i][j] = ')';
    s[i][m] = 0;
    printf("%s\n", s[i]);
  }
  cerr << k << endl;
  printf("%d\n", kk);
  return 0;
}