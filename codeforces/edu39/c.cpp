#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  char last = 'a';
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] <= last) {
      s[i] = last;
      ++last;
    }
    if (last > 'z') break;
  }
  if (last > 'z') {
    cout << s << endl;
  }
  else
    cout << -1 << endl;
  return 0;
}