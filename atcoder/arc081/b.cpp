#include <bits/stdc++.h>

using namespace std;
const int N = 106, mod = 1e9 + 7;
char s[2][N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 2; i++)
    scanf("%s", s[i]);
  long long ans = 1;
  if (s[0][0] == s[1][0])
    ans = 3;
  else
    ans = 6;
  for (int i = 1 + (s[0][0] != s[1][0]); i < n; i++) {
    if (s[0][i] == s[1][i]) {
      if (s[0][i-1] == s[1][i-1])
        ans = (ans * 2) % mod;
    }
    else {
      if (s[0][i-1] == s[1][i-1])
        ans = ans * 2 % mod;
      else
        ans = ans * 3 % mod;
      i++;
    }
  }
  cout << ans << endl;
  return 0;
}
