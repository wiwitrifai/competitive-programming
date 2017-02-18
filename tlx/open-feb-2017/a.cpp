#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  int n;
  cin >> n >>  s;
  int ans = 0;
  for (int i = 0; i < n; i++)
    if (s[i] > '1')
      ans++;
  int zero = 0, one = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      one = 1;
      break;
    }
    if (s[i] == '0')
      ans++, zero = 1;
  }
  if (!one && !zero) {
    puts("-1");
    return 0;
  }
  if (zero)
    ans = min(ans, n-1);
  printf("%d\n", ans);
  return 0;
}