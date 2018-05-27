#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

char s[N];
int cnt[N];
int main() {
  int n;
  scanf("%d %s", &n, s);
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    cnt[i] = cur;
    cur += s[i] == 'W';
  }
  int ans = cur;
  cur = 0;
  for (int i = n-1; i >= 0; --i) {
    ans = min(ans, cnt[i] + cur);
    cur += s[i] == 'E';
  }
  ans = min(ans, cur);
  printf("%d\n", ans);
  return 0;
}