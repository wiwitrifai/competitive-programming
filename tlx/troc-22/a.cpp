#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  bool ans = false;
  for (char c : s) {
    ans |= c == '0';
  }
  puts(ans ? "YES" : "NO");
  return 0;
}
