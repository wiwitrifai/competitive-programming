#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];

void solve() {
  scanf("%s", s);
  int n = strlen(s);
  int last[3];
  for (int i = 0; i < 3; ++i)
    last[i] = -1;
  int ans = n+1;
  for (int i = 0; i < n; ++i) {
    int now = s[i] - '1';
    last[now] = i;
    int lef = min(last[0], min(last[1], last[2]));
    if (lef == -1) continue;
    ans = min(ans, i - lef + 1);
  }
  if (ans > n)
    ans = 0;
  printf("%d\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
