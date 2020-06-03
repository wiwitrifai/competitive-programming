#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

string s[N];
int n;
map< string, int > mp;
int main() {
  cin >> n;
  for(int i = 0; i<n; i++) {
    cin >> s[i];
    int add = ('a' - s[i][0]) % 26;
    if(add < 0)
      add += 26;
    for(int j = 0; j<s[i].size(); j++) {
      s[i][j] = ((s[i][j] - 'a' + add) % 26) + 'a';
    }
    // cerr << s[i] << endl;
    mp[s[i]]++;
  }
  for(int i = 0; i<n; i++) {
    printf("%d\n", (mp[s[i]] > 1) ? 1 : 0);
  }
  
  return 0;
}