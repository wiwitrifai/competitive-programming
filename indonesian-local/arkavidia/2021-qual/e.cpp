#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  string ans = "";
  reverse(s.begin(), s.end());
  for (char c : s) {
    if (('0' <= c && c <= '9') || ('a' <= c && c <= 'z'))
      ans.push_back(c);
    else if ('A' <= c && c <= 'Z')
      ans.push_back(c - 'A' + 'a');
    else {
      puts("Emor tidak beruntung :(");
      return 0;
    }
  }
  cout << ans << endl;
  return 0;
}
