#include <bits/stdc++.h>

using namespace std;

map< string, string > mp;

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  while(n--) {
    string norm, temp, minion;
    cin >> norm >> temp >> minion;
    mp[norm] = minion;
  }
  int t;
  cin >> t;
  while(t--) {
    cin >> n;
    while(n--) {
      string norm;
      cin >> norm;
      cout << mp[norm];
      if(n)
        cout << " ";
      else
        cout << "\n";
    }
  }
  return 0;
}