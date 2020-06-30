#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N], t[N];

int main() {
  int n;
  scanf("%d %s %s", &n, s, t);
  int cnt[2];
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; ++i) {
    if (s[i] == t[i]) continue;
    ++cnt[s[i]-'0'];
  }
  if (cnt[0] != cnt[1]) {
    puts("-1");
    return 0;
  }
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; ++i) {
    if (s[i] == t[i]) continue;
    int c = s[i] - '0', o = c^1;
    if (cnt[o] == 0) {
      ++cnt[c];
    } else {
      --cnt[o];
      ++cnt[c];
    }
  }
  printf("%d\n", cnt[0] + cnt[1]);
  return 0;
}
