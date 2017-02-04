#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

char s[N];

int main() {
  long long m;
  scanf("%s %lld", s, &m);
  int n = strlen(s);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans = (ans * 10 + s[i] - '0') % m;
  }
  printf("%lld\n", ans);
  return 0;
}