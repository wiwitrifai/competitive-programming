#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int b, w;
  long long ans = 0;
  b = w = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'B')
      ++b;
    else
      ans += b;
  }
  printf("%lld\n", ans);
  return 0;
}