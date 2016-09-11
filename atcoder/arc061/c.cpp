#include <bits/stdc++.h>

using namespace std;

const int N = 12;

char s[N];
long long ans = 0;

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int len = 1<<(n-1);
  ans = 0;
  for (int i = 0; i < len; i++) {
    long long now = 0;
    for (int j = 0; j < n; j++) {
      now = now * 10 + s[j] - '0';
      if (i & (1<<j)) {
        ans += now;
        now = 0;
      }
    }
    ans += now;
  }
  printf("%lld\n", ans);

  return 0;
}