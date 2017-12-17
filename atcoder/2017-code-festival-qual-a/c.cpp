#include <bits/stdc++.h>

using namespace std;

int n, m, cnt[26];
char s[1000], ans[105][105];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    for (int j = 0; j < m; j++)
      cnt[s[j] - 'a']++;
  }
  int dua = 0, satu = 0;
  if ((n & 1) && (m & 1))
    dua = (n + m - 2)/2, satu = 1;
  else if (n & 1)
    dua = m / 2;
  else if (m & 1)
    dua = n/2;
  for (int i = 0; i < 26; i++) {
    int now = cnt[i];
    now %= 4;
    dua -= now / 2;
    now %= 2;
    satu -= now;
  }
  if (!(satu >= 0 && dua >= 0)) {
    puts("No");
    return 0;
  }
  puts("Yes");
  // for (int i = 0; i < n-1-i; i++) {
  //   for (int j = 0; j < m-1-j; j++) {
  //     for (int k = 0; k < 26; k++)
  //       if (cnt[k] >= 4) {
  //         cnt[k] -= 4;
  //         ans[i][j] = ans[n-1-j][j] = ans[i][m-1-j] = ans[n-1-j][m-1-j] = k + 'a';
  //         break;
  //       }
  //   }
  // }
  // if (n & 1) {
  //   for (int j = 0; j < m-1-j; j++) {
  //     for (int k = 0; k < 26; k++) if (cnt[k] >= 2) {
  //       ans[n/2][j] = ans[n/2][m-1-j] = k + 'a';
  //       cnt[k] -= 2;
  //       break;
  //     }
  //   }
  // }

  // if (m & 1) {
  //   for (int i = 0; i < n-1-i; i++) {
  //     for (int k = 0; k < 26; k++) if (cnt[k] >= 2) {
  //       ans[i][m/2] = ans[n-1-i][m/2] = k + 'a';
  //       cnt[k] -= 2;
  //       break;
  //     }
  //   }
  // }
  // if ((n & 1) && (m&1)) {
  //   for (int k = 0; k < 26; k++) if (cnt[k]) {
  //     ans[n/2][m/2] = 'a' + k;
  //     break;
  //   }
  // }
  // for (int i = 0; i < n; i++) {
  //   ans[i][m] = 0;
  //   printf("%s\n", ans[i]);
  // }
  return 0;
}