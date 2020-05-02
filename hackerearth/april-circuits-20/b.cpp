#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d %s", &n, s);
    int cnt[2];
    cnt[0] = cnt[1] = 0;
    for (int i = 0; i < n; ++i) {
      ++cnt[s[i] - 'A'];
    }
    int cur[2];
    cur[0] = cur[1] = 0;
    int ans = min(cnt[0], cnt[1]);
    for (int i = 0; i < n; ++i) {
      --cnt[s[i] - 'A'];
      ++cur[s[i] - 'A'];
      ans = min(ans, cur[1] + cnt[0]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
