#include <bits/stdc++.h>

using namespace std;

const int N = 1111;
char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    int cnt = -1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (i >= 1 && s[i] == 'h' && s[i-1] == 'l')
        cnt = 0;
      else if (s[i] == '?')
        ans = max(ans, cnt), cnt = -1;
      else if (s[i] == 'o' && cnt >= 0)
        cnt++;
      else
        cnt = -1;
    }
    printf("%d\n", ans);
  }
  return 0;
}