#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

int main() {
  int n;
  scanf("%d %s", &n, s);
  int cnt = 1;
  char last = s[0];
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    if (last == s[i]) {
      ++cnt;
    } else {
      ans += cnt / 2;
      cnt = 1;
      last = s[i];
    }
  }
  ans += cnt / 2;
  printf("%d\n", ans);
  return 0;
}
