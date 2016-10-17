#include <bits/stdc++.h>

using namespace std;

char s[3][1024];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s %s %s", s[0], s[1], s[2]);
    int cnt[3], len[3], n;
    scanf("%d", &n);
    for (int i = 0; i < 3; i++) {
      len[i] = strlen(s[i]);
      cnt[i] = 0;
      for (int j = 0; j < len[i]; j++) {
        cnt[i] += s[i][j] == '1';
      }
    }
    int ans = cnt[0] + n * cnt[1] + cnt[2];
    int d = -1;
    if (len[2] == cnt[2]) {
      d += cnt[2];
      if (len[1] == cnt[1]) {
        d += n * cnt[1];
        for (int i = len[0]-1; i>=0; i--) {
          if (s[0][i] == '1')
            d++;
          else
            break;
        }
      }
      else
        for (int i = len[1]-1; i>= 0; i--) {
          if (s[1][i] == '1')
            d++;
          else
            break;
        }
    }
    else {
      for (int i = len[2] - 1; i >= 0; i--) {
        if (s[2][i] == '1')
          d++;
        else
          break;
      }
    }
    ans -= d;
    printf("%d\n", ans);
  }

  return 0;
}