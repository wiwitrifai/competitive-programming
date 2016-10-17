#include <bits/stdc++.h>

using namespace std;

const int N = 22;
int x[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  bool ans = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      scanf("%d", x[i]+j);
  } 
  for (int a = 0; a < m && !ans; a++) {
    for (int b = a+1; b < m && !ans; b++) {
      bool ok = true;
      for (int i = 0; i < n && ok; i++) {
        int cnt = 0, d[5]; 
        for (int j = 0; j < m && ok; j++) {
          if (j == a || j == b)
            continue;
          if (x[i][j] != j+1) {
            d[cnt++] = j+1;
            if (cnt > 2)
              ok = false;
          }
        }
        if (!ok)
          break;
        if (cnt == 2 && x[i][d[0]-1] == d[1])
          ok = true;
        else if(cnt < 2)
          ok = true;
        else
          ok = false;
      }
      if (ok)
        ans = true;
    }
  }
  puts(ans ? "YES" : "NO");
  return 0;
}