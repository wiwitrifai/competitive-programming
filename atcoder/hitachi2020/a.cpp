#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  if (s.size() & 1) {
    puts("No");
    return 0;
  }
  bool ok = 1;
  for (int i = 0; i < (int)s.size(); i += 2) {
    ok &= s[i] == 'h' && s[i+1] == 'i';
  }
  puts(ok ? "Yes" : "No");
  return 0;
}
