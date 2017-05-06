#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, mod = 1e9 + 7;

char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  long long b = 0, ans = 0;
  for (int i = n-1; i >= 0; i--) {
    if (s[i] == 'b') b++;
    else {
      ans = (ans + b) % mod;
      b = (b + b) % mod;
    }
  }
  cout << ans << endl;
  return 0;
}