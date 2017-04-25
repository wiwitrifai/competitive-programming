#include <bits/stdc++.h>

using namespace std;

const int N = 101;

char s[N][N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%s", s[i]);
  int len = strlen(s[0]);
  for (int i = 1; i < n; i++) {
    if (strlen(s[i]) != len) {
      puts("-1");
      return 0;
    }
  }
  int ans = N * N;
  for (int off = 0; off < len; off++) {
    int tot = off;
    for (int i = 1; i < n; i++) {
      int to = -1;
      for (int j = 0; j < len; j++) {
        bool cek = 1;
        for (int k = 0; k < len; k++) {
          if (s[0][(off + k) % len] != s[i][(j+k) % len])
            cek = 0;
        }
        if (cek) {
          to = j;
          break;
        }
      }
      if (to == -1) {
        puts("-1");
        return 0;
      }
      tot += to;
    }
    ans = min(ans, tot);
  }
  printf("%d\n", ans);
  return 0;
}