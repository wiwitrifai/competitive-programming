#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  if (s == "zyxwvutsrqponmlkjihgfedcba") {
    puts("-1");
  }
  else if (s.size() == 26) {
    int i = 25;
    while (i > 0 && s[i] < s[i-1]) --i;
    --i;
    int j = 25;
    while (s[j] < s[i]) --j;;
    swap(s[i], s[j]);
    s.resize(i+1);
    cout << s << endl;
  }
  else {
    string now = s;
    sort(now.begin(), now.end());
    char c = 'a';
    for (char x : now)
      c += c == x;
    s.push_back(c);
    cout << s << endl;
  }
  return 0;
}