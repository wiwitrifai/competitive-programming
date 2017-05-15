#include <bits/stdc++.h>

using namespace std;

string s;
map< string, string > mp;
set< string > bracket_begin;
string brackets[] = {"{", "}", "(", ")", "[", "]"};

int main() {
  for (int i = 0; i < 6; i += 2)
    mp[brackets[i+1]] = brackets[i], bracket_begin.insert(brackets[i]);
  stack< string > stak;
  while (cin >> s) {
    if (bracket_begin.count(s))
      stak.push(s);
    else if (mp.count(s)) {
      if (stak.empty() || stak.top() != mp[s]) {
        puts("Error");
        return 0;
      }
      stak.pop();
    }
  }
  if (stak.empty())
    puts("Compiled");
  else
    puts("Error");
  return 0;
}