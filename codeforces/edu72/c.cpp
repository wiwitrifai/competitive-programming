#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

char s[N];
int cnt[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    int cur = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      cnt[i] = cur;
      int til = min(21, i+1);
      int now = 0;
      for (int j = 0; j < til; ++j) {
        if (s[i-j] == '1') {
          now += 1 << j;
          if (cnt[i-j] + (j+1) >= now && now >= (j+1)) {
            ++ans;
          }
        }
      }
      if (s[i] == '1')
        cur = 0;
      else
        ++cur;
    }
    printf("%d\n", ans);
  }
  return 0;
}
