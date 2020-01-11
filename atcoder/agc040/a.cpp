#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N];
char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s) + 1;
  for (int i = 0; i + 1 < n; ++i) {
    if (s[i] == '<')
      a[i+1] = a[i] + 1;
  }
  for (int i = n-2; i >= 0; --i) {
    if (s[i] == '>')
      a[i] = max(a[i+1] + 1, a[i]);
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i)
    ans += a[i];
  printf("%lld\n", ans);
  return 0;
}
