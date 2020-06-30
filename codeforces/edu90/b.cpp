#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

void solve() {
  scanf("%s", s);
  int n = strlen(s), one = 0;
  for (int i = 0; i < n; ++i)
    one += s[i] == '1';
  int cnt = min(one, n - one);
  puts(cnt & 1 ? "DA" : "NET");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
