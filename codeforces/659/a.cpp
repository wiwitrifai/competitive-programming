#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N], t[N];

int to[22][22];

void solve() {
  int n;
  scanf("%d", &n);
  scanf("%s %s", s, t);
  memset(to, 0, sizeof to);
  for (int i = 0; i < n; ++i) {
    if (t[i] < s[i]) {
      puts("-1");
      return;
    }
    to[s[i]-'a'][t[i]-'a'] = 1;
  }
  int ans = 0;
  for (int i = 0; i < 21; ++i) {
    int nxt = -1;
    for (int j = i+1; j < 21; ++j) {
      if (to[i][j]) {
        nxt = j;
        break;
      }
    }
    if (nxt == -1) continue;
    ++ans;
    for (int j = 0; j < 21; ++j) {
      to[nxt][j] |= to[i][j];
    }
  }
  printf("%d\n", ans);
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
