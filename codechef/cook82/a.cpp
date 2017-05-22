#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    map< string, int > mp;
    for (int i = 0; i < 4; i++) {
      string s;
      int g;
      cin >> s >> g;
      mp[s] = g;
    }
    if (mp["Barcelona"] > mp["Eibar"] && mp["RealMadrid"] < mp["Malaga"])
      puts("Barcelona");
    else
      puts("RealMadrid");
  }
  return 0;
}