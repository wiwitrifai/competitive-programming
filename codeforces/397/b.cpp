#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  bool ans = 1;
  char now = 'a';
  int n = s.size();
  for (int  i = 0;i < n; i++) {
    if (s[i] > now) {
      ans = 0;
      break;
    }
    now = max((int)now, s[i]+1);
  }
  puts(ans ? "YES" : "NO");
  return 0;
}