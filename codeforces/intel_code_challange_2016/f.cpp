#include <bits/stdc++.h>

using namespace std;

string s[] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

map< string, int> mp;

int main() {
  for (int i = 0; i < 7; i++)
    mp[s[i]] = i;
  string a, b;
  cin >> a >> b;
  int diff = (mp[b] + 7 - mp[a]) % 7;
  puts ((diff == 0 || diff == 3 || diff == 4) ? "YES" : "NO");

  return 0;
}