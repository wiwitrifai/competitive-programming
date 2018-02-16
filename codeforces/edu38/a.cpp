#include <bits/stdc++.h>

using namespace std;

string v = "aiueoy";

bool isVowel(char c) {
  for (int i = 0; i < v.size(); ++i)
    if ( c== v[i])
      return true;
  return false;
}

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  char c = s[0];
  cout << s[0];
  for (int i = 1; i < s.size(); ++i) {
    if (isVowel(c) && isVowel(s[i]))
      continue;
    c = s[i];
    cout << c;
  }
  cout << endl;
  return 0;
}