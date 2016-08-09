#include <bits/stdc++.h>

using namespace std;

char s[1005];

char mir[256];

int main() {
  mir['A'] = 'A';
  mir['b'] = 'd';
  mir['d'] = 'b';
  mir['H'] = 'H';
  mir['I'] = 'I';
  // mir['i'] = 'i';
  // mir['l'] = 'l';
  mir['M'] = 'M';
  // mir['m'] = 'm';
  // mir['n'] = 'n';
  mir['O'] = 'O';
  mir['o'] = 'o';
  mir['p'] = 'q';
  mir['q'] = 'p';
  mir['T'] = 'T';
  mir['U'] = 'U';
  // mir['u'] = 'u';
  mir['V'] = 'V';
  mir['v'] = 'v';
  mir['W'] = 'W';
  mir['w'] = 'w';
  mir['X'] = 'X';
  mir['x'] = 'x';
  mir['Y'] = 'Y';
  scanf("%s", s);
  int n = strlen(s);
  bool ok = true;
  for(int i = 0; i<n; i++) {
    ok &= (mir[s[i]] == s[n-i-1]);
  }
  puts(ok ? "TAK" : "NIE");
  return 0;
}