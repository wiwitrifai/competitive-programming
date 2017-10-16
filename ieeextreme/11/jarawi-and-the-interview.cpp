#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];
int last[N][26];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  for (int i = 0; i < 26; i++) {
    last[0][i] = -1;
  }
  for (int i = 0; i < n; i++) {
    if (i)
      for (int j = 0; j < 26; j++) {
        last[i][j] = last[i-1][j];
      }
    last[i][s[i]-'a'] = i;
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int now = n-1;
    scanf("%s", s);
    int m = strlen(s), ans = 0;
    for(int i = m-1; i >= 0; --i) {
      if (now < 0) break;
      now = last[now][s[i]-'a'];
      if (now < 0) break;
      ans++;
      now--;
    }
    printf("%d\n", ans);
  }
  return 0;
}