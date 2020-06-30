#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];

void solve() {
  scanf("%s", s);
  int n = strlen(s);
  int mini = 0, cur = 0;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    cur += s[i] == '+' ? +1 : -1;
    if (cur < mini) {
      ans += 1LL * (i + 1) * (mini - cur);
      mini = cur;
    }
  }
  ans += n;
  printf("%lld\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
