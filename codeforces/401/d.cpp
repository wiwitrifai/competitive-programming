#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
string s[N];
int n;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> s[i];
  for (int i = n-2; i >= 0; i--) {
    int j = 1;
    int sz = min(s[i].size(), s[i+1].size());
    while (j < sz && s[i][j] == s[i+1][j]) j++;
    if (j == sz) {
      if (s[i].size() > s[i+1].size()) {
        s[i] = s[i+1];
      }
    }
    else if (s[i][j] > s[i+1][j]) {
      s[i] = s[i].substr(0, j);
    }
  } 
  for (int i = 0; i < n; i++)
    cout << s[i] << "\n";
  return 0;
}