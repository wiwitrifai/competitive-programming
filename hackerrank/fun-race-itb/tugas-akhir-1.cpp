#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  long long ans = 1;
  for (int i = 1; i < n; i++) {
    if (s[i] == 'A' && s[i-1] == 'T') {
      if (i >= 3 && s[i-2] == 'O' && s[i-3] == 'D')
        ans = (ans * 4) % mod;
      else if  (i >= 2 && s[i-2] == 'G')
        ans = (ans * 3) % mod;
      else
        ans = (ans * 2) % mod;
      i++;
    }
  }
  printf("%lld\n", ans);
  return 0;
}